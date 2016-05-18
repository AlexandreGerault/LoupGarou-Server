#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include <iostream>
#include "includes/command.h"

class StartCommand : public Command
{
    public:
        StartCommand();
        virtual void execute(Server *s);

    private:

};

#endif // STARTCOMMAND_H
