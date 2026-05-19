#include "CommandParser.hpp"

#include <iostream>
#include <sstream>

bool CommandParser::parse(
    const std::string& line,
    StateMachine& machine,
    Context& ctx)
{
    std::stringstream ss(line);

    std::string command;

    ss >> command;

    if (command == "start")
    {
        machine.start();
    }
    else if (command == "stop")
    {
        machine.stop();
    }
    else if (command == "reset")
    {
        machine.reset();
    }
    else if (command == "fault")
    {
        std::string value;

        ss >> value;

        if (value == "on")
        {
            ctx.faultActive = true;
        }
        else if (value == "off")
        {
            ctx.faultActive = false;
        }
    }
    else if (command == "set")
    {
        std::string variable;

        ss >> variable;

        if (variable == "pressure")
        {
            ss >> ctx.pressure;
        }
        else if (variable == "temperature")
        {
            ss >> ctx.temperature;
        }
    }
    else if (command == "status")
    {
        std::cout
            << "Pressure: "
            << ctx.pressure
            << "\n";

        std::cout
            << "Temperature: "
            << ctx.temperature
            << "\n";

        std::cout
            << "Fault: "
            << (ctx.faultActive ? "ON" : "OFF")
            << "\n";
    }
    else if (command == "quit")
    {
        return false;
    }
    else
    {
        std::cout
            << "Unknown command\n";
    }

    return true;
}