#include "../include/Ray.h"

Ray::Ray(glm::vec3 theStartingPoint, glm::vec3 theDirection, double theImportance, glm::vec3 theColor)
{
    startingPoint = theStartingPoint;
    direction = theDirection;
    importance = theImportance;
    color = theColor;
}

Ray::~Ray()
{
    //dtor
}


