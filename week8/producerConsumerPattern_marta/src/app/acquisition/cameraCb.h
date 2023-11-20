#ifndef CAMERACB_H
#define CAMERACB_H

#include "dataBuffer.h"
#include <string>

class CameraCb // all functionality available in camera class
{
public:
    CameraCb(){}
    virtual ~CameraCb(){}
//    virtual void newImage() = 0;
    virtual void displayMsg(const std::string &tag, const std::string &msg) = 0;
    virtual void setData(DataBufferPtr dataJunk) = 0;
};

#endif // CAMERACB_H
