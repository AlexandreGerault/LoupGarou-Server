#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H

#include "includes/command.h"

class ListCommand : public Command
{
public:
    ListCommand();
    void execute(Server *s) override;
private:
};

#endif // LISTCOMMAND_H
