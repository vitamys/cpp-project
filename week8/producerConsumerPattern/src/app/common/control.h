/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <memory>

// TODO: Remove compile time dependency with observer pattern
// control should compile without including widget.h
//#include "widget.h"
#include "iControl.h"
#include "iCamera.h"
#include "iBaseCamera.h"
// ------------------------------------------------------------

// Forward declarations
class VCamera;
class DataBufferPool;

class Control :  public ICamera
{

public:
    Control(IControl *parent);
    ~Control();

    // TODO: Move to interface
    void displayMsg(const std::string &tag, const std::string &msg) override;
    void setData(DataBufferPtr dataJunk) override;
    // ------------------------------------------------------------

    void init();
    void startPlaying();
    void stopPlaying();
    bool isPlaying() const;
    void setPlayRate(int playRate);
    void setHardwareDevice(string device);
    string getHardwareDevice(string device);

private:
    IControl* m_widget;
    uint m_height;
    uint m_widht;
    string hardware_dw;

    std::unique_ptr<IBaseCamera> m_player;
    std::shared_ptr<DataBufferPool> m_dataPool;
};
#endif // CONTROL_H
