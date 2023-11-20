#ifndef ICAMERA_H
#define ICAMERA_H

#include "dataBuffer.h"
using namespace std;

class ICamera
{
public:
    ICamera(){}
    virtual ~ICamera(){}
    virtual void displayMsg(const std::string &tag, const std::string  &msg) = 0;
    virtual void setData(DataBufferPtr data) = 0;
};
#endif // ICAMERA_H
