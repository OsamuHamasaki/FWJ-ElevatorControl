//
// Door.hpp
//

#ifndef __DOOR_HPP__
#define __DOOR_HPP__

#include "Lift.hpp"
#include "MotorWithLimit.hpp"

class DoorEventListener
{
public:
    DoorEventListener() {}
    virtual ~DoorEventListener() {}

    virtual void notifyDoorOpened() {};
    virtual void notifyDoorClosed() {};
};

class DoorIO : public MotorWithLimitIO
{
public:
    DoorIO() : MotorWithLimitIO() {}
    ~DoorIO() {}

    void motorOff() { IO_doorMotorOff(); }
    void motorForwardOn() { IO_doorMotorForwardOn(); }
    void motorBackwardOn() { IO_doorMotorReverseOn(); }
    bool isOnForwardLimit() { return IO_isDoorOpen(); }
    bool isOnBackwardLimit() { return IO_isDoorClose(); }
};

class Door : public LiftEventListener, public MotorEventListener
{
private:
    DoorEventListener* listener;
    bool isOpened;
    int count;

    DoorIO io;
    MotorWithLimit motor;

    static const int waitClosingCount = 300;

    void open();
    void notifyOnForwardLimit() { listener->notifyDoorOpened(); isOpened = true; count = waitClosingCount; }
    void notifyOnBackwardLimit() { listener->notifyDoorClosed(); }

public:
    Door(DoorEventListener* listener) 
        : LiftEventListener(), MotorEventListener(), listener(listener),
          isOpened(false), count(0), io(), motor(this, &io) {}
    ~Door() {}

    void tick();

    virtual void notifyLiftOnUpstair() { open(); }
    virtual void notifyLiftOnDownstair() { open(); }
};

#endif

