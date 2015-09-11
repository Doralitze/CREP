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
        ExecutionTask(cl::Context* context, cl::Device* device);
        virtual ~ExecutionTask();
        cl::Program& getContext(void){return program;}
        void compile(cl::Program::Sources sources, std::vector<std::string>* kernel_code);
    protected:
    private:
        bool busy;
        cl::Context* contextPtr;
        cl::Device* devicePtr;
        cl::Program program;
};

#endif // EXECUTIONTASK_H
