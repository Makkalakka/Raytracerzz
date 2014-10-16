#ifndef RAY_H
#define RAY_H


class Ray
{
    public:
        Ray();
        virtual ~Ray();

        //the eye position
        vector startingPoint;
        //diection of the random generated ray?
        vector direction;
        //how much importance this ray has from the parent ray
        int importance;
        //RGB vector of the ray
        vector colour;
        //if it finds the wall or left the room (or finds the lightsource?)
        bool finalNode;
        //1 node for intransperent objects, 2 for transperent
        'dunno' pointersToChildrenNodes;
        //inside or outside an transperent object
        bool insideObject;

        //page 6 in the document*
        void calculateColour();
        //you shoot shadow rays from the ray-surface intersection point to the point light sources
        void calculateLocalLightingContribution();
        //


    protected:
    private:
};

#endif // RAY_H
