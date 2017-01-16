#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include <iostream>
#include "includes/command.h"

class HelpCommand : public Command
{
    public:
        HelpCommand();
        void execute() override;

    private:

};

#endif // HELPCOMMAND_H
