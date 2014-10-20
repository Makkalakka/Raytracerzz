#ifndef WALL_H
#define WALL_H


class Wall : SceneObject
{
    public:
        Wall();
        virtual ~Wall();

        glm::vec3 position;
        double size;

        glm::vec3 intersection(Ray r);
        void initialize();
        void computationOfIntersections();

    protected:
    private:
};

#endif // WALL_H
