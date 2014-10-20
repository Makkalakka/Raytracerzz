#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
        Pixel();
        virtual ~Pixel();

        void shootRays();


    protected:
    private:
        std::vector<Ray*> *arrayOfRays; //holds the adress to all rays shot from the eye point
        glm::vec3 pixelColor;
};

#endif // PIXEL_H
