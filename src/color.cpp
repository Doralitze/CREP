//this file holds the definitions for color.hpp

#include "color.hpp"

Color::Color()
{
    //ctor
}

Color::~Color()
{
    //dtor
}

Color& Color::operator+=(const Color& rhs)
{
    red += rhs.red;
    blue += rhs.blue;
    green += rhs.green;
    alpha += rhs.alpha;
    return *this;
}

Color& Color::operator-=(const Color& rhs)
{
    red -= rhs.red;
    blue -= rhs.blue;
    green -= rhs.green;
    alpha -= rhs.alpha;
    return *this;
}

Color& Color::operator*=(const Color& rhs)
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

    this->setRed((short) ((r1 * r2) * 255));
    this->setGreen((short) ((g1 * g2) * 255));
    this->setBlue((short) ((b1 * b2) * 255));
    this->setAlpha((short) ((a1 * a2) * 255));

    return *this;
}

Color& Color::operator/=(const Color& rhs)
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

    this->setRed((short) ((r1 / r2) * 255));
    this->setGreen((short) ((g1 / g2) * 255));
    this->setBlue((short) ((b1 / b2) * 255));
    this->setAlpha((short) ((a1 / a2) * 255));

    return *this;
}

void Color::setRed(short newRed){
    red = newRed;
}

void Color::setGreen(short newGreen){
    green = newGreen;
}

void Color::setBlue(short newBlue){
    blue = newBlue;
}

void Color::setAlpha(short newAlpha){
    alpha = newAlpha;
}

short Color::getRed(void){
    return red;
}

short Color::getGreen(void){
    return green;
}

short Color::getBlue(void){
    return blue;
}

short Color::getAlpha(void){
    return alpha;
}

/*
Vec3b Color::get3ChnVec(void){
    return Vec3b(this->getRed(), this->getGreen(), this->getBlue());
}

Vec4b Color::get4ChnVec(void){
    return Vec4b(this->getRed(), this->getGreen(), this->getBlue(), this->getAlpha());
}
*/
