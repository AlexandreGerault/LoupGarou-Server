#include "includes/Commands/helpcommand.h"
#include "includes/server.h"

HelpCommand::HelpCommand() : Command("help", "Obtenir de l'aide")
{
}

void HelpCommand::execute(Server *s)
{
    if(s != NULL)
    {
        QList<Command*> commands = s->getCommandManager().getCommands();

        for(Command *c : commands)
        {
            s->writeALog(c->getName().toUpper() + " - " + c->getDescription(), LogType::Info);
        }
    }
    else
    {
        throw QString("Erreur : pointeur de serveur null");
    }
}
