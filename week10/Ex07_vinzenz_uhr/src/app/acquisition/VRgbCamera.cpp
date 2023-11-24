/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#include <chrono>
#include "VRgbcamera.h"
#include "dataBufferPool.h"


VRgbCamera::VRgbCamera(Icontrol *control, std::shared_ptr<DataBufferPool> dataPool) :
    ICamera(control, dataPool),
    m_tag("Player"),
    m_play(false),
    offset_r(0),
    offset_g(85),
    offset_b(170)
{
    m_control->displayMsg(m_tag, "Player constructed");
}

VRgbCamera::~VRgbCamera()
{
    // Thread stopping
    m_play = false;

    if(m_acquireThread.joinable())
    {
        m_acquireThread.join();
    }
}

void VRgbCamera::startPlayData()
{
    m_play = false;

    if(m_acquireThread.joinable())
    {
        m_acquireThread.join();
    }
    m_play = true;
    m_acquireThread = std::thread(&VRgbCamera::run, this);
    m_control->displayMsg(m_tag, "Start Playing");
}

void VRgbCamera::stop()
{
    m_play = false;
    m_control->displayMsg(m_tag, "Stop playing");
}

bool VRgbCamera::isPlaying()
{
    return m_play;
}

//******* Below runs in own thread **********//
void VRgbCamera::run()
{
    while( m_play )
    {
        DataBufferPtr nextPtr = m_dataPool->getBuffer();
        if( readImage(nextPtr) )
        {
            m_control->setData(nextPtr);
        }
        // Control frame rate
        int sleeptime = static_cast<int>( 1000.0f/m_playRate ) ;
        std::this_thread::sleep_for( std::chrono::milliseconds( sleeptime ));
    }
}

bool VRgbCamera::readImage(DataBufferPtr data)
{
    int width = data->m_image.width();
    int height = data->m_image.height();

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            data->m_image.setPixel(x, y, qRgb(x+offset_r, x+offset_g ,x+offset_b));
            //data->m_image.setPixel(x, y, qRgb(0, 80 , 160));
        }
    }
    offset_r+= 25;
    offset_g+= 25;
    offset_b+= 25;
    return true;
}
