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

    virtual void notifyLiftOnUpstair() {};
    virtual void notifyLiftOnDownstair() {};
};

class Lift
{
private:
    LiftEventListener* listener;
    enum
    {
        onDownstair,
        onUpstair,
        goingDown,
        goingUp
    } state;

public:
    Lift(LiftEventListener* listener) : listener(listener), state(onDownstair) {}
    ~Lift() {}

    void goUp();
    void goDown();
    void tick();
};

#endif

