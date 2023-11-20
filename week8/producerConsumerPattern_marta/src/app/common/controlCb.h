#ifndef CONTROLCB_H
#define CONTROLCB_H

#include "dataBuffer.h"
#include <string>

class ControlCb
{
public:
    ControlCb(){}
    virtual ~ControlCb(){}
//    virtual void newImage() = 0;
    virtual void displayMsg(const std::string &tag, const std::string  &msg) = 0;
    virtual void setData(DataBufferPtr data) = 0;
};

#endif // CONTROLCB_H
