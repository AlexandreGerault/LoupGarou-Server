#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include <iostream>
#include "includes/command.h"

class StopCommand : public Command
{
    public:
        StopCommand();
        virtual void execute(Server *s);

    private:

};

#endif // STOPCOMMAND_H
