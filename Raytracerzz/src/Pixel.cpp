#include "Pixel.h"

Pixel::Pixel(glm::vec3 &c, glm::vec3 &right, glm::vec3 &down, glm::vec3 &cPos, double rpp, Scene &w)
{
    corner = c;
    rightAxis = right;
    downAxis = down;
    cameraPos = cPos;
    raysPerPixel = rpp;
    world = w;
}

Pixel::~Pixel()
{
    //dtor
}

void shootRays()
{
    glm::vec3 rayDir = glm::normalize(corner - cameraPos);

    //for(raysPerPixel)



}
