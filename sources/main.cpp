#include "includes/serverwindow.h"
#include <QApplication>
#include <iostream>
#include "includes/Services/Loggers/networklogger.h"
#include "includes/locator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Locator::initialize();
    Logger *nw = new NetworkLogger();
    Locator::provide(nw);

    Server s;

    return a.exec();
}
