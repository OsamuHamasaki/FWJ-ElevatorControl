//
// Lift.cpp
//

#include "Lift.hpp"
#include "IO.hpp"

void Lift::goUp()
{
    switch (state)
    {
    case goingDown:
        IO_liftMotorOff();
    case onDownstair:
        IO_liftMotorForwardOn();
        state = goingUp;
        break;
    case onUpstair:
        listener->notifyLiftOnUpstair();
        break;
    }
}

void Lift::goDown()
{
    switch (state)
    {
    case goingUp:
        IO_liftMotorOff();
    case onUpstair:
        IO_liftMotorReverseOn();
        state = goingDown;
        break;
    case onDownstair:
        listener->notifyLiftOnDownstair();
        break;
    }
}

void Lift::tick()
{
    switch(state)
    {
    case goingUp:
        if (IO_isLiftOnUpstair())
        {
            IO_liftMotorOff();
            listener->notifyLiftOnUpstair();
            state = onUpstair;
        }
        break;
    case goingDown:
        if (IO_isLiftOnDownstair())
        {
            IO_liftMotorOff();
            listener->notifyLiftOnDownstair();
            state = onDownstair;
        }
        break;
    }
}

