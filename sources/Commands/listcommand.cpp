#include "includes/Commands/listcommand.h"
#include "includes/application.h"

ListCommand::ListCommand() : Command("list", "Cette commande liste les serveurs connectés")
{

}

void ListCommand::execute()
{
    int i = 0;
    for(Client* c : Application::getInstance()->getServer()->clients())
    {
        i++;
        Locator::getLogger()->log("Client " + QString::number(i), LogType::Info);
        Locator::getLogger()->log("----------------------------", LogType::Info);
        Locator::getLogger()->log("Pseudo: " + c->pseudo() + "", LogType::Info);
        std::cout << "\n" << std::endl;
    }
    return;
}
