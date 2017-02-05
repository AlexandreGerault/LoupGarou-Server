#include "lib/UI/include/Commands/helpcommand.h"
#include "lib/core/include/application.h"

HelpCommand::HelpCommand() : Command("help", "Obtenir de l'aide")
{
}

void HelpCommand::execute()
{
    if(Application::getInstance()->getServer() != NULL)
    {
        QList<Command*> commands = Application::getInstance()->commandManager()->getCommands();

        for(Command *c : commands)
        {
            Locator::getLogger()->log(c->getName().toUpper() + " - " + c->getDescription(), LogType::Info);
        }
    }
    else
    {
        throw QString("Erreur : pointeur de serveur null");
    }
}
