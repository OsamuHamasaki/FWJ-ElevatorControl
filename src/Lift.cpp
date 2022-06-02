//
// Lift.cpp
//

#include "Lift.hpp"

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

