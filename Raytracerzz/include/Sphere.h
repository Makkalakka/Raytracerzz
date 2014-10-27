#include <vector>
#include "../lib/glm/glm/glm.hpp"
#include "../include/Ray.h"

#ifndef SPHERE_H
#define SPHERE_H


class Sphere
{
    public:
        Sphere(glm::vec3 pos, double rad, double trans, double refract);
        virtual ~Sphere();

        //calculates the intersection of a ray and a shpere
        bool intersection(Ray r);
        glm::vec3 getLatestIntersection();
        float getIntersectionDistance();
        //depends on the texture of the sphere
        void calculateChildrenRays();

        glm::vec3 getP0();
        glm::vec3 getP1();
        float getDistanceT0();
        float getDistanceT1();

    protected:
    private:
        glm::vec3 position;
        double radius;
        double transparency;
        double refractiveIndex; //1.0 <-> 1.5
        glm::vec3 t0;
        glm::vec3 t1;
        glm::vec3 p0;
        glm::vec3 p1;
};

#endif // SPHERE_H
