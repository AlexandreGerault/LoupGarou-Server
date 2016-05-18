#include "includes/parser.h"

Parser::Parser()
{

}

std::vector<std::string> Parser::parse(std::string message)
{
    std::vector<std::string> args;
    std::istringstream iss(message);
    std::string parsed = message;

    while(std::getline(iss, parsed, ' '))
    {
        args.push_back(parsed);
    }

    return args;
}
