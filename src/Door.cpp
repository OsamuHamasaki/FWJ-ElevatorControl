//
// Door.cpp
//

#include "Door.hpp"
#include "IO.hpp"

void Door::open()
{
    if (isOpened)
    {
        count = waitClosingCount;
    }
    else
    {
        motor.goForward();
        isOpened = false;
    }
}

void Door::tick()
{
    if (isOpened)
    {
        count--;
        if (count == 0)
        {
            motor.goBackward();
            isOpened = false;
        }
    }

    motor.tick();
}

