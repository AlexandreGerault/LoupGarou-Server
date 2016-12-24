#include "includes/commandmanager.h"

CommandManager::CommandManager()
{
    Command *helpCmd  = new HelpCommand;
    Command *startCmd = new StartCommand;
    Command *stopCmd  = new StopCommand;
    Command *listCmd = new ListCommand;

    m_commands.insert(startCmd->getName(), startCmd);
    m_commands.insert(stopCmd->getName(),  stopCmd);
    m_commands.insert(helpCmd->getName(),  helpCmd);
    m_commands.insert(listCmd->getName(), listCmd);
}

Command* CommandManager::getCommand(QString label) const
{
    for(auto it = m_commands.begin(); it!= m_commands.end(); it++)
    {
        if(label == it.key())
        {
            return *it;
        }
    }
    QString exception = "Command not found";
    throw exception;
}

QList<Command*> CommandManager::getCommands() const
{
    QList<Command*> cmds = m_commands.values();
    return cmds;
}

CommandManager::~CommandManager()
{
    for(auto it = m_commands.begin(); it!= m_commands.end(); it++)
    {
        delete *it;
    }
    m_commands.clear();
}
