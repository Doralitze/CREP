#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include "dimension.hpp"
#include "filter.hpp"

class Frame{
public:
    Frame(Dimension &size);
    int applyFilter(Filter &f);
private:
    int width;
    int height;
};

#endif // FRAME_HPP_INCLUDED
