#include "hsvpixel.h"

HSVPixel::HSVPixel()
{

    this->setHue(1.0);
    this->setSaturation(1.0);
    this->setValue(1.0);
    this->setAlpha(1.0);
}

HSVPixel::~HSVPixel()
{
    //dtor
}

HSVPixel& HSVPixel::operator=(const HSVPixel& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool HSVPixel::equals(HSVPixel* other){
    if(this->getHue() != other->getHue())
        return false;
    if(this->getSaturation() != other->getSaturation())
        return false;
    if(this->getValue() != other->getValue())
        return false;
    if(this->getAlpha() != other->getAlpha())
        return false;
    return true;
}

RGBAPixel& HSVPixel::getRGBAData(){
    RGBAPixel* newpixel = new RGBAPixel();
    newpixel->setAlpha(this->getAlpha());
    double chroma = this->getSaturation() * this->getValue();
    double newHUE = this->getHue() / 60;
    //TODO finish

    return *newpixel;
}
