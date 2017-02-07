#include "lib/UI/include/Commands/listcommand.h"
#include "lib/core/include/application.h"

ListCommand::ListCommand() : Command("list", "Cette commande liste les serveurs connectés")
{

}

void ListCommand::execute()
{
    int i = 0;
    for(Client* c : Application::getInstance()->getServer()->clients())
    {
        i++;
        Locator::getLogger()->log("Client " + std::to_string(i), LogType::Info);
        Locator::getLogger()->log("----------------------------", LogType::Info);
        Locator::getLogger()->log("Pseudo: " + c->pseudo() + "", LogType::Info);
        std::cout << std::endl;
    }
    return;
}
