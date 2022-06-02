//
// Lift.cpp
//

#include "Lift.hpp"
#include "IO.hpp"

LiftEventNotifier::LiftEventNotifier() : numOfListeners(0)
{
    for (int i = 0; i < sizeof(listeners)/sizeof(LiftEventListener*); i++)
    {
        listeners[i] = 0;
    }
}

void LiftEventNotifier::addEventListener(LiftEventListener* listener)
{
    listeners[numOfListeners] = listener;
    numOfListeners++;
}

void LiftEventNotifier::notifyOnUpstair()
{
    for (int i = 0; i < numOfListeners; i++)
    {
        listeners[i]->notifyLiftOnUpstair();
    }
}

void LiftEventNotifier::notifyOnDownstair()
{
    for (int i = 0; i < numOfListeners; i++)
    {
        listeners[i]->notifyLiftOnDownstair();
    }
}

void Lift::addEventListener(LiftEventListener* listener)
{
    notifier.addEventListener(listener);
}

void Lift::goUp()
{
    switch (state)
    {
    case goingDown:
        IO_liftMotorOff();
    case onDownstair:
        IO_liftMotorForwardOn();
        state = goingUp;
        break;
    case onUpstair:
        notifier.notifyOnUpstair();
        break;
    default:
        break;
    }
}

void Lift::goDown()
{
    switch (state)
    {
    case goingUp:
        IO_liftMotorOff();
    case onUpstair:
        IO_liftMotorReverseOn();
        state = goingDown;
        break;
    case onDownstair:
        notifier.notifyOnDownstair();
        break;
    default:
        break;
    }
}

void Lift::tick()
{
    switch(state)
    {
    case goingUp:
        if (IO_isLiftOnUpstair())
        {
            IO_liftMotorOff();
            notifier.notifyOnUpstair();
            state = onUpstair;
        }
        break;
    case goingDown:
        if (IO_isLiftOnDownstair())
        {
            IO_liftMotorOff();
            notifier.notifyOnDownstair();
            state = onDownstair;
        }
        break;
    default:
        break;
    }
}

