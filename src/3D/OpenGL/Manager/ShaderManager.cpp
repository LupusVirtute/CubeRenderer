#include "ShaderManager.h"

void ShaderManager::AddShader(std::string name, Shader shader){
    this->shaders[name] = shader;
}
Shader ShaderManager::GetShader(std::string name){
    return this->shaders[name];
}
std::string* ShaderManager::ListShaders(){
    int size = this->shaders.size();
    std::string array[size];
    int i=0;
    for(std::map<std::string,Shader>::iterator it = this->shaders.begin(); it != this->shaders.end(); ++it,++i) {
        if (i >= size)
        {
            break;
        }
        
        array[i] = it->first;
    }
    return array;
}
void ShaderManager::RemoveShader(std::string name){
    this->shaders.erase(name);
}
Shader ShaderManager::GetDefault(){
    return this->GetShader("DEFAULT");
}
ShaderManager::ShaderManager(){
    // Loads Default Shaders
    auto shader = Shader();
    shader.setFragmentShader(   "basicFragmentShader.glsl");
    shader.setVertexShader(     "basicVertexShader.glsl");
    shader.compile();
    this->AddShader("DEFAULT",shader);
}