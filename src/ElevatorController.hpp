//
// ElevatorController.hpp
//

#ifndef __ELEVATOR_CONTROLLER_HPP__
#define __ELEVATOR_CONTROLLER_HPP__

#include "Buttons.hpp"
#include "Cage.hpp"

class ElevatorController
{
private:
    UpstairCallButton upstairCallButton;
    UpstairRequestButton upstairRequestButton;
    DownstairCallButton downstairCallButton;
    DownstairRequestButton downstairRequestButton;

    Cage cage;

public:
    ElevatorController()
        : upstairCallButton(&cage), upstairRequestButton(&cage), downstairCallButton(&cage), downstairRequestButton(&cage),
          cage()
        { 
            cage.addRequester(&upstairCallButton);
            cage.addRequester(&upstairRequestButton);
            cage.addRequester(&downstairCallButton);
            cage.addRequester(&downstairRequestButton);
        }
    ~ElevatorController() {}

    void tick();
};

#endif

