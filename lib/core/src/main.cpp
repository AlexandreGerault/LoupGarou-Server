#include <QApplication>
#include <iostream>
#include "lib/core/include/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Locator::initialize();
    Logger *nw = new NetworkLogger();
    Locator::provide(nw);

    Application *app = Application::getInstance();
    app->run();

    return a.exec();
}
