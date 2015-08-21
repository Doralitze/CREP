#include "frame.hpp"

std::vector<cl::Platform> all_platforms;
std::vector<cl::Device> all_devices;
std::vector<cl::Context> all_contextes;

bool initialised = false;

Frame::Frame(Dimension &size){
    this->width = size.GetWidth();
    this->height = size.GetHeight();
    if(getAllPlatforms().size() == 0){
        std::cout << " No platforms found. Check OpenCL installation!" << std::endl;
        return;
    }
    valid = true;
}

bool Frame::isValid(void){
    return valid;
}

int Frame::applyFilter(Filter &filter){

return 0;
}

std::vector<cl::Platform>& getAllPlatforms(void){
    if(!initialised){
        cl::Platform::get(&all_platforms);
        if(all_platforms.size()==0){
            std::cout<<" No platforms found. Check OpenCL installation!\n";
            exit(EXIT_ERROR_CL_INIT);
        } else {
            std::cout << "found the following OpenCL platforms:" << std::endl;
            for(unsigned int i = 0; i < all_platforms.size(); i++){
                std::cout << all_platforms[i].getInfo<CL_PLATFORM_NAME>() << std::endl;
                //Add devices to vector
                std::vector<cl::Device> platformDevices;
                all_platforms[i].getDevices(CL_DEVICE_TYPE_ALL, &platformDevices);
                for(unsigned int j = 0; j < platformDevices.size(); j++){
                    all_devices.push_back(platformDevices[j]);
                    std::vector<cl::Device> sd;
                    sd.push_back(platformDevices[j]);
                    cl::Context context(sd);
                    all_contextes.push_back(context);
                    std::cout << "    Device [" << std::to_string(all_contextes.size()).c_str() << "]: " << platformDevices[j].getInfo<CL_DEVICE_NAME>() << std::endl;
                }
            }
            std::cout << std::endl;
        }
        initialised = true;
    }
    return all_platforms;
}

std::vector<cl::Device>& getAllDevices(void){
    if(!initialised)
        getAllPlatforms();
    return all_devices;
}

std::vector<cl::Context>& getAllContextes(void){
    if(!initialised)
        getAllPlatforms();
    return all_contextes;
}
