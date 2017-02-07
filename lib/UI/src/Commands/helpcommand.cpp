#include "lib/UI/include/Commands/helpcommand.h"
#include "lib/core/include/application.h"

HelpCommand::HelpCommand() : Command("help", "Obtenir de l'aide")
{
}

void HelpCommand::execute()
{
    if(Application::getInstance()->getServer() != NULL)
    {
        std::list<Command*> commands = Application::getInstance()->commandManager()->getCommands();

        for(Command *c : commands)
        {
            std::string name = c->getName();
            std::string desc = c->getDescription();
            Locator::getLogger()->log(name + " - " + desc, LogType::Info);
        }
    }
    else
    {
        throw std::string("Erreur : pointeur de serveur null");
    }
}
