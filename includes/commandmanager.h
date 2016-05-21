#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QMap>
#include <iostream>
#include "includes/Commands/startcommand.h"
#include "includes/Commands/stopcommand.h"
#include "includes/Commands/helpcommand.h"

class CommandManager
{
    public:
        CommandManager();
        ~CommandManager();

        Command* getCommand(QString label) const;
        QList<Command*> getCommands() const;

    private:
        QMap<QString, Command*> m_commands;
};

#endif // COMMANDMANAGER_H
