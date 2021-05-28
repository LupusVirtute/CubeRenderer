
#ifndef Vertex_H
#define Vertex_H
class Vertex {
private:
    float x,y,z;    
public:
    float getX();
    float getY();
    float getZ();
    Vertex(float x,float y,float z);
    Vertex(const Vertex*);
    Vertex();
};
#endif