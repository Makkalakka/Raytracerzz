#include "Cube.h"

//one
Cube::Cube(glm::vec3 &pos, double &d, bool &t, double &idx)
{
    position = pos;
	size = d;
	transparent = t;
	refractiveIndex = idx;
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


	walls.push_back(new Rectangle(p0, p3, p2, p1, glm::vec3(0, 0, -1))); //bottom
	walls.push_back(new Rectangle(p0, p4, p5, p1, glm::vec3(-1, 0, 0))); //left
	walls.push_back(new Rectangle(p1, p5, p6, p2, glm::vec3(0, 1, 0))); //back
	walls.push_back(new Rectangle(p3, p2, p6, p7, glm::vec3(1, 0, 0))); //right
	walls.push_back(new Rectangle(p0, p3, p7, p4, glm::vec3(0, -1, 0))); //front
	walls.push_back(new Rectangle(p4, p7, p6, p5, glm::vec3(0, 0, 1))); //top
}

glm::vec3 Cube::intersect(Ray r)
{

}