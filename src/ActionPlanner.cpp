//
// ActionPlanner.cpp
//

#include "ActionPlanner.hpp"

void ActionPlanner::notifyUpstairCallButtonPressed()
{
    requested(&upstairRequest);
}

void ActionPlanner::notifyUpstairRequestButtonPressed()
{
    requested(&upstairRequest);
}

void ActionPlanner::notifyDownstairCallButtonPressed()
{
    requested(&downstairRequest);
}

void ActionPlanner::notifyDownstairRequestButtonPressed()
{
    requested(&downstairRequest);
}

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

