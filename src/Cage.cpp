//
// Cage.cpp
//

#include "Cage.hpp"
#include "IO.hpp"

CageRequesterList::CageRequesterList() : numOfRequester(0)
{
    for (int i = 0; i < sizeof(requesters)/sizeof(CageRequester*); i++)
    {
        requesters[i] = 0;
    }
}

void CageRequesterList::addRequester(CageRequester* requester)
{
    requesters[numOfRequester] = requester;
    numOfRequester++;
}

void CageRequesterList::notifyOnUpstair()
{
    for (int i = 0; i < numOfRequester; i++)
    {
        requesters[i]->notifyOnUpstair();
    }
}

void CageRequesterList::notifyOnDownstair()
{
    for (int i = 0; i < numOfRequester; i++)
    {
        requesters[i]->notifyOnDownstair();
    }
}

void Cage::addRequester(CageRequester* requester)
{
    requesters.addRequester(requester);
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
    requesters.notifyOnUpstair();
    door.open();
}

void Cage::notifyLiftOnDownstair()
{
    requesters.notifyOnDownstair();
    door.open();
}

void Cage::tick()
{
    door.tick();
    lift.tick();
}

