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
            cage.addEventListener(&upstairCallButton);
            cage.addEventListener(&upstairRequestButton);
            cage.addEventListener(&downstairCallButton);
            cage.addEventListener(&downstairRequestButton);
        }
    ~ElevatorController() {}

    void tick();
};

#endif

