#ifndef CAMERA_FACTORY_H
#define CAMERA_FACTORY_H
#include <string.h>
#include "VCamera.h"
#include "VRgbCamera.h"

class camera_factory
{
public:
    camera_factory(){};
    std::unique_ptr<ICamera> create_camera(std::string camera, Icontrol* control, std::shared_ptr<DataBufferPool> dataPool);
};

#endif // CAMERA_FACTORY_H
