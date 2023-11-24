/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef ICONTROL_H
#define ICONTROL_H

#include <QWidget>
#include <memory>

// Remove compile time dependency with observer pattern
// control should compile without including widget.h
#include "Iwidget.h"
// ------------------------------------------------------------

// Forward declarations

class Icontrol : public QWidget
{

public:
    Icontrol(Iwidget *parent) : m_widget(parent){};
    virtual ~Icontrol() {};

    virtual void displayMsg(const std::string &tag, const std::string &msg) = 0;
    virtual void setData(DataBufferPtr dataJunk) = 0;
    virtual void init() = 0;
    virtual void startPlaying() = 0;
    virtual void stopPlaying() = 0;
    virtual bool isPlaying() const = 0;
    virtual void setPlayRate(int playRate) = 0;
    virtual void setCamera(std::string camera) = 0;
protected:
    Iwidget* m_widget;
};
#endif // ICONTROL_H
