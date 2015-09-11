__kernel void replaceColor(const __global double* 2DImage,
                           const __global uint width,
                           const __global uint height,
                           const __global uint channels,
                           const __global double* searchColor,
                           const __global double* replaceColor){
    uint y = get_global_id(0);
    uint x = get_global_id(1);
    if(y < height && x < width){

    }
}

__kernel void replaceChannel(const __global double* 2DImage,
                           const __global uint width,
                           const __global uint height,
                           const __global uint channel,
                           const __global double searchData,
                           const __global double replaceChannel){
    uint y = get_global_id(0);
    uint x = get_global_id(1);
    if(y < height && x < width){
        if(2DImage[x][y] == searchData){
            2DImage[x][y] = replaceData;
        }
    }
}
