#include "includes/Commands/startcommand.h"
#include "includes/server.h"

StartCommand::StartCommand() :  Command("start", "Cette commande sert à lancer le serveur.")
{
}

void StartCommand::execute(Server *s)
{
    if(s != NULL)
        s->startServer();
    else
        throw QString("Erreur : pointeur de serveur null");
}
