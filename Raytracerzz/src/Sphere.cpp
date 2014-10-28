#include "../include/Sphere.h"
#include "../include/Ray.h"
#include <iostream>
#include <cmath>

//one transperent and one perfect reflector
Sphere::Sphere(glm::vec3 pos, double rad, double trans, double refract, glm::vec3 theColor)
{
    position = pos;
    radius = rad;
    transparency = trans;
    refractiveIndex = refract;
    color = theColor;
}

Sphere::~Sphere()
{
    //dtor
}

bool Sphere::intersection(Ray r)
{
    glm::vec3 L = position - r.startingPoint; //L is the vector between the ray.starting point and the sphere

    float Tca = glm::dot(L,r.direction);
    if(Tca < 0)
    {
        return false;
    }

    float d2 =  glm::dot(L,L) - Tca * Tca;
    //float d = math::sqrt(d2);
    if(d2 > radius*radius) // d !?
    {
        return false;
    }

    float Thc = sqrt(radius*radius - d2);

    t0 = Tca - Thc; //t0 = distance from ray.startingPoint to the first intersection ANVÄND DESSA!
    t1 = Tca + Thc; //t1 = distance from ray.startingPoint to the second intersection ANVÄND DESSA!

    p0 = r.startingPoint + r.direction*t0;
    p1 = r.startingPoint + r.direction*t1;

    return true;
}

void Sphere::calculateChildrenRays()
{

}

glm::vec3 Sphere::getLatestIntersection()
{
    return p0;
}

float Sphere::getIntersectionDistance()
{
    return t0;
}

glm::vec3 Sphere::getColor()
{
    return color;
}

glm::vec3 Sphere::getP0()
{
    return p0;
}

glm::vec3 Sphere::getP1()
{
    return p1;
}

float Sphere::getDistanceT0()
{
    return 0;
}

float Sphere::getDistanceT1()
{
    return 0;
}
