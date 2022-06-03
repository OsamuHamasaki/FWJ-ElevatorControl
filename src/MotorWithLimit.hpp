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

    class State {
    public:
        State() {}
        virtual ~State() {}

        virtual State* goForward() { return this; }
        virtual State* goBackward() { return this; }
        virtual State* tick() { return this; }
    };

    class OnForwardLimitState : public State
    {
    private:
        MotorWithLimit* context;

    public:
        OnForwardLimitState(MotorWithLimit* context) : context(context) {}
        virtual ~OnForwardLimitState() {}

        State* goForward();
        State* goBackward();
    } onForwardLimitState;

    class OnBackwardLimitState : public State
    {
    private:
        MotorWithLimit* context;

    public:
        OnBackwardLimitState(MotorWithLimit* context) : context(context) {}
        virtual ~OnBackwardLimitState() {}

        State* goForward();
        State* goBackward();
    } onBackwardLimitState;

    class GoingForwardState : public State
    {
    private:
        MotorWithLimit* context;

    public:
        GoingForwardState(MotorWithLimit* context) : context(context) {}
        virtual ~GoingForwardState() {}

        State* goBackward();
        State* tick();
    } goingForwardState;

    class GoingBackwardState : public State
    {
    private:
        MotorWithLimit* context;

    public:
        GoingBackwardState(MotorWithLimit* context) : context(context) {}
        virtual ~GoingBackwardState() {}

        State* goForward();
        State* tick();
    } goingBackwardState;

    State* state;

public:
    MotorWithLimit(MotorEventListener* listener, MotorWithLimitIO* io) : listener(listener), io(io), onForwardLimitState(this), onBackwardLimitState(this), goingForwardState(this), goingBackwardState(this), state(&onBackwardLimitState) {}
    ~MotorWithLimit() {}

    
    void goForward();
    void goBackward();
    void tick();
};

#endif

