#include "../include/Rectangle.h"
#include "../include/Ray.h"
#include <iostream>

Rectangle::Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 n, glm::vec3 theColor)
{
    corner1 = v1;
    corner2 = v2;
    corner3 = v3;
    corner4 = v4;
    basV1 = v1 - v2;
    basV2 = v3 - v2;
    origin = basV1 + basV2;
	normal = n;
	objectColor = theColor;
}

bool Rectangle::intersection(Ray r)
{

    float denom = -(glm::dot(normal, r.direction));

    if(denom > 1e-6)   // if the angle between the normal and the vector from the ray is perpenduícular then denum is Zero, and no intersection is made.
    {

        glm::vec3 dist = -(corner1 - r.startingPoint);
        distance = glm::dot(dist, normal)/denom; //distance is the distance from the ray.startingPoint to the intersected point on the plane

        if (distance >= 0)
        {

            glm::vec3 tempP = distance * glm::normalize(r.direction); //the intersection point
            glm::vec3 vecP = tempP - corner2; //vector from the intersection point to corner2 of the rectangle

            float lenghtBasV1 = glm::length(basV1);
            float lenghtBasV2 = glm::length(basV2);

            float dot1 = glm::dot(vecP, glm::normalize(basV1));
            float dot2 = glm::dot(vecP, glm::normalize(basV2));

            if(dot1 <= lenghtBasV1 && dot1 >= 0 && dot2 <= lenghtBasV2  && dot2 >= 0)
            {
                P = tempP;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

void Rectangle::computationOfChildrenRays()
{

}

Rectangle::~Rectangle()
{
    //dtor
}

glm::vec3 Rectangle::getLatestIntersection()
{
    return P;
}

float Rectangle::getIntersectionDistance()
{
    return distance;
}

glm::vec3 Rectangle::getColor()
{
    return objectColor;
}
