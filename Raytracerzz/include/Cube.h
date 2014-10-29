#include "../include/SceneObject.h"
#include <vector>

#ifndef CUBE_H
#define CUBE_H

class Rectangle;
class Ray;

class Cube : public SceneObject
{
    public:
        Cube(glm::vec3 pos, double d, bool t, double idx, glm::vec3 theColor);
        virtual ~Cube();

        void initialize();
        void computationOfChildrenRays();
		bool intersection(Ray r);
		glm::vec3 getLatestIntersection();
		float getIntersectionDistance();
		glm::vec3 getIntersectionNormal();
		glm::vec3 getColor();

		std::vector<Rectangle*> *walls;

    private:
		glm::vec3 position;
        float size;
        bool transparent;
        double refractiveIndex;
        glm::vec3 objectColor;

        glm::vec3 intersectionPoint;
        float intersectionDistance;
        glm::vec3 intersectionNormal;

		//corner points
		glm::vec3 p0, p1, p2, p3, p4, p5, p6, p7;

};

#endif // CUBE_H
