#ifndef CUBE_H
#define CUBE_H


class Cube
{
    public:
        Cube(glm::vec3 &pos, double &d, bool &t, double &idx);
        virtual ~Cube();

        void initialize();
        void computationOfChildrenRays;
		glm::vec3 intersect(Ray r);


    protected:
    private:
		glm::vec3 position;
        double size;
        bool transparent;
        double refractiveIndex;
		std::vector<Rectangle*> *walls;

		//corner points
		glm::vec3 p0, p1, p2, p3, p4, p5, p6, p7;

};

#endif // CUBE_H
