#include "executiontask.h"

ExecutionTask::ExecutionTask(cl::Context* context, cl::Device* device)
{
    busy = false;
    contextPtr = context;
    devicePtr = device;
}

ExecutionTask::~ExecutionTask()
{
    //dtor
}

void ExecutionTask::compile(cl::Program::Sources sources, std::vector<std::string>* kernel_code){
    //Build the software
    for(unsigned int i = 0; i < kernel_code->size(); i++)
        sources.push_back({kernel_code->at(i).c_str(), kernel_code->at(i).length()});
    cl::Program _program(*contextPtr,sources);
    if(_program.build({*devicePtr}) != CL_SUCCESS){
        std::cout << "Failed while compiling: " << std::endl;
        for(unsigned int i = 0; i < kernel_code->size(); i++)
            std::cout << kernel_code->at(i).c_str() << std::endl;
        exit(EXIT_ERROR_CL_COMPILE);
    }
    this->program = _program;
}
