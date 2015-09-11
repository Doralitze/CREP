//this file holds the definitions for rgbapixel.hpp

#include "rgbapixel.hpp"

RGBAPixel::RGBAPixel()
{
    //ctor
}

RGBAPixel::~RGBAPixel()
{
    //dtor
}

RGBAPixel& RGBAPixel::operator+=(const RGBAPixel& rhs)
{
    red += rhs.red;
    blue += rhs.blue;
    green += rhs.green;
    alpha += rhs.alpha;
    return *this;
}

RGBAPixel& RGBAPixel::operator-=(const RGBAPixel& rhs)
{
    red -= rhs.red;
    blue -= rhs.blue;
    green -= rhs.green;
    alpha -= rhs.alpha;
    return *this;
}

RGBAPixel& RGBAPixel::operator*=(const RGBAPixel& rhs)
{
    double r1, r2, b1, b2, g1, g2, a1, a2;
    r1 = (this->getRed() / 255);
    g1 = (this->getGreen() / 255);
    b1 = (this->getBlue() / 255);
    a1 = (this->getAlpha() / 255);

    r2 = (rhs.red / 255);
    g2 = (rhs.green / 255);
    b2 = (rhs.blue / 255);
    a2 = (rhs.alpha / 255);

    this->setRed((RGBA_PIXEL_DATA_TYPE) ((r1 * r2) * 255));
    this->setGreen((RGBA_PIXEL_DATA_TYPE) ((g1 * g2) * 255));
    this->setBlue((RGBA_PIXEL_DATA_TYPE) ((b1 * b2) * 255));
    this->setAlpha((RGBA_PIXEL_DATA_TYPE) ((a1 * a2) * 255));

    return *this;
}

RGBAPixel& RGBAPixel::operator/=(const RGBAPixel& rhs)
{
    double r1, r2, b1, b2, g1, g2, a1, a2;
    r1 = (this->getRed() / 255);
    g1 = (this->getGreen() / 255);
    b1 = (this->getBlue() / 255);
    a1 = (this->getAlpha() / 255);

    r2 = (rhs.red / 255);
    g2 = (rhs.green / 255);
    b2 = (rhs.blue / 255);
    a2 = (rhs.alpha / 255);

    this->setRed((RGBA_PIXEL_DATA_TYPE) ((r1 / r2) * 255));
    this->setGreen((RGBA_PIXEL_DATA_TYPE) ((g1 / g2) * 255));
    this->setBlue((RGBA_PIXEL_DATA_TYPE) ((b1 / b2) * 255));
    this->setAlpha((RGBA_PIXEL_DATA_TYPE) ((a1 / a2) * 255));

    return *this;
}

bool RGBAPixel::operator==(RGBAPixel& other){
    if((other.getAlpha()) != (this->getAlpha()))
        return false;
    if(other.getRed() != this->getRed())
        return false;
    if(other.getGreen() != this->getGreen())
        return false;
    if(other.getBlue() != this->getBlue())
        return false;
    return true;
}

bool RGBAPixel::operator!=(RGBAPixel& other){
    if((other.getAlpha()) == (this->getAlpha()))
        return false;
    if(other.getRed() == this->getRed())
        return false;
    if(other.getGreen() == this->getGreen())
        return false;
    if(other.getBlue() == this->getBlue())
        return false;
    return true;
}

void RGBAPixel::setRed(RGBA_PIXEL_DATA_TYPE newRed){
    red = newRed;
}

void RGBAPixel::setGreen(RGBA_PIXEL_DATA_TYPE newGreen){
    green = newGreen;
}

void RGBAPixel::setBlue(RGBA_PIXEL_DATA_TYPE newBlue){
    blue = newBlue;
}

void RGBAPixel::setAlpha(RGBA_PIXEL_DATA_TYPE newAlpha){
    alpha = newAlpha;
}

RGBA_PIXEL_DATA_TYPE RGBAPixel::getRed(void){
    return red;
}

RGBA_PIXEL_DATA_TYPE RGBAPixel::getGreen(void){
    return green;
}

RGBA_PIXEL_DATA_TYPE RGBAPixel::getBlue(void){
    return blue;
}

RGBA_PIXEL_DATA_TYPE RGBAPixel::getAlpha(void){
    return alpha;
}

/*
Vec3b RGBAPixel::get3ChnVec(void){
    return Vec3b(this->getRed(), this->getGreen(), this->getBlue());
}

Vec4b RGBAPixel::get4ChnVec(void){
    return Vec4b(this->getRed(), this->getGreen(), this->getBlue(), this->getAlpha());
}
*/
