#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include "timerCallback.h"

class Timer
{
public:
    Timer(TimerCallback* host,  unsigned period_MS);
    ~Timer();

    void start(unsigned period_MS);

private:
    TimerCallback* m_host;
    bool m_doRun;
    std::thread m_timerThread;

};

#endif // TIMER_H
