#ifndef COMMAND_H
#define COMMAND_H

#include <list>
#include <iostream>

class Application;

class Command
{
    public:
        /***************
        * Entity class *
        ****************/
        Command();
        Command(std::string name, std::string description);
        virtual ~Command() = default;

        virtual void execute() = 0;
        std::string getName() const;
        std::string getDescription() const;

    protected:
        std::string m_name;
        std::string m_description;

        std::list<std::string> m_aliases;
        int grade;
};

#endif // COMMAND_H
