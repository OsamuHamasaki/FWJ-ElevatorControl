//
// MotorWithLimit.cpp
//

#include "MotorWithLimit.hpp"

void MotorWithLimit::goForward()
{
    switch (state)
    {
    case goingBackward:
        io->motorOff();
    case onBackwardLimit:
        io->motorForwardOn();
        state = goingForward;
        break;
    case onForwardLimit:
        listener->notifyOnForwardLimit();
        break;
    default:
        break;
    }
}

void MotorWithLimit::goBackward()
{
    switch (state)
    {
    case goingForward:
        io->motorOff();
    case onForwardLimit:
        io->motorBackwardOn();
        state = goingBackward;
        break;
    case onBackwardLimit:
        listener->notifyOnBackwardLimit();
        break;
    default:
        break;
    }
}

void MotorWithLimit::tick()
{
    switch(state)
    {
    case goingForward:
        if (io->isOnForwardLimit())
        {
            io->motorOff();
            listener->notifyOnForwardLimit();
            state = onForwardLimit;
        }
        break;
    case goingBackward:
        if (io->isOnBackwardLimit())
        {
            io->motorOff();
            listener->notifyOnBackwardLimit();
            state = onBackwardLimit;
        }
        break;
    default:
        break;
    }
}

