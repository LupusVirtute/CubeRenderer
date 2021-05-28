#include "VBO.h"

// unsigned int* getIndices(std::shared_ptr<Vertex[]> vertices){
//     int size = sizeof(vertices.get())/sizeof(Vertex);
//     unsigned int indices[size*2];
//     for (int i = 0,j=1,l=array_size; j < l; i+=2,j+=2)
//     {
//         indices[i] = i;
//         indices[j] = j;
//     }
// }
#include <iostream>
VBO::VBO(
    std::shared_ptr<std::vector<Vertex>> vertices,
    size_t array_size,
    std::shared_ptr<std::vector<unsigned int>> indices
) : ebo(indices) {
    glGenBuffers(1,&this->VBO_id);
    this->array_size = array_size;
    this->vertice_array = vertices;
    this->vao.BindArray();
    BindBuffer();
    std::cout << vertice_array.get()->size()*sizeof(Vertex);

    Vertex temp_array[vertice_array.get()->size()];
    int i=0;
    for (auto vertex : *vertice_array.get())
    {
        temp_array[i] = vertex;
        i++;
    }
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(temp_array), temp_array, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_id);
    this->vao.UnBind();
}
void VBO::BindBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER,VBO_id);

}
void VBO::BindVAO(){
    this->vao.BindArray();
}
EBO* VBO::GetEBO(){
    return &this->ebo;
}
VAO* VBO::GetVAO(){
    return &this->vao;
}
