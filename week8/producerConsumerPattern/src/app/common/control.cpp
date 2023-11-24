/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#include "control.h"
#include "VCamera.h"
#include "dataBufferPool.h"
#include "CameraFactory.h"
#include "iBaseCamera.h"

Control::Control(IControl *parent) :
    m_widget(parent),
    m_height(256),
    m_widht(256),
    hardware_dw("rgb")
{
    // init control handels
    init();
}

Control::~Control()
{

}

// reset main handels
void Control::init()
{
    // init data pool
    m_dataPool.reset(new DataBufferPool(m_height, m_widht));

    // create file reader
    m_player.reset( new RGBCamera( this, m_dataPool) );

    // Message
    m_widget->displayMsg("Control", "Constructed");
}

// -----------------------------------------------------------------
// Functions called by Player (tight coupling)
// -----------------------------------------------------------------
void Control::displayMsg(const std::string &tag, const std::string &msg)
{    
    m_widget->displayMsg(tag, msg);
}

void Control::setData(DataBufferPtr dataJunk)
{
    m_widget->setData(dataJunk);
}

void Control::startPlaying()
{
    init(); // reinit handlers
    //TODO: get devicetype
    string deviceType = hardware_dw;
    m_widget->displayMsg("deviceType ", hardware_dw);
    unique_ptr<CameraFactory> cameraFactory = unique_ptr<CameraFactory>(new CameraFactory());
    m_player = unique_ptr<IBaseCamera>(cameraFactory->getCamera(this, m_dataPool, hardware_dw));
    m_player->startPlayData();
}

void Control::stopPlaying()
{
    m_player->stop();
}

bool Control::isPlaying() const
{
    bool isPlaying = (m_player->isPlaying());
    return isPlaying;
}

void Control::setPlayRate(int playRate)
{
    m_player->setPlayRate(playRate);
}

void Control::setHardwareDevice(string device){
    hardware_dw= device;
}
