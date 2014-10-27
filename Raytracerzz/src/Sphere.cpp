#include "../include/Sphere.h"

//one transperent and one perfect reflector
Sphere::Sphere(glm::vec3 pos, double rad, double trans, double refract)
{
    position = pos;
    radius = rad;
    transparency = trans;
    refractiveIndex = refract;
}

Sphere::~Sphere()
{
    //dtor
}

bool Sphere::intersection(Ray r)
{
    /*glm::vec3 L = position - r.startingPoint; //L is the vector between the ray.starting point and the sphere

    float Tca = L.dot(r.direction);
    if(Tca < 0)
    {
        return false;
    }

    float d2 =  L.dot(L) - Tca * Tca;
    if(d > radius*radius)
    {
        return false;
    }

    glm::vec3 Thc = math::sqrt(radius*radius - d2);

    t0 = Tca - Thc; //t0 = distance from ray.startingPoint to the first intersection ANVÄND DESSA!
    t1 = Tca + Thc; //t1 = distance from ray.startingPoint to the second intersection ANVÄND DESSA!

    p0 = r.startingPoint + r.direction*t0;
    p1 = r.startingPoint + r.direction*t1;*/

    return true;
}

void Sphere::calculateChildrenRays()
{

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
