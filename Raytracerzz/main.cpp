#include <iostream>
#include "lib/glm/glm/glm.hpp"

//classes
#include "include/Camera.h"
#include "include/Scene.h"
#include "include/Rectangle.h"
#include "include/Cube.h"
#include "include/Sphere.h"
#include "include/Light.h"

using namespace std;

int main()
{
    Scene world;

    float d = 15, h = 3, w = 4; //d = distance from camera, height, width

    Sphere *sphere1 = new Sphere(glm::vec3(0, 6.5, -1.2), 0.5, 0.3, 1.0, glm::vec3(0.2,0.4,0.6), false);
    Sphere *sphere2 = new Sphere(glm::vec3(-1.5, 8.5, -1.2), 0.6, 1.0, 1.0, glm::vec3(0.6,0.4,0.6), false);

    Rectangle *rec = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, d, -h), glm::vec3(w, d, -h), glm::vec3(w, d, h), glm::vec3(0, -1, 0), glm::vec3(1,0,0)); //back
    Rectangle *rec2 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, (d-2*w), h), glm::vec3(-w, (d-2*w), -h), glm::vec3(-w, d, -h), glm::vec3(1, 0, 0), glm::vec3(0,0,1)); //left
    Rectangle *rec3 = new Rectangle(glm::vec3(-w, d, -h), glm::vec3(-w, (d-2*w), -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, d, -h), glm::vec3(0, 0, 1), glm::vec3(0,1,0)); //floor
    Rectangle *rec4 = new Rectangle(glm::vec3(w, d, h), glm::vec3(w, d, -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, (d-2*w), h), glm::vec3(-1, 0, 0), glm::vec3(0,0,1)); //right
    Rectangle *rec5 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(w, d, h), glm::vec3(w, (d-2*w), h), glm::vec3(-w, (d-2*w), h), glm::vec3(0, 0, -1), glm::vec3(0,1,0)); //roof

    Cube *theCube = new Cube(glm::vec3(2, 11, -2.7), 1.2, false, 0, glm::vec3(0.8, 0.8, 0));
    theCube->initialize();

    world.addObject(theCube);
    world.addObject(rec);
    world.addObject(rec2);
    world.addObject(rec3);
    world.addObject(rec4);
    world.addObject(rec5);
    world.addObject(sphere1);
    world.addObject(sphere2);

    //Adding lightsources
    Light *li1 = new Light(glm::vec3(0, 5, 0.5), glm::vec3(1, 1, 1), 1);
    Light *li2 = new Light(glm::vec3(1, 9, 1), glm::vec3(1,1,1), 1);
    Sphere *lightsphere = new Sphere(glm::vec3(0, 10, 2), 0.1, 1.0, 1.0, glm::vec3(0,0,1), false);

    world.addLight(li1);
    world.addLight(li2);
    world.addObject(lightsphere);


    cout << "Creating camera..." << endl;

    Camera cam (720, 1280, 2, 1.5);

    cout << "Starting rendering method" << endl;

    cam.renderImage(world);

    delete rec;
    delete rec2;
    delete rec3;
    delete rec4;
    delete rec5;
    delete sphere1;
    delete sphere2;
    delete theCube;
    delete li1;
    delete li2;
    delete lightsphere;
}
