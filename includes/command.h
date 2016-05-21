#ifndef COMMAND_H
#define COMMAND_H

#include <QList>
#include <QString>
#include <iostream>

class Server;

class Command
{
    public:
        Command();
        virtual ~Command() = default;

        virtual void execute(Server *s) = 0;
        virtual QString getName() const;
        virtual QString getDescription() const;

    protected:
        QString m_name;
        QString m_description;
        QList<QString> m_aliases;
        int grade;
};

#endif // COMMAND_H
