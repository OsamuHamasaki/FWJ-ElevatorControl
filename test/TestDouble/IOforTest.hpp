//
// IOforTest.hpp (for Unit test)
//

#ifndef __IOFORTEST_HPP__
#define __IOFORTEST_HPP__

void IO_liftOnUpstair();
void IO_liftOffUpstair();
void IO_liftOnDownstair();
void IO_liftOffDownstair();

void IO_doorOpen();
void IO_doorNotOpen();
void IO_doorClose();
void IO_doorNotClose();

void IO_upstairCallButtonOn();
void IO_upstairCallButtonOff();

void IO_downstairCallButtonOn();
void IO_downstairCallButtonOff();

void IO_upstairRequestButtonOn();
void IO_upstairRequestButtonOff();

void IO_downstairRequestButtonOn();
void IO_downstairRequestButtonOff();

bool IO_isLiftMotorForwardOn();
bool IO_isLiftMotorReverseOn();

bool IO_isDoorMotorForwardOn();
bool IO_isDoorMotorReverseOn();

bool IO_isUpstairCallButtonLampOn();
bool IO_isDownstairCallButtonLampOn();
bool IO_isUpstairRequestButtonLampOn();
bool IO_isDownstairRequestButtonLampOn();

#endif
