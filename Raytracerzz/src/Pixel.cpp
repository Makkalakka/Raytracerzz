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

    Ray pixelRay = Ray(cameraPos, rayDir, 1.0, world);

    pixColor = pixelRay.calculateColor();


}
