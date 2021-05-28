#ifndef ShaderManager_H
#define ShaderManager_H
#include "../Shaders/shader.h"
#include <map>
class ShaderManager {
private:
    std::map<std::string, Shader> shaders;
public:
    ShaderManager();
    // Adds given shader to pool
    void AddShader(std::string name,Shader shader);
    void RemoveShader(std::string name);
    std::string* ListShaders();
    Shader GetDefault();
    Shader GetShader(std::string name);

};
#endif