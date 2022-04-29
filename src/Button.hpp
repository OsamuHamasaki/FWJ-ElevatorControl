//
// Button.hpp
//

#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

class Button
{
private:
    bool isOnPrevious;

    virtual bool isOn() = 0;
    virtual void onPressed() = 0;

public:
    Button() : isOnPrevious(false) {};
    virtual ~Button() {}

    void tick();
};

#endif

