#ifndef CUBE_H
#define CUBE_H


class Cube
{
    public:
        Cube();
        virtual ~Cube();

        vector position;
        double size;
        double transparency;
        double refractiveIndex;

        void initializationOfRectangleObjects();
        void computationOfChildrenRays;


    protected:
    private:
};

#endif // CUBE_H
