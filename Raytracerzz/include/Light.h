#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light();
        virtual ~Light();

        double radiance;
        vector position;
        double size;

        void randomPosition();

    protected:
    private:
};

#endif // LIGHT_H
