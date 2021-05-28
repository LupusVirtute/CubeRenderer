#include "engine.h"


int main()
{
    Engine engine = Engine(640, 480, "Cube Render");
    if(!engine.Initialize())
    {
        std::cout << std::endl << "Press any key to close program..." << std::endl;
        std::cin.get();
    }
}
