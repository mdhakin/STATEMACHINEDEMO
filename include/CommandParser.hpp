#pragma once

#include "StateMachine.hpp"

#include <string>

class CommandParser
{
public:
    static bool parse(
        const std::string& line,
        StateMachine& machine,
        Context& ctx);
};