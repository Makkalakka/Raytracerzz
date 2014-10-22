#include "../lib/glm/glm/glm.hpp"

#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light();
        virtual ~Light();

        float radiance;
        glm::vec3 position;
        float size;

        void randomPosition();

    protected:
    private:
};

#endif // LIGHT_H
