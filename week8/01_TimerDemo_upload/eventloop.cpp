#include "eventloop.h"
#include "timer.h"
#include <iostream>
EventLoop::EventLoop():m_event(false)
{

    Timer t(this, 1000);

    while(true)
    {
        if(m_event)
        {
            m_event = false;
            std::cout << " Every Second Event!" << std::endl;
        }
    };
}

void EventLoop::timerEllapsedCallback()
{
    m_event = true;
}

