#include "../include/Camera.h"
#include "../include/Pixel.h"
#include "../include/Scene.h"

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
void Camera::renderImage(Scene &world)
{
    glm::vec3 *pixelValue = image;

    float normW = 0, normH = 0;

    glm::vec3 right = glm::vec3(1, 0, 0);
    glm::vec3 down = glm::vec3(0, -1, 0);
    glm::vec3 imagePoint;

    for(unsigned h = 1; h<=height; ++h)
    {
        for(unsigned w = 1; w<=width; ++w, ++pixelValue)
        {
            normW = (w/width) - 0.5 - 1/width;
            normH = (h/height) - 0.5 - 1/height;

            imagePoint = normW*right + normH*down + viewDirection*viewPlaneDistance;

            //glm::vec3 raydir = imagePoint - position;
            float dx = 1/width;
            float dy = 1/height;

            Pixel *pix = new Pixel(imagePoint, right*dx, down*dy, glm::vec3(0,0,0), raysPerPixel, world);//unfinished specs

            pix->shootRays();

            *pixelValue = pix->getColor();
        }
    }


    //Writes image values to file here...

}

//convert radiometric pixel colour to photometric
void Camera::mappingFunction()
{

}

//plot the figure or save it as an image
void Camera::displayImage()
{

}
