#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include <iostream>
#include "includes/command.h"

class HelpCommand : public Command
{
    public:
        HelpCommand();
        virtual void execute(Server *s);

    private:

};

#endif // HELPCOMMAND_H
