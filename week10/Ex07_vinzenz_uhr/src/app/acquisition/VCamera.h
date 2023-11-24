/****************************************************************************
** Copyright (c) 2018 HuCE-optoLab - Bern University of Applied Science
** Project: Example of a producer-comsumer-pattern
**
** Contact:    Patrik Arnold ( patrik.arnold@bfh.ch )
*****************************************************************************/
#ifndef VCAMERA_H
#define VCAMERA_H

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
class VCamera final : public ICamera
{

public:
     VCamera(Icontrol* control, std::shared_ptr<DataBufferPool> dataPool);
     virtual ~VCamera();

     virtual void startPlayData() override;
     virtual void stop() override;
     virtual bool isPlaying() override;

private:
     void run() ;
     bool readImage(DataBufferPtr data);

     std::string m_tag;
     std::thread m_acquireThread;
     bool m_play;

     int offset;
};

#endif // VCAMERA_H
