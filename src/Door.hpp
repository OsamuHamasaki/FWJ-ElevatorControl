//
// Door.hpp
//

#ifndef __DOOR_HPP__
#define __DOOR_HPP__

#include "Lift.hpp"

class DoorEventListener
{
public:
    DoorEventListener() {}
    virtual ~DoorEventListener() {}

    virtual void notifyDoorOpened() {};
    virtual void notifyDoorClosed() {};
};

class Door : public LiftEventListener
{
private:
    DoorEventListener* listener;
    enum
    {
        closed,
        opened,
        closing,
        opening
    } state;
    int count;

    static const int waitClosingCount = 300;

    void open();

public:
    Door(DoorEventListener* listener) : listener(listener), state(closed), count(0) {}
    ~Door() {}

    void tick();

    virtual void notifyLiftOnUpstair() { open(); }
    virtual void notifyLiftOnDownstair() { open(); }
};

#endif

