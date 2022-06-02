//
// Lift.hpp
//

#ifndef __Lift_HPP__
#define __Lift_HPP__

#include "MotorWithLimit.hpp"
#include "IO.hpp"

class LiftEventListener
{
public:
    LiftEventListener() {}
    virtual ~LiftEventListener() {}

    virtual void notifyLiftOnUpstair() {}
    virtual void notifyLiftOnDownstair() {}
};

class LiftEventNotifier
{
private:
    int numOfListeners;
    LiftEventListener* listeners[5];
    
public:
    LiftEventNotifier();
    ~LiftEventNotifier() {}

    void addEventListener(LiftEventListener* listener);

    void notifyOnUpstair();
    void notifyOnDownstair();
};

class LiftIO : public MotorWithLimitIO
{
public:
    LiftIO() : MotorWithLimitIO() {}
    virtual ~LiftIO() {}

    void motorOff() { IO_liftMotorOff(); }
    void motorForwardOn() { IO_liftMotorForwardOn(); }
    void motorBackwardOn() { IO_liftMotorReverseOn(); }
    bool isOnForwardLimit() { return IO_isLiftOnUpstair(); }
    bool isOnBackwardLimit() { return IO_isLiftOnDownstair(); }
};

class Lift : public MotorEventListener
{
private:
    LiftEventNotifier notifier;
    LiftIO io;
    MotorWithLimit motor;

    void notifyOnForwardLimit() { notifier.notifyOnUpstair(); }
    void notifyOnBackwardLimit() { notifier.notifyOnDownstair(); }

public:
    Lift() : MotorEventListener(), notifier(), io(), motor(this, &io) {}
    ~Lift() {}

    void addEventListener(LiftEventListener* listener) { notifier.addEventListener(listener); }
    
    void goUp() { motor.goForward(); }
    void goDown() { motor.goBackward(); }
    void tick() { motor.tick(); }
};

#endif

