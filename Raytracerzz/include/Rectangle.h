#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    public:
        Rectangle();
        virtual ~Rectangle();

        vector positionsOfCornerPoints;

        void calculateIntersections();
        void computationOfChildrenRays();

    protected:
    private:
};

#endif // RECTANGLE_H
