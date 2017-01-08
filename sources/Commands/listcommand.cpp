#include "includes/Commands/listcommand.h"
#include "includes/server.h"

ListCommand::ListCommand() : Command("list", "Cette commande liste les serveurs connectés")
{

}

void ListCommand::execute(Server *s)
{
    s->isStarted();
    return;
}
