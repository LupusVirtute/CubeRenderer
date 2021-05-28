#ifndef EBO_H
#define EBO_H
#include <glad/glad.h>
#include <memory>
#include <vector>
class EBO {
private:
    unsigned int EBO_id;
    std::shared_ptr<std::vector<unsigned int>> indices;
    unsigned int indice_array_size = 0;
public:
    EBO(std::shared_ptr<std::vector<unsigned int>> indices);
    void BindBuffer();
    void DrawUsingEBO();
};
#endif