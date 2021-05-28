#include "VAO.h"

#include <iostream>
VAO::VAO(){
    unsigned int tempID;
    glGenVertexArrays(1,&tempID);
    this->VAO_id = tempID;
}
void VAO::BindArray(){
    glBindVertexArray(VAO_id);
}
void VAO::UnBind(){
    glBindVertexArray(0);
}
