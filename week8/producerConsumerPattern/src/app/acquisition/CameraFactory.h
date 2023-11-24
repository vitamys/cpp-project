#ifndef CAMERAFACTORY_H
#define CAMERAFACTORY_H

#include <iCamera.h>
#include <iControl.h>
#include "RGBcamera.h"

using namespace std;

class CameraFactory
{
public:
    CameraFactory(){}
    std::unique_ptr<IBaseCamera> getCamera(ICamera* camera, std::shared_ptr<DataBufferPool> data,const std::string &type);
};

#endif // CAMERAFACTORY_H
