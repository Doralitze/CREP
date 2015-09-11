#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <iostream>

#include "dimension.hpp"
#include "filter.hpp"
#include "codes.h"
#include "executiontask.h"
#include "hsvpixel.h"
#include "rgbapixel.hpp"

#define FK_USE_VECTOR_IMP

class Frame{
public:
    //Frame(Dimension &size);
    Frame(Dimension &size, RGBAPixel* initColor);
    int applyFilter(Filter &f);
    bool isValid(void);
    RGBAPixel& getDataAt(unsigned int x, unsigned int y);
private:
    unsigned int width;
    unsigned int height;
    //Width(X) * Height(Y) * RGBA
#ifdef FK_USE_VECTOR_IMP
    std::vector<std::vector<RGBAPixel>> data;
#else
    double* data = nullptr;
#endif
    bool valid = false;
};

std::vector<cl::Platform>& getAllPlatforms(void);
std::vector<cl::Device>& getAllDevices(void);
std::vector<cl::Context>& getAllContextes(void);
std::vector<ExecutionTask*>& getAllExecutors(void);


#endif // FRAME_HPP_INCLUDED
