#pragma once

#include "State.hpp"
#include "Context.hpp"

#include <string>

class StateMachine
{
public:
    explicit StateMachine(Context& context);

    void update();

    void start();
    void stop();
    void reset();

    State getState() const;

private:
    Context& ctx;

    State currentState;

    void transitionTo(State next);

    const char* stateToString(State state) const;
};