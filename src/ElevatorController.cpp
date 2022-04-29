//
// ElevatorController.cpp
//

#include "ElevatorController.hpp"
#include "Buttons.hpp"

void ElevatorController::tick()
{
    upstairCallButton.tick();
    upstairRequestButton.tick();
    downstairCallButton.tick();
    downstairRequestButton.tick();

    cage.tick();
}

