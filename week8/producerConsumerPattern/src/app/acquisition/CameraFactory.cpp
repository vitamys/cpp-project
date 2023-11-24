#include <CameraFactory.h>
#include <VCamera.h>
#include<RGBcamera.h>
#include <iControl.h>
using namespace std;

std::unique_ptr<IBaseCamera> CameraFactory::getCamera(ICamera* camera, std::shared_ptr<DataBufferPool> data,const std::string &type)
{
    if(type=="rgb")
        return std::unique_ptr<IBaseCamera>(new RGBCamera(camera, data));
    else
        return std::unique_ptr<IBaseCamera>(new VCamera(camera, data));

}
