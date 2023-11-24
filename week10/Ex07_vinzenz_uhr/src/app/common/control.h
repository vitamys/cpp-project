/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef CONTROL_H
#define CONTROL_H

#include <memory>
#include "icontrol.h"

// Remove compile time dependency with observer pattern
// control should compile without including widget.h
#include "Iwidget.h"
// ------------------------------------------------------------

// Forward declarations
class ICamera;
class DataBufferPool;
class camera_factory;

class Control :  public Icontrol
{

public:
    Control(Iwidget *parent);
    virtual ~Control() override;

    virtual void displayMsg(const std::string &tag, const std::string &msg) override;
    virtual void setData(DataBufferPtr dataJunk) override;

    virtual void init() override;
    virtual void startPlaying() override;
    virtual void stopPlaying() override;
    virtual bool isPlaying() const override;
    virtual void setPlayRate(int playRate) override;
    virtual void setCamera(std::string camera) override;

private:
    uint m_height;
    uint m_widht;

    std::unique_ptr<ICamera> m_player;
    std::shared_ptr<DataBufferPool> m_dataPool;
    std::unique_ptr<camera_factory> m_camera_factory;
};
#endif // CONTROL_H
