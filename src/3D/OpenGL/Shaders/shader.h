#ifndef __SHADER__
#define __SHADER__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

// Creates a new shader program.
class Shader
{
private:
    unsigned int shaderProgram;

    unsigned int vertexShaderID = 0;
    const char* vertexShaderSource;

    unsigned int fragmentShaderID = 0;
    const char* fragmentShaderSource;

public:
    // Sets the vertex shader of this program.
    bool setVertexShader(std::string a_vertexShaderSource);
    bool setFragmentShader(std::string a_fragmentShaderSource);
    int getUniformLocation(std::string a_uniformName);
    int compile();
    void use();
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
    std::string loadShaderSource(std::string a_pathToShaderSourceFile);
    bool shaderCompiled(unsigned int a_id);
};

#endif