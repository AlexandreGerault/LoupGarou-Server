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
            QString name = QString::fromStdString(c->getName()).toUpper();
            QString desc = QString::fromStdString(c->getDescription()).toUpper();
            Locator::getLogger()->log(name + " - " + desc, LogType::Info);
        }
    }
    else
    {
        throw QString("Erreur : pointeur de serveur null");
    }
}
