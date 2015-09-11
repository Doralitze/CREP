#ifndef HSVPIXEL_H
#define HSVPIXEL_H

#include "rgbapixel.hpp"

class HSVPixel
{
    public:
        HSVPixel();
        virtual ~HSVPixel();
        //HSVPixel(const HSVPixel& other);
        HSVPixel& operator=(const HSVPixel& other);
        double getHue() { return m_Hue; }
        void setHue(double val) { m_Hue = val; }
        double getValue() { return m_Value; }
        void setValue(double val) { m_Value = val; }
        double getSaturation() { return m_Saturation; }
        void setSaturation(double val) { m_Saturation = val; }
        double getAlpha() { return m_Alpha; }
        void setAlpha(double val) { m_Alpha = val; }
        bool equals(HSVPixel* other);
        RGBAPixel& getRGBAData();
    protected:
    private:
        double m_Hue;
        double m_Value;
        double m_Saturation;
        double m_Alpha;
};

#endif // HSVPIXEL_H
