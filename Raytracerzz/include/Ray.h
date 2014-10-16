#ifndef RAY_H
#define RAY_H


class Ray
{
    public:
        Ray(glm::vec3 theStartingPoint, glm::vec3 theDirection, int theImportance, glm::vec3 theColor);
        virtual ~Ray();

        //the eye position
        glm::vec3 startingPoint;
        //diection of the random generated ray?
        glm::vec3 direction;
        //how much importance this ray has from the parent ray
        int importance;
        //RGB vector of the ray
        glm::vec3 color;
        //if it finds the wall or left the room (or finds the lightsource?)
        bool finalNode;
        //1 node for intransperent objects, 2 for transperent
        'dunno' pointersToChildrenNodes;
        //inside or outside an transperent object
        bool insideObject;

        //page 6 in the document*
        void calculateColor();
        //you shoot shadow rays from the ray-surface intersection point to the point light sources
        void calculateLocalLightingContribution();
        //


    protected:
    private:
};

#endif // RAY_H
