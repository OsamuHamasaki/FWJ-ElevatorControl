//
// MotorWithLimit.hpp
//

#ifndef __MOTORWITHLIMIT_HPP__
#define __MOTORWITHLIMIT_HPP__

class MotorEventListener
{
public:
    MotorEventListener() {}
    virtual ~MotorEventListener() {}

    virtual void notifyOnForwardLimit() {}
    virtual void notifyOnBackwardLimit() {}
};

class MotorWithLimitIO
{
private:
public:
    MotorWithLimitIO() {}
    virtual ~MotorWithLimitIO() {}

    virtual void motorOff() = 0;
    virtual void motorForwardOn() = 0;
    virtual void motorBackwardOn() = 0;
    virtual bool isOnForwardLimit() = 0;
    virtual bool isOnBackwardLimit() = 0;
};

class MotorWithLimit 
{
private:
    MotorEventListener* listener;
    MotorWithLimitIO* io;

    enum
    {
        onForwardLimit,
        onBackwardLimit,
        goingForward,
        goingBackward
    } state;

public:
    MotorWithLimit(MotorEventListener* listener, MotorWithLimitIO* io) : listener(listener), io(io), state(onBackwardLimit) {}
    ~MotorWithLimit() {}

    
    void goForward();
    void goBackward();
    void tick();
};

#endif

