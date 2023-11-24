/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#include "control.h"
#include "VCamera.h"
#include "camera_factory.h"
#include "dataBufferPool.h"

class camera_factory;

Control::Control(Iwidget *parent) :
    Icontrol(parent),
    m_height(256),
    m_widht(256)
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
    if(m_player==nullptr)
        m_player.reset( new VCamera( this, m_dataPool) );

    // Message
    m_widget->displayMsg("Control", "Constructed");

    //m_camera_factory.reset( new camera_factory());
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
    //init(); // reinit handlers
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

void Control::setCamera(std::string camera)
{
    m_player=m_camera_factory->create_camera(camera, this, m_dataPool);
}

void Control::setPlayRate(int playRate)
{
    m_player->setPlayRate(playRate);
}
