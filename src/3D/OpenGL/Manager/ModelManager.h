#ifndef ModelManager_H
#define ModelManager_H

#include "../Objects/Model.h"
#include "../../Units/Vertex.h"
#include <vector>
#include <memory>

class ModelManager {
private:
    std::vector<Model> models;
public:
    ModelManager();
    void Render();
    // TODO: Add more functionality
};
#endif