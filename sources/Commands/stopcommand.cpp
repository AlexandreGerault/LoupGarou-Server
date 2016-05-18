#include "includes/Commands/stopcommand.h"
#include "includes/server.h"

StopCommand::StopCommand()
{
    m_name = "stop";
    m_description = "Cette commande sert à éteindre le serveur.";
}

void StopCommand::execute(Server *s)
{
    s->stopServer();
}
