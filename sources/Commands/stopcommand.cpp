#include "includes/Commands/stopcommand.h"
#include "includes/application.h"

StopCommand::StopCommand() : Command("stop", "Cette commande sert à éteindre le serveur.")
{
}

void StopCommand::execute()
{
    if(Application::getInstance()->getServer() != NULL)
        Application::getInstance()->getServer()->stopServer();
    else
        throw QString("Erreur : pointeur de serveur null");
}
