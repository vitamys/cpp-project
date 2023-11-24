/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef VRGBCAMERA_H
#define VRGBCAMERA_H

#include <thread>
#include "dataBuffer.h"
#include "icontrol.h"
#include "ICamera.h"

// Forward declarations
class Icontrol;
class DataBufferPool;

/**
 * @brief The VCamera class
 *
 * Note: Inheritating is not allowed since starting a thread in the constructor can be problematic for derived classes
 */
class VRgbCamera final : public ICamera
{

public:
     VRgbCamera(Icontrol* control, std::shared_ptr<DataBufferPool> dataPool);
     virtual ~VRgbCamera();

     virtual void startPlayData() override;
     virtual void stop() override;
     virtual bool isPlaying() override;

private:
     void run() ;
     bool readImage(DataBufferPtr data);

     std::string m_tag;
     std::thread m_acquireThread;
     bool m_play;

     int offset_r;
     int offset_g;
     int offset_b;
};

#endif // VRGBCAMERA_H
