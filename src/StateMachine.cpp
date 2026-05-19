#include "StateMachine.hpp"

#include <iostream>

StateMachine::StateMachine(Context& context)
    : ctx(context),
      currentState(State::Idle)
{
}

void StateMachine::update()
{
    // Global fault handling
    if (ctx.faultActive &&
        currentState != State::Fault)
    {
        transitionTo(State::Fault);
        return;
    }

    switch (currentState)
    {
        case State::Priming:
        {
            if (ctx.pressure > 20.0)
            {
                transitionTo(State::Running);
            }

            break;
        }

        case State::Fault:
        {
            if (!ctx.faultActive)
            {
                transitionTo(State::Idle);
            }

            break;
        }

        default:
            break;
    }
}

void StateMachine::start()
{
    if (currentState == State::Idle)
    {
        transitionTo(State::Priming);
    }
    else
    {
        std::cout
            << "Cannot start from current state\n";
    }
}

void StateMachine::stop()
{
    if (currentState == State::Running)
    {
        transitionTo(State::Shutdown);
    }
    else
    {
        std::cout
            << "Cannot stop from current state\n";
    }
}

void StateMachine::reset()
{
    if (currentState == State::Shutdown)
    {
        transitionTo(State::Idle);
    }
    else
    {
        std::cout
            << "Cannot reset from current state\n";
    }
}

State StateMachine::getState() const
{
    return currentState;
}

void StateMachine::transitionTo(State next)
{
    std::cout
        << "Transition: "
        << stateToString(currentState)
        << " -> "
        << stateToString(next)
        << "\n";

    currentState = next;
}

const char* StateMachine::stateToString(
    State state) const
{
    switch (state)
    {
        case State::Idle:
            return "Idle";

        case State::Priming:
            return "Priming";

        case State::Running:
            return "Running";

        case State::Fault:
            return "Fault";

        case State::Shutdown:
            return "Shutdown";

        default:
            return "Unknown";
    }
}