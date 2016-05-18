#include "includes/command.h"
#include "includes/server.h"

Command::Command()
{

}

void Command::execute(Server *s)
{
    std::cout << "Fail";
}

QString Command::getName() const
{
    return m_name;
}
QString Command::getDescription() const
{
    return m_description;
}
