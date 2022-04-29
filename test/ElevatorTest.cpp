#include <gtest/gtest.h>
#include "IO.hpp"
#include "IOforTest.hpp"

class ElevatorControlTest : public ::testing::Test
{
protected:

	virtual void SetUp()
	{
		IO_initialize();
	}

	virtual void TearDown() {}
};

TEST_F(ElevatorControlTest, Initialize)
{
	EXPECT_FALSE(IO_isLiftMotorForwardOn());
	EXPECT_FALSE(IO_isLiftMotorReverseOn());
	EXPECT_FALSE(IO_isDoorMotorForwardOn());
	EXPECT_FALSE(IO_isDoorMotorReverseOn());

    EXPECT_TRUE(IO_isLiftOnDownstair());
    EXPECT_FALSE(IO_isLiftOnUpstair());
    EXPECT_TRUE(IO_isDoorClose());
    EXPECT_FALSE(IO_isDoorOpen());
}

TEST_F(ElevatorControlTest, IO_lift_sensor)
{
	IO_liftOffDownstair();
	EXPECT_FALSE(IO_isLiftOnDownstair());
	IO_liftOnUpstair();
	EXPECT_TRUE(IO_isLiftOnUpstair());
	IO_liftOffUpstair();
	EXPECT_FALSE(IO_isLiftOnUpstair());
	IO_liftOnDownstair();
	EXPECT_TRUE(IO_isLiftOnDownstair());
}

TEST_F(ElevatorControlTest, IO_door_sensor)
{
	IO_doorNotClose();
	EXPECT_FALSE(IO_isDoorClose());
	IO_doorOpen();
	EXPECT_TRUE(IO_isDoorOpen());
	IO_doorNotOpen();
	EXPECT_FALSE(IO_isDoorOpen());
	IO_doorClose();
	EXPECT_TRUE(IO_isDoorClose());
}

TEST_F(ElevatorControlTest, IO_upstairCallButton)
{
	IO_upstairCallButtonOn();
	EXPECT_TRUE(IO_isUpstairCallButtonPressed());

	IO_upstairCallButtonOff();
	EXPECT_FALSE(IO_isUpstairCallButtonPressed());
}

TEST_F(ElevatorControlTest, IO_downstairCallButton)
{
	IO_downstairCallButtonOn();
	EXPECT_TRUE(IO_isDownstairCallButtonPressed());

	IO_downstairCallButtonOff();
	EXPECT_FALSE(IO_isDownstairCallButtonPressed());
}

TEST_F(ElevatorControlTest, IO_upstairRequestButton)
{
	IO_upstairRequestButtonOn();
	EXPECT_TRUE(IO_isUpstairRequestButtonPressed());

	IO_upstairRequestButtonOff();
	EXPECT_FALSE(IO_isUpstairRequestButtonPressed());
}

TEST_F(ElevatorControlTest, IO_downstairRequestButton)
{
	IO_downstairRequestButtonOn();
	EXPECT_TRUE(IO_isDownstairRequestButtonPressed());

	IO_downstairRequestButtonOff();
	EXPECT_FALSE(IO_isDownstairRequestButtonPressed());
}

TEST_F(ElevatorControlTest, IO_lift_motor)
{
	IO_liftMotorForwardOn();
	EXPECT_TRUE(IO_isLiftMotorForwardOn());
	EXPECT_FALSE(IO_isLiftMotorReverseOn());

	IO_liftMotorOff();
	EXPECT_FALSE(IO_isLiftMotorForwardOn());
	EXPECT_FALSE(IO_isLiftMotorReverseOn());

	IO_liftMotorReverseOn();
	EXPECT_FALSE(IO_isLiftMotorForwardOn());
	EXPECT_TRUE(IO_isLiftMotorReverseOn());

	IO_liftMotorOff();
	EXPECT_FALSE(IO_isLiftMotorForwardOn());
	EXPECT_FALSE(IO_isLiftMotorReverseOn());

}

TEST_F(ElevatorControlTest, IO_door_motor)
{
	IO_doorMotorForwardOn();
	EXPECT_TRUE(IO_isDoorMotorForwardOn());
	EXPECT_FALSE(IO_isDoorMotorReverseOn());

	IO_doorMotorOff();
	EXPECT_FALSE(IO_isDoorMotorForwardOn());
	EXPECT_FALSE(IO_isDoorMotorReverseOn());

	IO_doorMotorReverseOn();
	EXPECT_FALSE(IO_isDoorMotorForwardOn());
	EXPECT_TRUE(IO_isDoorMotorReverseOn());

	IO_doorMotorOff();
	EXPECT_FALSE(IO_isDoorMotorForwardOn());
	EXPECT_FALSE(IO_isDoorMotorReverseOn());
}

TEST_F(ElevatorControlTest, IO_upstairCallButtonLamp)
{
	IO_upstairCallButtonLampOn();
	EXPECT_TRUE(IO_isUpstairCallButtonLampOn());

	IO_upstairCallButtonLampOff();
	EXPECT_FALSE(IO_isUpstairCallButtonLampOn());
}

TEST_F(ElevatorControlTest, IO_downstairCallButtonLamp)
{
	IO_downstairCallButtonLampOn();
	EXPECT_TRUE(IO_isDownstairCallButtonLampOn());

	IO_downstairCallButtonLampOff();
	EXPECT_FALSE(IO_isDownstairCallButtonLampOn());
}

TEST_F(ElevatorControlTest, IO_upstairRequestButtonLamp)
{
	IO_upstairRequestButtonLampOn();
	EXPECT_TRUE(IO_isUpstairRequestButtonLampOn());

	IO_upstairRequestButtonLampOff();
	EXPECT_FALSE(IO_isUpstairRequestButtonLampOn());
}

TEST_F(ElevatorControlTest, IO_downstairRequestButtonLamp)
{
	IO_downstairRequestButtonLampOn();
	EXPECT_TRUE(IO_isDownstairRequestButtonLampOn());

	IO_downstairRequestButtonLampOff();
	EXPECT_FALSE(IO_isDownstairRequestButtonLampOn());
}

