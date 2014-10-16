#ifndef WALL_H
#define WALL_H


class Wall
{
    public:
        Wall();
        virtual ~Wall();

        vector position;
        double size;

        void initializationOfRectangleObjects();
        void computationOfIntersections();

    protected:
    private:
};

#endif // WALL_H
