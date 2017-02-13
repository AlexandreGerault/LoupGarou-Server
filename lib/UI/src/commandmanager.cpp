#include "lib/UI/include/commandmanager.h"

CommandManager::CommandManager()
{
    Command *helpCmd  = new HelpCommand;
    Command *stopCmd  = new StopCommand;
    Command *listCmd = new ListCommand;

    m_commands.insert(std::pair<std::string,Command*>(stopCmd->getName(), stopCmd));
    m_commands.insert(std::pair<std::string,Command*>(helpCmd->getName(), helpCmd));
    m_commands.insert(std::pair<std::string,Command*>(listCmd->getName(), listCmd));
}

Command* CommandManager::getCommand(std::string label) const
{
    auto it = m_commands.find(label);
    if(it != m_commands.end())
        return it->second;
    else
        throw std::string("Command not found");
}

std::list<Command*> CommandManager::getCommands() const
{
    std::list<Command*> cmds;
    auto listIterator = cmds.begin();
    for (auto it = m_commands.begin(); it!=m_commands.end(); it++)
    {
        cmds.insert(listIterator, it->second);
    }
    return cmds;
}

void CommandManager::commandProcess(std::string inputCommand)
{
    try {
        getCommand(inputCommand)->execute();
    } catch(std::string error) {
        Locator::getLogger()->log(error, LogType::Error);
    }
}

CommandManager::~CommandManager()
{
    for(auto it = m_commands.begin(); it!= m_commands.end(); it++)
    {
        delete it->second;
    }
    m_commands.clear();
}
