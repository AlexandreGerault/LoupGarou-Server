#include "includes/Commands/startcommand.h"
#include "includes/server.h"

StartCommand::StartCommand()
{
    m_name = "start";
    m_description = "Cette commande sert à lancer le serveur.";
}

void StartCommand::execute(Server *s)
{
    s->startServer();
}
