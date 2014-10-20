#include "Camera.h"

Camera::Camera(int h, int w, int rpp, double vpd)
{
    position = glm::vec3(0,0,0);
    viewDirection = glm::vec3(0,1,0);
    viewPlaneDistance = vpd;
    raysPerPixel = rpp;
    height = h;
    width = w;
    image = new glm::vec3[width*height];
}

//loop over all pixels
void renderImage(Scene &world)
{
    glm::vec3 *pixelValue = image;

    for(unsigned h = 0; h<height; ++h)
    {
        for(unsigned w = 0; w<width; ++w, ++pixelValue)
        {
            //Pixel pix = new Pixel();//unfinished specs

            //pix.shootRays();

            //pixelValue = pix.getColor;
        }
    }


    //Writes image values to file here...

}

//convert radiometric pixel colour to photometric
void mappingFunction()
{

}

//plot the figure or save it as an image
void displayImage()
{

}
