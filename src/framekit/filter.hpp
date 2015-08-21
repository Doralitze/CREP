#ifndef FILTER_HPP_INCLUDED
#define FILTER_HPP_INCLUDED

#include "settings.h"

#define __CL_ENABLE_EXCEPTIONS
#ifdef USE_FISSION
#define USE_CL_DEVICE_FISSION
#endif

#include <CL/cl.hpp>

class Filter{
    public:
        cl::Program::Sources& getSources(void) {return sources;};
    private:
        cl::Program::Sources sources;
};

#endif // FILTER_HPP_INCLUDED
