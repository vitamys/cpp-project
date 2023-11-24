/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef RGBCamera_H
#define RGBCamera_H

#include <thread>
#include "dataBuffer.h"
#include "iBaseCamera.h" //factory method

// Forward declarations
class ICamera;
class DataBufferPool;

/**
 * @brief The RGBCamera class
 *
 * Note: Inheritating is not allowed since starting a thread in the constructor can be problematic for derived classes
 */
class RGBCamera final : public IBaseCamera
{

public:
     RGBCamera(ICamera* control, std::shared_ptr<DataBufferPool> dataPool);
     ~RGBCamera();

     void startPlayData();
     void stop();
     bool isPlaying();
     void setPlayRate(int playRate);

private:
     void run() ;
     bool readImage(DataBufferPtr data);

     std::string m_tag;
     std::thread m_acquireThread;
     bool m_play;

     // TODO: Remove compile time dependency
     ICamera* m_control;
     // ------------------------------------------------------------

     int m_playRate;
     std::shared_ptr<DataBufferPool> m_dataPool;

     int offset;

};

#endif // RGBCamera_H
