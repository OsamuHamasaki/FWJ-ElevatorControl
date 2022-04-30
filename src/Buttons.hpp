//
// Buttons.hpp
//

#ifndef __BUTTONS_HPP__
#define __BUTTONS_HPP__

#include "Button.hpp"
#include "Cage.hpp"
#include "IO.hpp"

class UpstairCallButton : public Button, public CageEventListener
{
private:
    Cage* cage;

    bool isOn() { return IO_isUpstairCallButtonPressed(); }
    void onPressed() { IO_upstairCallButtonLampOn(); cage->notifyUpstairCallButtonPressed(); }

public:
    UpstairCallButton(Cage* cage) : cage(cage) {}
    virtual ~UpstairCallButton() {}

    void notifyOnUpstair() { IO_upstairCallButtonLampOff(); }
};

class UpstairRequestButton : public Button, public CageEventListener
{
private:
    Cage* cage;

    bool isOn() { return IO_isUpstairRequestButtonPressed(); }
    void onPressed() { IO_upstairRequestButtonLampOn(); cage->notifyUpstairRequestButtonPressed(); }

public:
    UpstairRequestButton(Cage* cage) : cage(cage) {}
    virtual ~UpstairRequestButton() {}

    void notifyOnUpstair() { IO_upstairRequestButtonLampOff(); }
};

class DownstairCallButton : public Button, public CageEventListener
{
private:
    Cage* cage;

    bool isOn() { return IO_isDownstairCallButtonPressed(); }
    void onPressed() {  IO_downstairCallButtonLampOn(); cage->notifyDownstairCallButtonPressed(); }

public:
    DownstairCallButton(Cage* cage) : cage(cage) {}
    virtual ~DownstairCallButton() {}

    void notifyOnDownstair() { IO_downstairCallButtonLampOff(); }
};

class DownstairRequestButton : public Button, public CageEventListener
{
private:
    Cage* cage;

    bool isOn() { return IO_isDownstairRequestButtonPressed(); }
    void onPressed() {  IO_downstairRequestButtonLampOn(); cage->notifyDownstairRequestButtonPressed(); }

public:
    DownstairRequestButton(Cage* cage) : cage(cage) {}
    virtual ~DownstairRequestButton() {}

    void notifyOnDownstair() { IO_downstairRequestButtonLampOff(); }
};


#endif

