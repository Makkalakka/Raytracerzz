#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
        Camera();
        virtual ~Camera();
        vector position;
        vector viewDirection;
        vector viewPlaneDistance;
        vector viewPlaneResolution;
        int raysPerPixel;
        int pixels

        void renderImage(); //loop over all pixels
        void mappingFunction(); //convert radiometric pixel colour to photometric
        void displayImage(); //plot the figure or save it as an image
    protected:
    private:
};

#endif // CAMERA_H
