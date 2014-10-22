#include "Rectangle.h"

Rectangle::Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 n)
{
    corner1 = v1;
    corner2 = v2;
    corner3 = v3;
    corner4 = v4;
    basV1 = v1 - v2;
    basV2 = v3 - v2;
    origin = basV1 + basV2;
	normal = n;
}

bool Rectangle::calculateIntersection(Ray r)
{
    float denum = glm::dot(normal, r.direction);
    if(denum > 1e-6)   // if the angle between the normal and the vector from the ray is perpenduícular then denum is Zero, and no intersection is made.
    {
        glm::vec3 dist = origin - r.startingPoint;
        distance = glm::dot(dist, normal)/denum; //distance is the distance from the ray.startingPoint to the intersected point on the plane
        if (distance >= 0)
        {
            glm::vec3 tempP = distance * glm::normalize(r.direction); //punkten
            glm::vec3 vecP = tempP - v2; //vector P from v1

            float lenghtBasV1 = glm::length(basV1);
            float lenghtBasV2 = glm::length(basV2);

            float dot1 = glm::dot(vecP,glm::normalize(basV1));
            float dot2 = glm::dot(vecP,glm::normalize(basV2));

            if(dot1 < lenghtBasV1 && dot1 > 0 && dot2 < lenghtBasV2  && dot2> 0)
            {
                P = tempP;
                return true;
            }
        }
        else
            return false;
    }
}

void Rectangle::computationOfChildrenRays()
{

}

Rectangle::~Rectangle()
{
    //dtor
}

glm::vec3 Rectangle::getP()
{
    return P;
}

float Rectangle::getDistance()
{
    return distance;
