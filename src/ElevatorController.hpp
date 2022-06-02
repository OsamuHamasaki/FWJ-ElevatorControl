//
// ElevatorController.hpp
//

#ifndef __ELEVATOR_CONTROLLER_HPP__
#define __ELEVATOR_CONTROLLER_HPP__

#include "Buttons.hpp"
#include "Lift.hpp"
#include "Door.hpp"
#include "ActionPlanner.hpp"

class ElevatorController
{
private:
    UpstairCallButton upstairCallButton;
    UpstairRequestButton upstairRequestButton;
    DownstairCallButton downstairCallButton;
    DownstairRequestButton downstairRequestButton;

    Door door;
    Lift lift;

    ActionPlanner actionPlanner;

public:
    ElevatorController()
        : upstairCallButton(&actionPlanner), upstairRequestButton(&actionPlanner),
          downstairCallButton(&actionPlanner), downstairRequestButton(&actionPlanner),
          door(&actionPlanner), lift(), actionPlanner(&lift)
        { 
            lift.addEventListener(&upstairCallButton);
            lift.addEventListener(&upstairRequestButton);
            lift.addEventListener(&downstairCallButton);
            lift.addEventListener(&downstairRequestButton);
            lift.addEventListener(&door);
        }
    ~ElevatorController() {}

    void tick();
};

#endif

