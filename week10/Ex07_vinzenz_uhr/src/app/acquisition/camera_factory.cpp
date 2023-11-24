#include "camera_factory.h"
#include <iostream>

std::unique_ptr<ICamera> camera_factory::create_camera(std::string camera, Icontrol* control, std::shared_ptr<DataBufferPool> dataPool)
{
    if(camera=="VCamera")
        return std::unique_ptr<ICamera>(new VCamera(control, dataPool));
    else if (camera == "VRgbCamera")
        return std::unique_ptr<ICamera>(new VRgbCamera(control, dataPool));
    else
        std::cout << "can't detect camera" << std::endl;
    return std::unique_ptr<ICamera>(new VCamera(control, dataPool));
}
