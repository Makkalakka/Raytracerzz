#include "../include/Ray.h"
#include "../include/Scene.h"
#include "../include/SceneObject.h"

Ray::Ray(glm::vec3 theStartingPoint, glm::vec3 theDirection, double theImportance, Scene *w)
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
    glm::vec3 rayColor;


    for(int i=0; i<nrOfObj; i++)
    {
        if(world->Objects->at(i)->intersection(*this)) //if the object intersects with this ray
        {
            if(world->Objects->at(i)->getIntersectionDistance() < minDist) //if the distance to the intersection is shorter than previous
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
        rayColor = world->Objects->at(objectIdx)->getColor();
    }
    else
        rayColor = glm::vec3(0,0,0);

    return rayColor;
}

