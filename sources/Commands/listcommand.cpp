#include "includes/Commands/listcommand.h"
#include "includes/server.h"

ListCommand::ListCommand() : Command("list", "Cette commande liste les serveurs connectés")
{

}

void ListCommand::execute(Server *s)
{
    int i = 0;
    for(Client* c : s->clients())
    {
        i++;
        Locator::getLogger()->log("Client " + QString::number(i), LogType::Info);
        Locator::getLogger()->log("----------------------------", LogType::Info);
        Locator::getLogger()->log("Pseudo: " + c->pseudo() + "", LogType::Info);
        std::cout << "\n" << std::endl;
    }
    return;
}
