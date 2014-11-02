#include "../include/Ray.h"
#include "../include/Scene.h"
#include "../include/SceneObject.h"
#include "../include/Light.h"
#include <iostream>
#include <math.h>

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
    //std::cout << "Iteration: " << iteration << std::endl;
    if(iteration<4 && importance>0.05)
    {
        //std::cout << "iteration: " << iteration << std::endl;

        if(insideObject && (refractedObject != -1)) //maybe limit depending on iterations
        {
            //std::cout << "insideObject = " << insideObject << std::endl;
            if(world->Objects->at(refractedObject)->intersection(*this))
            {
                glm::vec3 secondIntersection = world->Objects->at(refractedObject)->getSecondIntersection();
                glm::vec3 objectNormal = glm::normalize(secondIntersection - world->Objects->at(refractedObject)->getPosition());

                /*float cosi = glm::dot(objectNormal, direction);
                float refractiveIndex = 1.2;
                float q = 1-refractiveIndex*refractiveIndex*(1-cosi*cosi);

                if(q<0)
                {
                    std::cout << "q = " << q << std::endl;
                    return glm::vec3(0,0,0);
                }*/


                glm::vec3 newRefractedDir = world->Objects->at(refractedObject)->calculateRefractedRay(*this);

                Ray refractedRay = Ray(secondIntersection, newRefractedDir, importance, world);

                return refractedRay.rayTracedColor(++iteration);
            }
            else
                return glm::vec3(0,0,0);
        }
        else
        {
            int objIdx = getIntersectedObject();
            //std::cout << "objectIndex: " << objIdx << std::endl;

            if(objIdx != -1) //if an object have been intersected
            {
                //std::cout << "isDiffuse = " << world->Objects->at(objIdx)->isDiffuse << std::endl;

                if(!world->Objects->at(objIdx)->isDiffuse()) //Change nr of iterations
                {
                    //glm::vec3 localColor = getLocalColor(objIdx);


                    if(world->Objects->at(objIdx)->isTransparent()) //object is transparent, calculate two rays
                    {
                        glm::vec3 localColor = getLocalColor(objIdx); //local color contribution

                        float diffuseFactor = world->Objects->at(objIdx)->getDiffuseIndex(); //how diffuse is the object?
                        float refractedImportance = (importance - diffuseFactor*importance)*0.9;
                        float reflectedImportance = (importance - diffuseFactor*importance)*0.1;

                        //calculate reflected ray direction
                        glm::vec3 reflectedDir = world->Objects->at(objIdx)->calculateReflectedRay(*this);
                        Ray reflectedRay = Ray(world->Objects->at(objIdx)->getLatestIntersection(), reflectedDir, reflectedImportance, world);

                        //calculate refracted ray
                        glm::vec3 refractedDir = world->Objects->at(objIdx)->calculateRefractedRay(*this);
                        Ray refractedRay = Ray(world->Objects->at(objIdx)->getLatestIntersection(), refractedDir, refractedImportance, world);
                        refractedRay.insideObject = true;
                        refractedRay.refractedObject = objIdx;

                        iteration++;

                        return importance*diffuseFactor*localColor + reflectedRay.rayTracedColor(iteration) + refractedRay.rayTracedColor(iteration);
                    }
                    else //the object is reflective only
                    {
                        //std::cout << "objectnr:" << objIdx << " is reflective but not transparent" << std::endl;

                        float diffuseFactor = world->Objects->at(objIdx)->getDiffuseIndex(); //how diffuse is the object?
                        float newImportance = importance - diffuseFactor*importance;

                        //calculate reflected ray direction
                        glm::vec3 reflectedDir = world->Objects->at(objIdx)->calculateReflectedRay(*this);

                        Ray reflectedRay = Ray(world->Objects->at(objIdx)->getLatestIntersection(), reflectedDir, newImportance, world);

                        glm::vec3 localColor = getLocalColor(objIdx);


                        return localColor*diffuseFactor*importance + reflectedRay.rayTracedColor(++iteration); //++ before to send the added number
                    }

                }
                else
                {
                    //std::cout << "the object is diffuse" << std::endl;
                    return getLocalColor(objIdx)*importance;
                }


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
    glm::vec3 n = glm::normalize(world->Objects->at(objIdx)->getIntersectionNormal());
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


        if(!intersected)
        {
            bool specular = !world->Objects->at(objIdx)->isDiffuse();
            bool transparent = world->Objects->at(objIdx)->isTransparent();

            float d = glm::length(lightVec);

            lightVec = glm::normalize(lightVec);

            float lambertian = 0;

            if(!transparent)
                lambertian = glm::dot(n, lightVec);// / (d/5);


            glm::vec3 H = glm::normalize(lightVec+glm::normalize(-iPoint));
            glm::vec3 specularity = glm::vec3(0,0,0);

            if(specular)
                specularity = (float)pow(glm::dot(n,H), 40)*glm::vec3(1,1,1);//(d/5);*/

            if(lambertian >= 0)
            {
                color += (lambertian * objColor + specularity) * world->Lights->at(i)->radiance / (d/3); //diffuse phong
            }

            //color = glm::normalize(color);
        }


    }

    return color;//(float)nrOfLights;
}



