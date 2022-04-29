//
// IO.cpp (for Unit test)
//

#include "IO.hpp"
#include "IOforTest.hpp"

bool isLiftMotorForwardOn = false;
bool isLiftMotorReverseOn = false;
bool isDoorMotorForwardOn = false;
bool isDoorMotorReverseOn = false;

bool isLiftOnUpstair = false;
bool isLiftOnDownstair = false;
bool isDoorOpen = false;
bool isDoorClose = false;

bool isUpstairCallButtonPressed = false;
bool isUpstairCallButtonLampOn = false;

bool isDownstairCallButtonPressed = false;
bool isDownstairCallButtonLampOn = false;

bool isUpstairRequestButtonPressed = false;
bool isUpstairRequestButtonLampOn = false;

bool isDownstairRequestButtonPressed = false;
bool isDownstairRequestButtonLampOn = false;

bool IO_initialize()
{
	isLiftMotorForwardOn = false;
	isLiftMotorReverseOn = false;
	isDoorMotorForwardOn = false;
	isDoorMotorReverseOn = false;

	isLiftOnUpstair = false;
	isLiftOnDownstair = true;
	isDoorOpen = false;
	isDoorClose = true;

	isUpstairCallButtonPressed = false;
	isUpstairCallButtonLampOn = false;

	isDownstairCallButtonPressed = false;
	isDownstairCallButtonLampOn = false;

	isUpstairRequestButtonPressed = false;
	isUpstairRequestButtonLampOn = false;

	isDownstairRequestButtonPressed = false;
	isDownstairRequestButtonLampOn = false;

    return true;
}

void IO_finalize()
{
    // do nothing
}

void IO_liftMotorForwardOn()
{
	isLiftMotorForwardOn = true;
	isLiftMotorReverseOn = false;
}

void IO_liftMotorReverseOn()
{
	isLiftMotorForwardOn = false;
	isLiftMotorReverseOn = true;
}

void IO_liftMotorOff()
{
	isLiftMotorForwardOn = false;
	isLiftMotorReverseOn = false;
}

bool IO_isLiftOnUpstair()
{
	return isLiftOnUpstair;
}

bool IO_isLiftOnDownstair()
{
	return isLiftOnDownstair;
}

void IO_doorMotorForwardOn()
{
	isDoorMotorForwardOn = true;
	isDoorMotorReverseOn = false;
}

void IO_doorMotorReverseOn()
{
	isDoorMotorForwardOn = false;
	isDoorMotorReverseOn = true;
}

void IO_doorMotorOff()
{
	isDoorMotorForwardOn = false;
	isDoorMotorReverseOn = false;
}

bool IO_isDoorOpen()
{
	return isDoorOpen;
}

bool IO_isDoorClose()
{
	return isDoorClose;
}

bool IO_isUpstairCallButtonPressed()
{
	return isUpstairCallButtonPressed;
}

void IO_upstairCallButtonLampOn()
{
	isUpstairCallButtonLampOn = true;
}

void IO_upstairCallButtonLampOff()
{
	isUpstairCallButtonLampOn = false;
}

bool IO_isDownstairCallButtonPressed()
{
	return isDownstairCallButtonPressed;
}

void IO_downstairCallButtonLampOn()
{
	isDownstairCallButtonLampOn = true;
}

void IO_downstairCallButtonLampOff()
{
	isDownstairCallButtonLampOn = false;
}

bool IO_isUpstairRequestButtonPressed()
{
	return isUpstairRequestButtonPressed;
}

void IO_upstairRequestButtonLampOn()
{
	isUpstairRequestButtonLampOn = true;
}

void IO_upstairRequestButtonLampOff()
{
	isUpstairRequestButtonLampOn = false;
}

bool IO_isDownstairRequestButtonPressed()
{
	return isDownstairRequestButtonPressed;
}

void IO_downstairRequestButtonLampOn()
{
	isDownstairRequestButtonLampOn = true;
}

void IO_downstairRequestButtonLampOff()
{
	isDownstairRequestButtonLampOn = false;
}

void IO_liftOnUpstair()
{
	isLiftOnUpstair = true;
}

void IO_liftOffUpstair()
{
	isLiftOnUpstair = false;
}

void IO_liftOnDownstair()
{
	isLiftOnDownstair = true;
}

void IO_liftOffDownstair()
{
	isLiftOnDownstair = false;
}

void IO_doorOpen()
{
	isDoorOpen = true;
}

void IO_doorNotOpen()
{
	isDoorOpen = false;
}

void IO_doorClose()
{
	isDoorClose = true;
}

void IO_doorNotClose()
{
	isDoorClose = false;
}

void IO_upstairCallButtonOn()
{
	isUpstairCallButtonPressed = true;
}

void IO_upstairCallButtonOff()
{
	isUpstairCallButtonPressed = false;
}

void IO_downstairCallButtonOn()
{
	isDownstairCallButtonPressed = true;
}

void IO_downstairCallButtonOff()
{
	isDownstairCallButtonPressed = false;
}

void IO_upstairRequestButtonOn()
{
	isUpstairRequestButtonPressed = true;
}

void IO_upstairRequestButtonOff()
{
	isUpstairRequestButtonPressed = false;
}

void IO_downstairRequestButtonOn()
{
	isDownstairRequestButtonPressed = true;
}

void IO_downstairRequestButtonOff()
{
	isDownstairRequestButtonPressed = false;
}

bool IO_isLiftMotorForwardOn()
{
	return isLiftMotorForwardOn;
}

bool IO_isLiftMotorReverseOn()
{
	return isLiftMotorReverseOn;
}

bool IO_isDoorMotorForwardOn()
{
	return isDoorMotorForwardOn;
}

bool IO_isDoorMotorReverseOn()
{
	return isDoorMotorReverseOn;
}

bool IO_isUpstairCallButtonLampOn()
{
	return isUpstairCallButtonLampOn;
}

bool IO_isDownstairCallButtonLampOn()
{
	return isDownstairCallButtonLampOn;
}

bool IO_isUpstairRequestButtonLampOn()
{
	return isUpstairRequestButtonLampOn;
}

bool IO_isDownstairRequestButtonLampOn()
{
	return isDownstairRequestButtonLampOn;
}


