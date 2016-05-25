#include "includes/command.h"
#include "includes/server.h"

Command::Command()
{
}

Command::Command(QString name, QString description) : m_name(name), m_description(description)
{
}

QString Command::getName() const
{
    return m_name;
}
QString Command::getDescription() const
{
    return m_description;
}
