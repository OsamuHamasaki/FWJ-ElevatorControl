//
// Button.cpp
//

#include "Button.hpp"

void Button::tick()
{
    bool isOnNow = isOn();

    if (!isOnPrevious && isOnNow)
    {
        onPressed();
    }

    isOnPrevious = isOnNow;
}

