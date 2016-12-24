#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include <iostream>
#include "includes/command.h"

class StartCommand : public Command
{
    public:
        StartCommand();
        void execute(Server *s) override;

    private:

};

#endif // STARTCOMMAND_H
