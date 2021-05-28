#include "EBO.h"
#include <iostream>
EBO::EBO(std::shared_ptr<std::vector<unsigned int>> indices){
    this->indices = indices;
    glGenBuffers(1,&this->EBO_id);
    this->indice_array_size = indices.get()->size();

    unsigned int temp_array[indice_array_size] = {0,0,0};

    int i=0;
    for (auto vertex : *indices.get())
    {
        temp_array[i] = vertex;
        i++;
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO_id);
    std::cout << "Indice size : " << sizeof(temp_array)/indice_array_size;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(temp_array),temp_array,GL_STATIC_DRAW);

}
void EBO::BindBuffer(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->EBO_id);
}
void EBO::DrawUsingEBO(){
    BindBuffer();
    glDrawElements(GL_TRIANGLES, this->indice_array_size,GL_UNSIGNED_INT, 0);    
}
