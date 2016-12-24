#ifndef COMMAND_H
#define COMMAND_H

#include <QList>
#include <QString>

class Server;

class Command
{
    public:
        Command();
        Command(QString name, QString description);
        virtual ~Command() = default;

        virtual void execute(Server *s) = 0;
        QString getName() const;
        QString getDescription() const;

    protected:
        QString m_name;
        QString m_description;

        QList<QString> m_aliases;
        int grade;
};

#endif // COMMAND_H
