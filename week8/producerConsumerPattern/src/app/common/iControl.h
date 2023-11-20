#ifndef ICONTROL_H
#define ICONTROL_H

#include "dataBuffer.h"
using namespace std;

class IControl
{
public:
    IControl(){}
    virtual ~IControl(){}
    virtual void displayMsg(const std::string &tag, const std::string  &msg) = 0;
    virtual void setData(DataBufferPtr data) = 0;
};
#endif // ICONTROL_H
