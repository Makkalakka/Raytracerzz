#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
        Camera();
        virtual ~Camera();
        glm::vec3 position;
        glm::vec3 viewDirection;
        vector viewPlaneDistance;
        vector viewPlaneResolution;
        int raysPerPixel;
        int pixels;

        void renderImage(); //loop over all pixels
        void mappingFunction(); //convert radiometric pixel colour to photometric
        void displayImage(); //plot the figure or save it as an image
    protected:
    private:
};

#endif // CAMERA_H
