/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#include <chrono>
#include "RGBcamera.h"
#include "dataBufferPool.h"

// TODO: Remove compile time dependency
#include "iCamera.h"
#include <cmath>
// ------------------------------------------------------------

RGBCamera::RGBCamera(ICamera *control, std::shared_ptr<DataBufferPool> dataPool) :
    IBaseCamera(control, dataPool),
    m_tag("Player"),
    m_play(false),
    m_control(control),
    m_playRate(33),
    m_dataPool(dataPool),
    offset(0)

{
    m_control->displayMsg(m_tag, "Player constructed");
}

RGBCamera::~RGBCamera()
{
    // Thread stopping
    m_play = false;

    if(m_acquireThread.joinable())
    {
        m_acquireThread.join();
    }
}

void RGBCamera::startPlayData()
{
    m_play = true;
    m_acquireThread = std::thread(&RGBCamera::run, this);
    m_control->displayMsg(m_tag, "Start Playing");
}

void RGBCamera::stop()
{
    m_play = false;
    m_control->displayMsg(m_tag, "Stop playing");
}

bool RGBCamera::isPlaying()
{
    return m_play;
}

void RGBCamera::setPlayRate(int playRate)
{
    m_playRate = playRate;
}

//******* Below runs in own thread **********//
void RGBCamera::run()
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

bool RGBCamera::readImage(DataBufferPtr data)
{
    int width = data->m_image.width();
    int height = data->m_image.height();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int val = x + offset;

            // Calculate RGB values for a color gradient
            int red = static_cast<int>(255 * std::sin(0.01 * val));
            int green = static_cast<int>(255 * std::sin(0.02 * val));
            int blue = static_cast<int>(255 * std::sin(0.03 * val));

            data->m_image.setPixel(x, y, qRgb(red, green, blue));
        }

    }
    offset+=25;


    return true;
}

