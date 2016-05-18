#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Parser
{
public:
    Parser();
    static std::vector<std::string> parse(std::string message);
};

#endif // PARSER_H
