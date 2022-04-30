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
    int state;

    static const int onDownstair = 0;
    static const int onUpstair = 1;
    static const int goingDown = 2;
    static const int goingUp = 3;

public:
    Lift(LiftEventListener* listener) : listener(listener), state(onDownstair) {}
    ~Lift() {}

    void goUp();
    void goDown();
    void tick();
};

#endif

