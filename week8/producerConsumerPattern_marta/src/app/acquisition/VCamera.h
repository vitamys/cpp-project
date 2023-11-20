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
// #include "cameraCb.h"

// Forward declarations : pimpl Idiom (pointers to our implementation)
// class Control; --> build or test our camera without knowing how user its using it
class DataBufferPool;
class CameraCb;

/**
 * @brief The VCamera class
 *
 * Note: Inheritating is not allowed since starting a thread in the constructor can be problematic for derived classes
 */
class VCamera final
{

public:
     VCamera(CameraCb* control, std::shared_ptr<DataBufferPool> dataPool);
     ~VCamera();

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

     // TODO_Done: Remove compile time dependency
     CameraCb* m_control;
     // ------------------------------------------------------------

     int m_playRate;
     std::shared_ptr<DataBufferPool> m_dataPool;
     int offset;
};

#endif // VCAMERA_H
