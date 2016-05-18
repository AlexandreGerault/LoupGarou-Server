#include "includes/Commands/helpcommand.h"
#include "includes/server.h"

HelpCommand::HelpCommand()
{
    m_description = "Permet d'obtenir la liste des commandes et leur description correspondante.";
}

void HelpCommand::execute(Server *s)
{
    QList<Command*> commands = s->getCommandManager().getCommands();

    for(Command *c : commands)
    {
        s->writeALog(c->getName() + " - " + c->getDescription(), LogType::Info);
    }
}
