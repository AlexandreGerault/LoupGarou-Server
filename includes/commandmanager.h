#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QMap>
#include <QObject>
#include <iostream>
#include "includes/Commands/stopcommand.h"
#include "includes/Commands/helpcommand.h"
#include "includes/Commands/listcommand.h"
#include "includes/locator.h"

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

        Command* getCommand(QString label) const;
        QList<Command*> getCommands() const;
    public slots:
        void commandProcess(std::string inputCommand);
    private:
        QMap<QString, Command*> m_commands;
};

#endif // COMMANDMANAGER_H
