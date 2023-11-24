/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef ICAMERA_H
#define ICAMERA_H

#include <thread>
#include "dataBuffer.h"
#include "icontrol.h"

// Forward declarations
class Icontrol;
class DataBufferPool;

/**
 * @brief The VCamera class
 *
 * Note: Inheritating is not allowed since starting a thread in the constructor can be problematic for derived classes
 */
class ICamera
{

public:
    ICamera(Icontrol* control, std::shared_ptr<DataBufferPool> dataPool) :
        m_control(control),
        m_playRate(33),
        m_dataPool(dataPool) {};
    virtual ~ICamera() {};

    virtual void startPlayData() = 0;
    virtual void stop() = 0;
    virtual bool isPlaying() = 0;
    void setPlayRate(int playRate) {
        m_playRate = playRate;
    };

    Icontrol* m_control;
    // ------------------------------------------------------------

    int m_playRate;
    std::shared_ptr<DataBufferPool> m_dataPool;
};

#endif // ICAMERA_H
