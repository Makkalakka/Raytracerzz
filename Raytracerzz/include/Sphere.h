#include <vector>
#include "../lib/glm/glm/glm.hpp"
#include "../include/SceneObject.h"

#ifndef SPHERE_H
#define SPHERE_H

class Ray;

class Sphere : public SceneObject
{
    public:
        Sphere(glm::vec3 pos, double rad, double trans, double refract, glm::vec3 color);
        virtual ~Sphere();

        //calculates the intersection of a ray and a shpere
        bool intersection(Ray r);
        glm::vec3 getLatestIntersection();
        float getIntersectionDistance();
        glm::vec3 getIntersectionNormal();
        //depends on the texture of the sphere
        void calculateChildrenRays();

        glm::vec3 getP0();
        glm::vec3 getP1();
        float getDistanceT0();
        float getDistanceT1();
        glm::vec3 getColor();

    protected:
    private:
        glm::vec3 position;
        double radius;
        double transparency;
        double refractiveIndex; //1.0 <-> 1.5
        glm::vec3 color;
        float t0;
        float t1;
        glm::vec3 p0;
        glm::vec3 p1;
        glm::vec3 intersectionNormal;
};

#endif // SPHERE_H
