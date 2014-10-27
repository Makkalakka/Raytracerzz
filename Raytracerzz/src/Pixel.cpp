#include "../include/Pixel.h"
#include "../include/Ray.h"
#include "../include/Scene.h"
#include "../include/SceneObject.h"
#include <iostream>


Pixel::Pixel(glm::vec3 c, glm::vec3 right, glm::vec3 down, glm::vec3 cPos, int rpp, Scene &w)
{
    corner = c;
    rightAxis = right;
    downAxis = down;
    cameraPos = cPos;
    raysPerPixel = rpp;
    world = &w;
    pixColor = glm::vec3(0,0,0);
}

Pixel::~Pixel()
{
    //dtor
}

glm::vec3 Pixel::getColor()
{
    return pixColor;
}

void Pixel::shootRays()
{
    glm::vec3 rayDir = glm::normalize(corner - cameraPos);

    //for(raysPerPixel)

    Ray pixelRay = Ray(cameraPos, rayDir, 1, glm::vec3(0,0,0));

    //check intersection, get color from object
    int nrOfObj = world->Objects->size();



    for(int i=0; i<nrOfObj; i++)
    {
        if(world->Objects->at(i)->intersection(pixelRay))
        {
            glm::vec3 theIntersection = world->Objects->at(i)->getLatestIntersection();
            std::cout << "found intersection at: " << theIntersection.x << ", " << theIntersection.y << ", " << theIntersection.z << std::endl;

            pixColor = world->Objects->at(i)->getColor();
        }
        else
            pixColor = glm::vec3(0,0,0);
    }



}
