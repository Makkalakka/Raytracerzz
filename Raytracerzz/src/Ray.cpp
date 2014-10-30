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
    insideObject = false;
    refractedObject = -1;
}

Ray::~Ray()
{
    //dtor
}

glm::vec3 Ray::rayTracedColor(int iteration)
{
    if(iteration<2 && importance>0.1)
    {

        if(insideObject) //maybe limit depending on iterations
        {

            if(world->Objects->at(refractedObject)->intersection(*this))  //create variable refractedObject
            {
                /*world->Objects->at(refractedObject)->getP1(); //second intersection, point to get out from

                //logic for calculating new direction
                //check for brewster angle... set ray to inside if reached

                glm::vec3 refractedRay = new Ray(...);

                refractedRay.importance = importance;*/

                return glm::vec3(0,0,0);//refractedRay.rayTracedColor(iteration++);
            }
            else
                return glm::vec3(0,0,0);
        }
        else
        {
            int objIdx = getIntersectedObject();

            if(objIdx != -1) //if an object have been intersected
            {

                if(!world->Objects->at(objIdx)->isDiffuse) //Change nr of iterations
                {
                    //glm::vec3 localColor = getLocalColor(objIdx);

                    if(world->Objects->at(objIdx)->isTransparent) //object is transparent, calculate two rays
                    {
                        /*float diffuseFactor = world->Objects->at(objIdx)->diffuseIndex; //how diffuse is the object? //variable not created

                        importance -= diffuseFactor*importance;

                        //calculate reflected ray

                        Ray reflectedRay = Ray(...);
                        reflectedRay.importance = importance / 2;
                        //calculate refracted ray



                        Ray refractedRay = Ray(...);
                        refractedRay.setInside();
                        refractedRay.refractedObject = objIdx;
                        refractedRay.importance = importance / 2;
                        */

                        return glm::vec3(0,0,0);//diffuseFactor*localColor + reflectedRay.rayTracedColor(iteration++) + refractedRay.rayTracedColor(iteration++)
                    }
                    else //the object is reflective only
                    {
                        float diffuseFactor = world->Objects->at(objIdx)->diffuseIndex; //how diffuse is the object?
                        float newImportance = importance - diffuseFactor*importance;

                        //calculate reflected ray direction
                        glm::vec3 reflectedDir = world->Objects->at(objIdx)->calculateReflectedRay(*this);

                        Ray reflectedRay = Ray(world->Objects->at(objIdx)->getLatestIntersection(), reflectedDir, newImportance, world);

                        glm::vec3 localColor = getLocalColor(objIdx);

                        return localColor*diffuseFactor*importance + reflectedRay.rayTracedColor(iteration++);
                    }

                }
                else
                    return getLocalColor(objIdx)*importance;


            }
            else //no object intersected = empty space
                return glm::vec3(0,0,0);

        }
    }
    else
        return glm::vec3(0,0,0);
}

int Ray::getIntersectedObject()
{
//check intersection, get color from object
    int nrOfObj = world->Objects->size();
    int objectIdx = -1;
    float minDist = 999999;
    //glm::vec3 rayColor = glm::vec3(0,0,0); //set to background color


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

        //rayColor = getLocalColor(world->Objects->at(objectIdx)->getColor(), world->Objects->at(objectIdx)->getIntersectionNormal(), world->Objects->at(objectIdx)->getLatestIntersection());
    return objectIdx;

}


glm::vec3 Ray::getLocalColor(int objIdx)
{
    glm::vec3 iPoint = world->Objects->at(objIdx)->getLatestIntersection();
    glm::vec3 n = world->Objects->at(objIdx)->getIntersectionNormal();
    glm::vec3 objColor = world->Objects->at(objIdx)->getColor();
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
            color += glm::vec3(0,0,0);
        else
        {
            float d = glm::length(lightVec);

            lightVec = glm::normalize(lightVec);

            float lambertian = glm::dot(glm::normalize(n), lightVec) / (d/5);

            if(lambertian >= 0)
                color += lambertian * objColor * world->Lights->at(i)->radiance; //diffuse phong
        }


    }

    return color/(float)nrOfLights;
}



