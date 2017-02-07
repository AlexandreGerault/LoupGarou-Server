#include "lib/UI/include/command.h"
#include "lib/core/include/application.h"

Command::Command()
{
}

Command::Command(std::string name, std::string description) : m_name(name), m_description(description)
{
}

std::string Command::getName() const
{
    return m_name;
}
std::string Command::getDescription() const
{
    return m_description;
}
