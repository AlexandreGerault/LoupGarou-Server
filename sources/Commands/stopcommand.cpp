#include "includes/Commands/stopcommand.h"
#include "includes/server.h"

StopCommand::StopCommand() : Command("stop", "Cette commande sert à éteindre le serveur.")
{
}

void StopCommand::execute(Server *s)
{
    if(s != NULL)
        s->stopServer();
    else
        throw QString("Erreur : pointeur de serveur null");
}
