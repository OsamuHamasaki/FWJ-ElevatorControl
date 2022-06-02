//
// ActionPlanner.cpp
//

#include "ActionPlanner.hpp"

void ActionPlanner::requested(Request* request)
{
    if (currentRequest->isNoRequest()
        || currentRequest == request)
    {
        currentRequest = request;
        currentRequest->exec();
    }
    else
    {
        nextRequest = request;
    }
}

void ActionPlanner::notifyDoorClosed()
{
    currentRequest = nextRequest;
    nextRequest = &noRequest;

    currentRequest->exec();
}

