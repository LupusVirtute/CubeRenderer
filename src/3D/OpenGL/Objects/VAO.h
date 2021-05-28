#ifndef VAO_H
#define VAO_H
#include <glad\glad.h>
class VAO {
private:
    unsigned int VAO_id;
public:
    VAO();
    void BindArray();
    void UnBind();
};
#endif