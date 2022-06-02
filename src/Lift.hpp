//
// Lift.hpp
//

#ifndef __Lift_HPP__
#define __Lift_HPP__

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

class Lift
{
private:
    LiftEventNotifier notifier;

    enum
    {
        onDownstair,
        onUpstair,
        goingDown,
        goingUp
    } state;

public:
    Lift() : notifier(), state(onDownstair) {}
    ~Lift() {}

    void addEventListener(LiftEventListener* listener);
    
    void goUp();
    void goDown();
    void tick();
};

#endif

