#include "Rectangle.h"

Rectangle::Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4)
{
    vertex1 = v1;
    vertex2 = v2;
    vertex3 = v3;
    vertex4 = v4;
}

Rectangle::~Rectangle()
{
    //dtor
}
