#ifndef RGBA_PIXEL_H
#define RGBA_PIXEL_H

//#include "includes.h"

#define RGBA_PIXEL_DATA_TYPE double

class RGBAPixel
{
    public:
        RGBAPixel();
        virtual ~RGBAPixel();
        RGBAPixel& operator+=(const RGBAPixel& other);
        RGBAPixel& operator-=(const RGBAPixel& other);
        RGBAPixel& operator*=(const RGBAPixel& other);
        RGBAPixel& operator/=(const RGBAPixel& other);
        bool operator==(RGBAPixel& other);
        bool operator!=(RGBAPixel& other);
        void setRed(RGBA_PIXEL_DATA_TYPE);
        void setGreen(RGBA_PIXEL_DATA_TYPE);
        void setBlue(RGBA_PIXEL_DATA_TYPE);
        void setAlpha(RGBA_PIXEL_DATA_TYPE);
        RGBA_PIXEL_DATA_TYPE getRed();
        RGBA_PIXEL_DATA_TYPE getGreen();
        RGBA_PIXEL_DATA_TYPE getBlue();
        RGBA_PIXEL_DATA_TYPE getAlpha();
        //Vec3b get3ChnVec(void);
        //Vec4b get4ChnVec(void);
    protected:
        //Nothing
    private:
        RGBA_PIXEL_DATA_TYPE red = 255;
        RGBA_PIXEL_DATA_TYPE green = 255;
        RGBA_PIXEL_DATA_TYPE blue = 255;
        RGBA_PIXEL_DATA_TYPE alpha = 255;
};

#endif // RGBA_PIXEL_H
