#include "Vertex.h"

Vertex::Vertex(float x,float y,float z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Vertex::Vertex() : Vertex(0,0,0){

}
Vertex::Vertex(const Vertex* vertex){
    this->x = vertex->x;
    this->y = vertex->y;
    this->z = vertex->z;
}
float Vertex::getX(){
    return this->x;
}
float Vertex::getY(){
    return this->y;
}
float Vertex::getZ(){
    return this->z;
}
