//
// Cage.cpp
//

#include "Cage.hpp"
#include "IO.hpp"

CageEventNotifier::CageEventNotifier() : numOfListeners(0)
{
    for (int i = 0; i < sizeof(listeners)/sizeof(CageEventListener*); i++)
    {
        listeners[i] = 0;
    }
}

void CageEventNotifier::addEventListener(CageEventListener* listener)
{
    listeners[numOfListeners] = listener;
    numOfListeners++;
}

void CageEventNotifier::notifyOnUpstair()
{
    for (int i = 0; i < numOfListeners; i++)
    {
        listeners[i]->notifyOnUpstair();
    }
}

void CageEventNotifier::notifyOnDownstair()
{
    for (int i = 0; i < numOfListeners; i++)
    {
        listeners[i]->notifyOnDownstair();
    }
}

void Cage::addEventListener(CageEventListener* listener)
{
    notifier.addEventListener(listener);
}

void Cage::notifyUpstairCallButtonPressed()
{
    requested(&upstairRequest);
}

void Cage::notifyUpstairRequestButtonPressed()
{
    requested(&upstairRequest);
}

void Cage::notifyDownstairCallButtonPressed()
{
    requested(&downstairRequest);
}

void Cage::notifyDownstairRequestButtonPressed()
{
    requested(&downstairRequest);
}

void Cage::requested(Request* request)
{
    if (currentRequest->isNoRequest()
        || currentRequest == request)
    {
        currentRequest = request;
        currentRequest->exec(&lift);
    }
    else
    {
        nextRequest = request;
    }
}

void Cage::notifyDoorOpened()
{
}

void Cage::notifyDoorClosed()
{
    currentRequest = nextRequest;
    nextRequest = &noRequest;

    currentRequest->exec(&lift);
}

void Cage::notifyLiftOnUpstair()
{
    notifier.notifyOnUpstair();
    door.open();
}

void Cage::notifyLiftOnDownstair()
{
    notifier.notifyOnDownstair();
    door.open();
}

void Cage::tick()
{
    door.tick();
    lift.tick();
}

