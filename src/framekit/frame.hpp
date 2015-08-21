#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <iostream>

#include "dimension.hpp"
#include "filter.hpp"

class Frame{
public:
    Frame(Dimension &size);
    int applyFilter(Filter &f);
    bool isValid(void);
private:
    int width;
    int height;
    bool valid = false;
};

std::vector<cl::Platform>& getAllPlatforms(void);
std::vector<cl::Device>& getAllDevices(void);

#endif // FRAME_HPP_INCLUDED
