#include "../include/Pixel.h"
#include "../include/Ray.h"
#include "../include/Scene.h"

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
    //check intersection, get color from object

    pixColor = glm::vec3(1,0,0);

}
