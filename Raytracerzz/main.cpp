#include <iostream>

#include "lib/glm/glm/glm.hpp"

//classes
#include "include/Camera.h"
#include "include/Scene.h"
#include "include/Rectangle.h"
#include "include/Cube.h"



using namespace std;

int main()
{
    Scene world;

    //Rectangle *rec = new Rectangle(glm::vec3(-1, 10, 1), glm::vec3(-1, 10, -1), glm::vec3(1, 10, -1), glm::vec3(1, 10, 1), glm::vec3(0, -1, 0), glm::vec3(1,0,0));

    Cube *theCube = new Cube(glm::vec3(1, 5, 0), 2, false, 0, glm::vec3(0.8, 0.8, 0));

    world.addObject(theCube);

    cout << "Creating camera..." << endl;

    Camera cam (512, 512, 5, 1);

    cout << "Starting rendering method" << endl;

    cam.renderImage(world);

    //delete rec;
    delete theCube;
}
