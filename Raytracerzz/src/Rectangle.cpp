#include "Rectangle.h"

Rectangle::Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 n)
{
    corner1 = v1;
    corner2 = v2;
    corner3 = v3;
    corner4 = v4;
	normal = n;
}

Rectangle::~Rectangle()
{
    //dtor
}
