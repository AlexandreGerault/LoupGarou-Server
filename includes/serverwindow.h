#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QKeyEvent>
#include "ui_serverwindow.h"
#include "server.h"
#include "includes/command.h"
#include <cstddef>

class ServerWindow : public Server, private Ui::ServerWindow
{
    Q_OBJECT

    public:
        ServerWindow();
        ~ServerWindow();

    public slots:
        void sendCommand();

    private:
        virtual void writeALog(const QString&, LogType c);

};

#endif // LOGWINDOW_H
