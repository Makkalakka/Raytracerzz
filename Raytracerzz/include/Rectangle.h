#include "../lib/glm/glm/glm.hpp"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Ray;

class Rectangle
{
    public:
        Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 n);
        virtual ~Rectangle();



        glm::vec3 calculateIntersection(Ray r);
        void computationOfChildrenRays();

    protected:
    private:
		glm::vec3 corner1, corner2, corner3, corner4;
		glm::vec3 normal;
};

#endif // RECTANGLE_H
