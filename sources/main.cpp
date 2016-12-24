#include "includes/serverwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWindow w;
    w.show();
    return a.exec();
}
