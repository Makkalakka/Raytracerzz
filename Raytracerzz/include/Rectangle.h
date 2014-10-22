#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    public:
        Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, glm::vec3 n);
        virtual ~Rectangle();

        bool calculateIntersection(Ray r);
        void computationOfChildrenRays();
        glm::vec3 Rectangle::getP();
        float Rectangle::getDistance();

    protected:
    private:
		glm::vec3 corner1, corner2, corner3, corner4;
        glm::vec3 basV1, basV2;
		glm::vec3 normal;
		glm::vec3 origin;
		float distance;
		glm::vec3 P;
};

#endif // RECTANGLE_H
