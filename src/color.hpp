#ifndef COLOR_H
#define COLOR_H

//#include "includes.h"

class Color
{
    public:
        Color();
        virtual ~Color();
        Color& operator+=(const Color& other);
        Color& operator-=(const Color& other);
        Color& operator*=(const Color& other);
        Color& operator/=(const Color& other);
        void setRed(short);
        void setGreen(short);
        void setBlue(short);
        void setAlpha(short);
        short getRed(void);
        short getGreen(void);
        short getBlue(void);
        short getAlpha(void);
        //Vec3b get3ChnVec(void);
        //Vec4b get4ChnVec(void);
    protected:
        //Nothing
    private:
        short red = 255;
        short green = 255;
        short blue = 255;
        short alpha = 255;
};

#endif // COLOR_H
