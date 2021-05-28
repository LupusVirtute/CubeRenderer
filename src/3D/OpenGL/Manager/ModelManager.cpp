#include "ModelManager.h"
ModelManager::ModelManager(){
    // Load Default models 
    Vertex vertices[] = {
        Vertex( .5,  .5, 0.0),
        Vertex( .5, -.5, 0.0),
        Vertex(-.5, -.5, 0.0),
        Vertex(-.5,  .5, 0.0),
        // Back
        Vertex( .5,  .5, -1.0),
        Vertex( .5, -.5, -1.0),
        Vertex(-.5, -.5, -1.0),
        Vertex(-.5,  .5, -1.0),
    };
    // Cube indice don't care really how it works
    unsigned int indice_arr[]  = {
            0, 1, 3, 
            1, 2, 3,
            3, 7, 6,
            6, 3, 2,
            5, 6, 7,
            4, 5, 7,
            0, 1, 4,
            5, 4, 1,
            0, 3, 7,
            7, 4, 0,
            1, 2, 5,
            5, 6 , 2
    };

    std::shared_ptr<std::vector<unsigned int>> indices = std::make_shared<std::vector<unsigned int>>();

    size_t size = sizeof(vertices)/sizeof(Vertex);
    std::shared_ptr<std::vector<Vertex>> vertice_vector = std::make_shared<std::vector<Vertex>>();
    
    // That sounds utterly retarded but fuck this i don't have time
    
    for(int i=0,l=sizeof(indice_arr)/sizeof(unsigned int);i<l;i++)
        indices.get()->push_back(indice_arr[i]);
    for(int i=0;i<size;i++)
        vertice_vector.get()->push_back(vertices[i]);
    

    Model model(vertice_vector,size,indices);
    this->models.push_back(model);
}
void ModelManager::Render(){
    for(auto &model : models){
        model.render();
    }
}