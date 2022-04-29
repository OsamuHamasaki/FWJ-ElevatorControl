//
// IO.hpp
//

#ifndef __IO_HPP__
#define __IO_HPP__

bool IO_initialize();
void IO_finalize();
void IO_tick();

void IO_liftMotorForwardOn();
void IO_liftMotorReverseOn();
void IO_liftMotorOff();
bool IO_isLiftOnUpstair();
bool IO_isLiftOnDownstair();

void IO_doorMotorForwardOn();
void IO_doorMotorReverseOn();
void IO_doorMotorOff();
bool IO_isDoorOpen();
bool IO_isDoorClose();

bool IO_isUpstairCallButtonPressed();
void IO_upstairCallButtonLampOn();
void IO_upstairCallButtonLampOff();

bool IO_isDownstairCallButtonPressed();
void IO_downstairCallButtonLampOn();
void IO_downstairCallButtonLampOff();

bool IO_isUpstairRequestButtonPressed();
void IO_upstairRequestButtonLampOn();
void IO_upstairRequestButtonLampOff();

bool IO_isDownstairRequestButtonPressed();
void IO_downstairRequestButtonLampOn();
void IO_downstairRequestButtonLampOff();

#endif

