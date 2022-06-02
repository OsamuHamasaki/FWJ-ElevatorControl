//
// Buttons.hpp
//

#ifndef __BUTTONS_HPP__
#define __BUTTONS_HPP__

#include "Button.hpp"
#include "ActionPlanner.hpp"
#include "IO.hpp"

class UpstairCallButton : public Button, public LiftEventListener
{
private:
    ActionPlanner* actionPlanner;

    bool isOn() { return IO_isUpstairCallButtonPressed(); }
    void onPressed() { IO_upstairCallButtonLampOn(); actionPlanner->notifyUpstairCallButtonPressed(); }

public:
    UpstairCallButton(ActionPlanner* actionPlanner) : actionPlanner(actionPlanner) {}
    virtual ~UpstairCallButton() {}

    void notifyLiftOnUpstair() { IO_upstairCallButtonLampOff(); }
};

class UpstairRequestButton : public Button, public LiftEventListener
{
private:
    ActionPlanner* actionPlanner;

    bool isOn() { return IO_isUpstairRequestButtonPressed(); }
    void onPressed() { IO_upstairRequestButtonLampOn(); actionPlanner->notifyUpstairRequestButtonPressed(); }

public:
    UpstairRequestButton(ActionPlanner* actionPlanner) : actionPlanner(actionPlanner) {}
    virtual ~UpstairRequestButton() {}

    void notifyLiftOnUpstair() { IO_upstairRequestButtonLampOff(); }
};

class DownstairCallButton : public Button, public LiftEventListener
{
private:
    ActionPlanner* actionPlanner;

    bool isOn() { return IO_isDownstairCallButtonPressed(); }
    void onPressed() {  IO_downstairCallButtonLampOn(); actionPlanner->notifyDownstairCallButtonPressed(); }

public:
    DownstairCallButton(ActionPlanner* actionPlanner) : actionPlanner(actionPlanner) {}
    virtual ~DownstairCallButton() {}

    void notifyLiftOnDownstair() { IO_downstairCallButtonLampOff(); }
};

class DownstairRequestButton : public Button, public LiftEventListener
{
private:
    ActionPlanner* actionPlanner;

    bool isOn() { return IO_isDownstairRequestButtonPressed(); }
    void onPressed() {  IO_downstairRequestButtonLampOn(); actionPlanner->notifyDownstairRequestButtonPressed(); }

public:
    DownstairRequestButton(ActionPlanner* actionPlanner) : actionPlanner(actionPlanner) {}
    virtual ~DownstairRequestButton() {}

    void notifyLiftOnDownstair() { IO_downstairRequestButtonLampOff(); }
};


#endif

