#include "Model.h"
void Model::render(){
    auto vao = this->vbo.GetVAO();
    vao->BindArray();
    
    auto ebo = this->vbo.GetEBO();
    ebo->DrawUsingEBO();
    vao->UnBind();
}
// Model::Model(std::shared_ptr<Vertex[]> vertices) : vbo(vertices)
// {
// }
Model::Model(std::shared_ptr<std::vector<Vertex>> vertices,size_t array_size,std::shared_ptr<std::vector<unsigned int>> indices) : vbo(vertices,array_size,indices)
{
}
