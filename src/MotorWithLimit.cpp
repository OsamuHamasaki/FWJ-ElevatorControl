//
// MotorWithLimit.cpp
//

#include "MotorWithLimit.hpp"

MotorWithLimit::State* MotorWithLimit::OnForwardLimitState::goForward()
{
    context->listener->notifyOnForwardLimit();
    return this;
}

MotorWithLimit::State* MotorWithLimit::OnForwardLimitState::goBackward()
{
    context->io->motorBackwardOn();
    return &context->goingBackwardState;
}

MotorWithLimit::State* MotorWithLimit::OnBackwardLimitState::goForward()
{
    context->io->motorForwardOn();
    return &context->goingForwardState;
}

MotorWithLimit::State* MotorWithLimit::OnBackwardLimitState::goBackward()
{
    context->listener->notifyOnBackwardLimit();
    return this;
}

MotorWithLimit::State* MotorWithLimit::GoingForwardState::goBackward()
{
    context->io->motorOff();
    context->io->motorBackwardOn();
    return &context->goingBackwardState;
}

MotorWithLimit::State* MotorWithLimit::GoingForwardState::tick()
{
    if (!context->io->isOnForwardLimit()) return this;

    context->io->motorOff();
    context->listener->notifyOnForwardLimit();
    return &context->onForwardLimitState;
}

MotorWithLimit::State* MotorWithLimit::GoingBackwardState::goForward()
{
    context->io->motorOff();
    context->io->motorForwardOn();
    return &context->goingForwardState;
}

MotorWithLimit::State* MotorWithLimit::GoingBackwardState::tick()
{
    if (!context->io->isOnBackwardLimit()) return this;

    context->io->motorOff();
    context->listener->notifyOnBackwardLimit();
    return &context->onBackwardLimitState;
}

void MotorWithLimit::goForward()
{
    state = state->goForward();
}

void MotorWithLimit::goBackward()
{
    state = state->goBackward();
}

void MotorWithLimit::tick()
{
    state = state->tick();
}

