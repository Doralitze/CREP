#include "executiontask.h"

ExecutionTask::ExecutionTask()
{
    //ctor
}

ExecutionTask::~ExecutionTask()
{
    //dtor
}

void compile(cl::Program::Sources sources, cl::Context context, cl::Device device, std::string kernel_code){
    //Build the software
    sources.push_back({kernel_code.c_str(),kernel_code.length()});
    cl::Program program(context,sources);
    if(program.build({device}) != CL_SUCCESS){
        std::cout << "Failed while compiling: " << std::endl;
        std::cout << kernel_code.c_str() << std::endl;
        exit(EXIT_ERROR_CL_COMPILE);
    }
}
