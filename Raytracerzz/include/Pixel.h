#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
        Pixel();
        virtual ~Pixel();

        int[] arrayOfRays; //holds and adresses all rays
        vector colourOfPixel;

        void shootingRays();


    protected:
    private:
};

#endif // PIXEL_H
