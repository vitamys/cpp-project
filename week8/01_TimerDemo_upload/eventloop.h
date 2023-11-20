#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include "timerCallback.h"

class EventLoop : public TimerCallback
{
public:
    EventLoop();
    void timerEllapsedCallback() override;
private:
    bool m_event;
};

#endif // EVENTLOOP_H
