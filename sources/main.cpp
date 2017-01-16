#include <QApplication>
#include <iostream>
#include "includes/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Locator::initialize();
    Logger *nw = new NetworkLogger();
    Locator::provide(nw);

    Application *app = Application::getInstance();

    return a.exec();
}
