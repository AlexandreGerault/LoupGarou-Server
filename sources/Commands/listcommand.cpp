#include "includes/Commands/listcommand.h"
#include "includes/server.h"

ListCommand::ListCommand() : Command("list", "Cette commande liste les serveurs connectés")
{

}

void ListCommand::execute(Server *s)
{
    int i = 0;
    for(auto it = s->clients().begin(); it!= s->clients().end(); it++)
    {
        i++;
        Client* c = *it;

        s->logger()->log("Client " + QString::number(i), LogType::Info);
        s->logger()->log("----------------------------", LogType::Info);
        s->logger()->log("Pseudo: " + c->pseudo() + "", LogType::Info);
        std::cout << "\n" << std::endl;
    }
    return;
}
