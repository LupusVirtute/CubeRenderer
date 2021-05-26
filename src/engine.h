#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <glm/glm.hpp>

#include "3D/OpenGL/Shaders/shader.h"
#include "3D/OpenGL/Manager/ShaderManager.h"
#include "3D/OpenGL/Manager/ModelManager.h"

void WindowResize(GLFWwindow* a_window, int a_width, int a_height);

class Engine
{
public:
    int Initialize();
    float gameSpeed = 0.1f;

private:
    int screenWidth = 800;
    int screenHeight = 600;
    ShaderManager shaderManager;
    ModelManager modelManager;
    const char* windowName = "Default Name";

    GLFWwindow* window;

    float lastFrameTime = 0.0f;
    glm::vec3 clearColor = glm::vec3(0.0f, 0.0f, 0.0f);

public:
    Engine(int a_width, int a_height, const char* a_windowName);

    void Update(float a_deltaTime);
    void Draw();

    void ProcessInput(GLFWwindow* a_window);

private:
    void SetupOpenGlRendering();
};
#endif