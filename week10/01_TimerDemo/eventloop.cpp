#include "eventloop.h"
#include "timer.h"
#include <iostream>
EventLoop::EventLoop():m_event(false)
{



    while(true)
    {
        if(m_event)
        {
            m_event = false;
            std::cout << " Every Second Event!" << std::endl;
        }
    };
}

