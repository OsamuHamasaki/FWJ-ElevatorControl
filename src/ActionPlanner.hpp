//
// ActionPlanner.hpp
//

#ifndef __ACTIONPLANNER_HPP__
#define __ACTIONPLANNER_HPP__

#include "Door.hpp"
#include "Lift.hpp"

class Request
{
public:
    Request() {}
    virtual ~Request() {}

    virtual void exec() = 0;
    virtual bool isNoRequest() { return false; }
};

class NoRequest : public Request
{
public:
    NoRequest() {}
    virtual ~NoRequest() {}

    void exec() {}
    bool isNoRequest() { return true; }

};

class UpstairRequest : public Request
{
private:
    Lift* lift;

public:
    UpstairRequest(Lift* lift) : lift(lift) {}
    virtual ~UpstairRequest() {}

    void exec() { lift->goUp(); }
};

class DownstairRequest : public Request
{
private:
    Lift* lift;

public:
    DownstairRequest(Lift* lift) : lift(lift) {}
    virtual ~DownstairRequest() {}

    void exec() { lift->goDown(); }
};

class ActionPlanner : public DoorEventListener
{
private:
    NoRequest noRequest;
    UpstairRequest upstairRequest;
    DownstairRequest downstairRequest;

    Request *currentRequest;
    Request *nextRequest;

    void requested(Request* request);

public:
    ActionPlanner(Lift* lift)
        : noRequest(), upstairRequest(lift), downstairRequest(lift),
          currentRequest(&noRequest), nextRequest(&noRequest) {}
    ~ActionPlanner() {}


    void notifyUpstairCallButtonPressed();
    void notifyUpstairRequestButtonPressed();
    void notifyDownstairCallButtonPressed();
    void notifyDownstairRequestButtonPressed();
    
    void notifyDoorClosed();
};

#endif

