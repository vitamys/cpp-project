#ifndef TIMER_H
#define TIMER_H

#include <thread>

class Timer
{
public:
    Timer(unsigned period_MS);
    ~Timer();

    void start(unsigned period_MS);

private:
    bool m_doRun;
    std::thread m_timerThread;

};

#endif // TIMER_H
