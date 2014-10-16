#ifndef SPHERE_H
#define SPHERE_H


class Sphere
{
    public:
        Sphere();
        virtual ~Sphere();

        vector position;
        double radius;
        double transparency;
        double refractiveIndex; //1.0 <-> 1.5

        //calculates the intersection of a ray and a shpere
        void calculateIntersection();
        //depends on the texture of the sphere
        void calculateChildrenRays();
        //

    protected:
    private:
};

#endif // SPHERE_H
