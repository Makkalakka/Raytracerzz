#include "../include/Ray.h"
#include "../include/Scene.h"
#include "../include/SceneObject.h"
#include "../include/Light.h"

Ray::Ray(glm::vec3 theStartingPoint, glm::vec3 theDirection, float theImportance, Scene *w)
{
    startingPoint = theStartingPoint;
    direction = theDirection;
    importance = theImportance;
    world = w;
}

Ray::~Ray()
{
    //dtor
}

glm::vec3 Ray::calculateColor()
{
//check intersection, get color from object
    int nrOfObj = world->Objects->size();
    int objectIdx = -1;
    float minDist = 999999;
    glm::vec3 rayColor = glm::vec3(0,0,0); //set to background color


    for(int i=0; i<nrOfObj; i++)
    {
        if(world->Objects->at(i)->intersection(*this)) //if the object intersects with this ray
        {
            if(world->Objects->at(i)->getIntersectionDistance() < minDist) //if the distance to the intersection is shorter than previous intersections
            {
                objectIdx = i;
                minDist = world->Objects->at(i)->getIntersectionDistance();
            }
        }
    }

    //glm::vec3 theIntersection = world->Objects->at(i)->getLatestIntersection();
            //std::cout << "found intersection at: " << theIntersection.x << ", " << theIntersection.y << ", " << theIntersection.z << std::endl;
    if(objectIdx != -1)
    {
        rayColor = getLocalColor(world->Objects->at(objectIdx)->getColor(), world->Objects->at(objectIdx)->getIntersectionNormal(), world->Objects->at(objectIdx)->getLatestIntersection());

    }


    return rayColor;
}


glm::vec3 Ray::getLocalColor(glm::vec3 objColor, glm::vec3 n, glm::vec3 iPoint)
{
    int nrOfLights = world->Lights->size();
    int nrOfObj = world->Objects->size();

    glm::vec3 color = glm::vec3(0,0,0);

    for(unsigned i=0; i<nrOfLights; i++)
    {
        glm::vec3 lightVec = world->Lights->at(i)->position - iPoint;

        Ray shadowRay = Ray(iPoint, glm::normalize(lightVec), 1.0, world);
        bool intersected = false;

        for(int k=0; k<nrOfObj; k++)
        {
            if(world->Objects->at(k)->intersection(shadowRay)) //if the object intersects with this ray
            {
                if(glm::length(lightVec) >= world->Objects->at(k)->getIntersectionDistance())
                    intersected = true;
            }
        }


        if(intersected)
            color = glm::vec3(0,0,0);
        else
        {
            float d = glm::length(lightVec);

            lightVec = glm::normalize(lightVec);

            float lambertian = glm::dot(glm::normalize(n), lightVec) / (d/4);

            if(lambertian >= 0)
                color += lambertian * objColor * world->Lights->at(i)->radiance; //diffuse phong






        }






    }

    return color;
}



