#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
        Pixel(glm::vec3 &c, glm::vec3 &right, glm::vec3 &down, glm::vec3 &cPos, double rpp, Scene &w);
        virtual ~Pixel();

        void shootRays();


    protected:
    private:
        std::vector<Ray*> *arrayOfRays; //holds the adress to all rays shot from the eye point
        glm::vec3 pixelColor;
        glm::vec3 corner, rightAxis, downAxis, cameraPos;
        double raysPerPixel;
        Scene *world;
};

#endif // PIXEL_H
