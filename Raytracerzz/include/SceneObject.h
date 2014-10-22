#include "../lib/glm/glm/glm.hpp"

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

class Ray;

class SceneObject
{
    public:
        SceneObject();
        virtual ~SceneObject();
        virtual glm::vec3 intersection(Ray r) = 0;
    protected:
    private:
};

#endif // SCENEOBJECT_H
