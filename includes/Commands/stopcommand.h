#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include <iostream>
#include "includes/command.h"

class StopCommand : public Command
{
    public:
        StopCommand();
        void execute() override;

    private:

};

#endif // STOPCOMMAND_H
