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
        //s->logger()->log("Client " + QString::number(i), LogType::Info);
        //s->logger()->log("----------------------------", LogType::Info);
        //s->logger()->log("Pseudo: " + c->pseudo() + "", LogType::Info);
        std::cout << "\n" << std::endl;
    }
    return;
}
