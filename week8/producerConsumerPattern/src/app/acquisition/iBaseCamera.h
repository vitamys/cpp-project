#ifndef IBASECAMERA_H
#define IBASECAMERA_H

#include <memory>
class ICamera;
class DataBufferPool;

class IBaseCamera
{
public:
    IBaseCamera(ICamera* , std::shared_ptr<DataBufferPool>){}
    virtual ~IBaseCamera(){}
    virtual void startPlayData()=0;
    virtual void stop()=0;
    virtual void setPlayRate(int playRate)=0;
    virtual bool isPlaying()=0;
};

#endif // IBASECAMERA_H
