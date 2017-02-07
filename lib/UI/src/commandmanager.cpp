#include "lib/UI/include/commandmanager.h"

CommandManager::CommandManager()
{
    Command *helpCmd  = new HelpCommand;
    Command *stopCmd  = new StopCommand;
    Command *listCmd = new ListCommand;

    m_commands.insert(QString::fromStdString(stopCmd->getName()),  stopCmd);
    m_commands.insert(QString::fromStdString(helpCmd->getName()),  helpCmd);
    m_commands.insert(QString::fromStdString(listCmd->getName()), listCmd);
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

void CommandManager::commandProcess(std::string inputCommand)
{
    try {
        getCommand(QString::fromStdString(inputCommand))->execute();
    } catch(QString error) {
        Locator::getLogger()->log(error, LogType::Error);
    }
}

CommandManager::~CommandManager()
{
    for(auto it = m_commands.begin(); it!= m_commands.end(); it++)
    {
        delete *it;
    }
    m_commands.clear();
}
