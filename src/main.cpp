#include "CommandParser.hpp"

#include <iostream>
#include <string>

int main()
{
    Context ctx;

    StateMachine machine(ctx);

    bool running = true;

    while (running)
    {
        std::string line;

        std::cout << "> ";

        std::getline(std::cin, line);

        running =
            CommandParser::parse(
                line,
                machine,
                ctx);

        machine.update();
    }

    return 0;
}