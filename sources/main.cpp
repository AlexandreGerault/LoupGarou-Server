#include <QApplication>
#include <iostream>
#include "includes/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Application app;

    /*while(true) //A voir comment en sortir si je tape quit
    {
        std::string inputCommand;
        std::getline(std::cin, inputCommand);
        std::cout << "InputHandler will handle the " << inputCommand << " command whenever is possible." << std::endl;
    }*/

    return a.exec();
}
