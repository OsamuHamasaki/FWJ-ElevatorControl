//
// Door.cpp
//

#include "Door.hpp"
#include "IO.hpp"

void Door::open()
{
    switch (state)
    {
    case closing:
        IO_doorMotorOff();
    case closed:
        IO_doorMotorForwardOn();
        state = opening;
        break;
    case opened:
        count = waitClosingCount;
        break;
    default:
        break;
    }
}

void Door::tick()
{
    switch(state)
    {
    case closing:
        if (IO_isDoorClose())
        {
            IO_doorMotorOff();
            listener->notifyDoorClosed();
            state = closed;
        }
        break;
    case opening:
        if (IO_isDoorOpen())
        {
            IO_doorMotorOff();
            listener->notifyDoorOpened();
            count = waitClosingCount;
            state = opened;
        }
        break;
    case opened:
        count--;
        if (count == 0)
        {
            IO_doorMotorReverseOn();
            state = closing;
        }
        break;
    default:
        break;
    }
}

