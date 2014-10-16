#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    public:
        Rectangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4);
        virtual ~Rectangle();

        glm::vec3 vertex1, vertex2, vertex3, vertex4;

        void calculateIntersections();
        void computationOfChildrenRays();

    protected:
    private:
};

#endif // RECTANGLE_H
