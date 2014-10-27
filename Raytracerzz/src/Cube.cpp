#include "../include/Cube.h"
#include "../include/SceneObject.h"
#include "../include/Rectangle.h"
#include "../include/Ray.h"
#include <iostream>

//one
Cube::Cube(glm::vec3 pos, double d, bool t, double idx, glm::vec3 color)
{
    position = pos;
	size = d;
	transparent = t;
	refractiveIndex = idx;
	objectColor = color;
}

Cube::~Cube(){}

void Cube::initialize()
{
	//Defining corner points, scaling and translation to world coordinates

	//Bottom four points
	p0 = glm::vec3(0, 0, 0)*size + position;
	p1 = glm::vec3(0, 1, 0)*size + position;
	p2 = glm::vec3(1, 1, 0)*size + position;
	p3 = glm::vec3(1, 0, 0)*size + position;

	//top four points
	p4 = glm::vec3(0, 0, 1)*size + position;
	p5 = glm::vec3(0, 1, 1)*size + position;
	p6 = glm::vec3(1, 1, 1)*size + position;
	p7 = glm::vec3(1, 0, 1)*size + position;


	walls->push_back(new Rectangle(p0, p3, p2, p1, glm::vec3(0, 0, -1), objectColor)); //bottom
	walls->push_back(new Rectangle(p0, p4, p5, p1, glm::vec3(-1, 0, 0), objectColor)); //left
	walls->push_back(new Rectangle(p1, p5, p6, p2, glm::vec3(0, 1, 0), objectColor)); //back
	walls->push_back(new Rectangle(p3, p2, p6, p7, glm::vec3(1, 0, 0), objectColor)); //right
	walls->push_back(new Rectangle(p0, p3, p7, p4, glm::vec3(0, -1, 0), objectColor)); //front
	walls->push_back(new Rectangle(p4, p7, p6, p5, glm::vec3(0, 0, 1), objectColor)); //top
}

bool Cube::intersection(Ray r)
{
    float minDist = 99999999;
    int rectangleIdx = -1;

    for(unsigned i=0; i<walls->size(); i++)
    {
        if(walls->at(i)->intersection(r))
        {
            if(walls->at(i)->getIntersectionDistance() < minDist)
            {
                minDist = walls->at(i)->getIntersectionDistance();
                rectangleIdx = i;
            }
        }
    }

    std::cout << "rectangleIdx: " << rectangleIdx << std::endl;

    if(rectangleIdx != -1)
    {
        intersectionDistance = minDist;
        intersectionPoint = walls->at(rectangleIdx)->getLatestIntersection();
        return true;
    }
    else
        return false;

}

glm::vec3 Cube::getColor()
{
    return objectColor;
}

glm::vec3 Cube::getLatestIntersection()
{
    return intersectionPoint;
}

float Cube::getIntersectionDistance()
{
    return intersectionDistance;
}


