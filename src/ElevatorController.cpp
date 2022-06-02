//
// ElevatorController.cpp
//

#include "ElevatorController.hpp"
#include "Buttons.hpp"
#include "Door.hpp"
#include "Lift.hpp"

void ElevatorController::tick()
{
    upstairCallButton.tick();
    upstairRequestButton.tick();
    downstairCallButton.tick();
    downstairRequestButton.tick();

    door.tick();
    lift.tick();
}

