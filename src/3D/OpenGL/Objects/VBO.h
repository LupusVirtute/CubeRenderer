#ifndef VBO_H
#define VBO_H
#include <glad\glad.h>
#include <GLFW/glfw3.h>
#include "../../Units/Vertex.h"
#include "VAO.h"
#include "EBO.h"
#include <memory>
#include <vector>
class VBO {
private:
    unsigned int VBO_id;
    std::shared_ptr<std::vector<Vertex>> vertice_array;
    size_t array_size;
    VAO vao;
    EBO ebo;
public:
    //VBO(std::shared_ptr<Vertex[]> vertices);
    VBO(std::shared_ptr<std::vector<Vertex>> vertices,size_t array_size,std::shared_ptr<std::vector<unsigned int>> indices);
    VAO* GetVAO();
    EBO* GetEBO();
    void BindVAO();
    void BindBuffer();
};
#endif