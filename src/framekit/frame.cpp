#include "frame.hpp"

std::vector<cl::Platform> all_platforms;
std::vector<cl::Device> all_devices;
std::vector<cl::Context> all_contextes;
std::vector<ExecutionTask*> all_execkernels;

bool initialised = false;

Frame::Frame(Dimension &size, RGBAPixel* initColor){
    this->width = size.GetWidth();
    this->height = size.GetHeight();
    if(getAllPlatforms().size() == 0){
        std::cout << " No platforms found. Check OpenCL installation!" << std::endl;
        return;
    }
#ifdef FK_USE_VECTOR_IMP
    //this->data = new std::vector<std::vector<HSVPixel>>();
    data.resize(width);
    for(unsigned int x = 0; x < this->width; x++){
        //std::vector<HSVPixel*>* nvector = new std::vector<HSVPixel*>;
        data[x].resize(height);
        //this->data->push_back(nvector);
        for(unsigned int y = 0; y < this->height; y++){
            //HSVPixel* pixel = new HSVPixel();
            //nvector->push_back(pixel);
            if(initColor != nullptr){
                data[x][y].setRed(initColor->getRed());
                data[x][y].setGreen(initColor->getGreen());
                data[x][y].setBlue(initColor->getBlue());
                data[x][y].setAlpha(initColor->getAlpha());
            } else {
                data[x][y].setRed(255);
                data[x][y].setGreen(255);
                data[x][y].setBlue(255);
                data[x][y].setAlpha(255);
            }
        }
    }
#else
    data = new double[width][height][4];
    if(initColor != nullptr)
        for(unsigned int x = 0; x < this->width; x++)
            for(unsigned int y = 0; y < this->height; y++){
                data[x][y][0] = initColor->getRed();
                data[x][y][1] = initColor->getGreen();
                data[x][y][2] = initColor->getBlue();
                data[x][y][3] = initColor->getAlpha();
            }
#endif
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
                    ExecutionTask* task = new ExecutionTask(&context, &platformDevices[j]);
                    all_execkernels.push_back(task);
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

std::vector<ExecutionTask*>& getAllExecutors(void){
    if(!initialised)
        getAllPlatforms();
    return all_execkernels;
}

RGBAPixel& Frame::getDataAt(unsigned int x, unsigned int y){
    if((x >= width || y >= height) || (x < 0 || y < 0))
        throw "Your cordinates are outside the frame";
#ifndef FK_USE_VECTOR_IMP
    return &data[x][y];
#else
    //RGBAPixel* newPixel = new RGBAPixel();
    std::vector<RGBAPixel> row = data[x];
    RGBAPixel p = row[y];
    /*double r = p.getRed();
    double g = p.getGreen();
    double b = p.getBlue();
    double a = p.getAlpha();
    newPixel->setRed(r);
    newPixel->setGreen(g);
    newPixel->setBlue(b);
    newPixel->setAlpha(a);
    return *newPixel;*/
    return p;
#endif
}
