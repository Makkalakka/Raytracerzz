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

    float d = 15, h = 3, w = 4;

    Rectangle *rec = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, d, -h), glm::vec3(w, d, -h), glm::vec3(w, d, h), glm::vec3(0, -1, 0), glm::vec3(1,0,0)); //back
    Rectangle *rec2 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, (d-2*w), h), glm::vec3(-w, (d-2*w), -h), glm::vec3(-w, d, -h), glm::vec3(1, 0, 0), glm::vec3(0,0,1)); //left
    Rectangle *rec3 = new Rectangle(glm::vec3(-w, d, -h), glm::vec3(-w, (d-2*w), -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, d, -h), glm::vec3(0, 0, 1), glm::vec3(0,1,0)); //floor
    Rectangle *rec4 = new Rectangle(glm::vec3(w, d, h), glm::vec3(w, d, -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, (d-2*w), h), glm::vec3(-1, 0, 0), glm::vec3(0,0,1)); //right
    Rectangle *rec5 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(w, d, h), glm::vec3(w, (d-2*w), h), glm::vec3(-w, (d-2*w), h), glm::vec3(0, 0, -1), glm::vec3(0,1,0)); //roof

    Cube *theCube = new Cube(glm::vec3(-1.5, 4, -1.5), 1, false, 0, glm::vec3(0.8, 0.8, 0));
    theCube->initialize();

    world.addObject(theCube);
    world.addObject(rec);
    world.addObject(rec2);
    world.addObject(rec3);
    world.addObject(rec4);
    world.addObject(rec5);

    cout << "Creating camera..." << endl;

    Camera cam (720, 1280, 5, 1.5);

    cout << "Starting rendering method" << endl;

    cam.renderImage(world);

    //delete rec;
    delete theCube;
}
