#include "engine.h"

int g_screenWidth=0;
int g_screenHeight=0;
std::shared_ptr<Camera> camera;

Engine::Engine(int a_width, int a_height, const char* a_windowName)
{
    this->screenWidth = a_width;
    this->screenHeight = a_height;
    g_screenHeight =    this->screenHeight;
    g_screenWidth  =    this->screenWidth;
    this->windowName = a_windowName;
}

int Engine::Initialize()
{
    int code = glfwInit();
    if(code == GLFW_FALSE){
        std::cout << "ERROR FATAL";
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    this->window = glfwCreateWindow(this->screenWidth, this->screenHeight, this->windowName, NULL, NULL);

    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();

        std::cin.get();
        return 0;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        
        std::cin.get();
        return 0;
    }


    glViewport(0, 0, this->screenWidth, this->screenHeight);


    glfwSetFramebufferSizeCallback(window, WindowResize);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    this->SetupOpenGlRendering();

    while(!glfwWindowShouldClose(this->window))
    {
        float m_frameTime = (float)glfwGetTime();
        float m_deltaTime = m_frameTime - this->lastFrameTime;
        this->lastFrameTime = m_frameTime;

        glfwPollEvents();
        this->ProcessInput(this->window,m_deltaTime);

        glClearColor(this->clearColor.x, this->clearColor.y, this->clearColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        this->Update(m_deltaTime);
        this->Draw();

        glfwSwapBuffers(this->window);
    }

    glfwTerminate();

    return 1;
}
void Engine::SetWidthHeight(int width,int height){
    if(height > 1)
        this->screenHeight = height;
    if (width > 1)
    {
        this->screenWidth = width;
    }
    
}

void WindowResize(GLFWwindow* a_window, int a_width, int a_height)
{  
    if (a_width > 1)
    {
        g_screenWidth = a_width;
    }
    
    if (a_height > 1)
    {
        g_screenHeight = a_height;
    }
    
    glViewport(0, 0, a_width, a_height);

}
bool switcher = true;
bool rotate = false;
void Engine::ProcessInput(GLFWwindow* a_window,float deltaTime)
{    
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.get()->ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.get()->ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.get()->ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.get()->ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window,GLFW_KEY_F2) == GLFW_PRESS)
    {
        if(switcher)
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        switcher = !switcher;
    }
    if(glfwGetKey(window,GLFW_KEY_F3) == GLFW_PRESS){
        rotate = !rotate;
    }
    if(glfwGetKey(a_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(a_window, true);
}
bool firstMouse = true;
float lastX = g_screenWidth / 2.0f;
float lastY = g_screenHeight / 2.0f;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (!rotate)
    {
        return;
    }
    
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    camera->ProcessMouseMovement(xoffset, yoffset);

}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera->ProcessMouseScroll(yoffset);
}
void Engine::SetupOpenGlRendering()
{
    this->shaderManager = std::make_shared<ShaderManager>(ShaderManager());
    this->modelManager = std::make_shared<ModelManager>(ModelManager());
    camera = std::make_shared<Camera>(Camera());
    
}

void Engine::Update(float a_deltaTime)
{
    SetWidthHeight(g_screenWidth,g_screenHeight);
}

void Engine::Draw()
{

    auto shader = this->shaderManager.get()->GetDefault();
    glm::mat4 projection = 
        glm::perspective(
            glm::radians(camera->Zoom), 
            (float)screenWidth / (float)screenHeight,
            0.1f,
            100.0f
        );
    shader.setMat4("projection", projection);

    // camera/view transformation
    glm::mat4 view = camera->GetViewMatrix();
    shader.setMat4("view", view);
    shader.use();
    modelManager.get()->Render();
}