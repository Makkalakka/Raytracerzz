#include <vector>

#ifndef SCENE_H
#define SCENE_H

class SceneObject;
class Light;

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        void addObject(SceneObject *so);
        void addLight(Light *li);

    protected:
    private:
        std::vector<SceneObject*> *Objects;
        std::vector<Light*> *Lights;
};

#endif // SCENE_H
