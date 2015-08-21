#ifndef EXECUTIONTASK_H
#define EXECUTIONTASK_H

#define EXECUTIONTASK_CLINIT ""

#include <CL/cl.hpp>
#include <string.h>
#include <iostream>
#include "codes.h"

class ExecutionTask
{
    public:
        ExecutionTask();
        virtual ~ExecutionTask();
        cl::Program& getContext(void){return program;}
        void compile(cl::Program::Sources sources, cl::Context context);
    protected:
    private:
        cl::Program program;
};

#endif // EXECUTIONTASK_H
