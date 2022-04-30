//
// Cage.hpp
//

#ifndef __CAGE_HPP__
#define __CAGE_HPP__

#include "Door.hpp"
#include "Lift.hpp"

class CageEventListener
{
public:
    CageEventListener() {}
    virtual ~CageEventListener() {}

    virtual void notifyOnUpstair() {};
    virtual void notifyOnDownstair() {};
};

class CageEventNotifier
{
private:
    int numOfListeners;
    CageEventListener* listeners[4];
    
public:
    CageEventNotifier();
    ~CageEventNotifier() {}

    void addEventListener(CageEventListener* listener);

    void notifyOnUpstair();
    void notifyOnDownstair();
};

class Request
{
public:
    Request() {}
    virtual ~Request() {}

    virtual void exec(Lift* lift) = 0;
    virtual bool isNoRequest() { return false; }
};

class NoRequest : public Request
{
public:
    NoRequest() {}
    virtual ~NoRequest() {}

    void exec(Lift* lift) {}
    bool isNoRequest() { return true; }

};

class UpstairRequest : public Request
{
private:
    Lift* lift;

public:
    UpstairRequest(Lift* lift) : lift(lift) {}
    virtual ~UpstairRequest() {}

    void exec(Lift* lift) { lift->goUp(); }
};

class DownstairRequest : public Request
{
private:
    Lift* lift;

public:
    DownstairRequest(Lift* lift) : lift(lift) {}
    virtual ~DownstairRequest() {}

    void exec(Lift* lift) { lift->goDown(); }
};

class Cage : public DoorEventListener, public LiftEventListener
{
private:
    Door door;
    Lift lift;
    CageEventNotifier notifier;

    NoRequest noRequest;
    UpstairRequest upstairRequest;
    DownstairRequest downstairRequest;

    Request *currentRequest;
    Request *nextRequest;

    void requested(Request* request);
    void moveLift();

public:
    Cage()
        : door(this), lift(this), notifier(),
          noRequest(), upstairRequest(&lift), downstairRequest(&lift),
          currentRequest(&noRequest), nextRequest(&noRequest) {}
    ~Cage() {}

    void addEventListener(CageEventListener* listener);

    void notifyUpstairCallButtonPressed();
    void notifyUpstairRequestButtonPressed();
    void notifyDownstairCallButtonPressed();
    void notifyDownstairRequestButtonPressed();
    
    void notifyDoorClosed();
    void notifyDoorOpened();

    void notifyLiftOnUpstair();
    void notifyLiftOnDownstair();

    void tick();
};

#endif

