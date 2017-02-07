#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QObject>
#include <iostream>
#include <map>
#include <list>
#include "lib/UI/include/Commands/stopcommand.h"
#include "lib/UI/include/Commands/helpcommand.h"
#include "lib/UI/include/Commands/listcommand.h"
#include "lib/core/include/locator.h"

class CommandManager : public QObject
{
    Q_OBJECT

    public:
        /***************
        * Entity class *
        ****************/
        CommandManager();
        CommandManager(CommandManager const&) = delete;
        CommandManager& operator=(CommandManager&) = delete;
        bool operator==(CommandManager const&) = delete;
        bool operator!=(CommandManager const&) = delete;

        virtual ~CommandManager();

        Command* getCommand(std::string label) const;
        std::list<Command*> getCommands() const;
    public slots:
        void commandProcess(std::string inputCommand);
    private:
        std::map<std::string, Command*> m_commands;
};

#endif // COMMANDMANAGER_H
