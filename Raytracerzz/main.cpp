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

    //glm::vec3 position, float radius, float diffIdx, float refractiveIndex, glm::vec3 theColor, bool transparent
    Sphere *sphere1 = new Sphere(glm::vec3(1.2, 12, -2), 1.0, 0.1, 1.5, glm::vec3(1,0,0), true);
    Sphere *sphere2 = new Sphere(glm::vec3(-2.0, 13, -2.2), 0.7, 0, 1.0, glm::vec3(1,0,0.6), false);

    Rectangle *rec = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, d, -h), glm::vec3(w, d, -h), glm::vec3(w, d, h), glm::vec3(0, -1, 0), glm::vec3(0.5,0.5,0.5)); //back
    Rectangle *rec2 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(-w, (d-2*w), h), glm::vec3(-w, (d-2*w), -h), glm::vec3(-w, d, -h), glm::vec3(1, 0, 0), glm::vec3(1,0,0)); //left
    Rectangle *rec3 = new Rectangle(glm::vec3(-w, d, -h), glm::vec3(-w, (d-2*w), -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, d, -h), glm::vec3(0, 0, 1), glm::vec3(0.5,0.5,0.3)); //floor
    Rectangle *rec4 = new Rectangle(glm::vec3(w, d, h), glm::vec3(w, d, -h), glm::vec3(w, (d-2*w), -h), glm::vec3(w, (d-2*w), h), glm::vec3(-1, 0, 0), glm::vec3(0,0,1)); //right
    Rectangle *rec5 = new Rectangle(glm::vec3(-w, d, h), glm::vec3(w, d, h), glm::vec3(w, (d-2*w), h), glm::vec3(-w, (d-2*w), h), glm::vec3(0, 0, -1), glm::vec3(0.2,0.2,0.2)); //roof

    Cube *theCube = new Cube(glm::vec3(2, 13, -3), 1.5, false, 0, glm::vec3(0, 0.8, 0.3));
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
    Light *li2 = new Light(glm::vec3(1, 12, 1), glm::vec3(1,1,1), 1);
   // Sphere *lightsphere = new Sphere(glm::vec3(-1.2, 7, -1), 0.2, 0, 1.3, glm::vec3(0,0,1), true);

    world.addLight(li1);
    world.addLight(li2);
   // world.addObject(lightsphere);


    cout << "Creating camera..." << endl;

    Camera cam (720, 1280, 1, 1.5);

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
    //delete lightsphere;
}
