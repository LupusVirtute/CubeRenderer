#ifndef Model_H
#define Model_H
#include "VBO.h"
#include "VAO.h"
#include <memory>
class Model {
private:
    VBO vbo;
public:
    // Model(std::shared_ptr<Vertex[]> vertices);
    Model(std::shared_ptr<std::vector<Vertex>> vertices,size_t array_size,std::shared_ptr<std::vector<unsigned int>> indices);
    void render();
};
#endif