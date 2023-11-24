#include "timer.h"
#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

Timer::Timer(unsigned period_MS): m_doRun(true)
{
    m_timerThread = std::thread(&Timer::start, this, period_MS);
}

Timer::~Timer()
{
    m_doRun = false;
    if(m_timerThread.joinable())
        m_timerThread.join();
}

void Timer::start(unsigned period_MS)
{
    unsigned count{0};

    while (m_doRun)
    {
        if(count < period_MS)
        {
            count++;
            this_thread::sleep_for(1ms);
        }
        else
        {
            count=0;
            // Event Callback
        }
    }
}

