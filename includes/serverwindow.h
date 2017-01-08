#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QKeyEvent>
#include "ui_serverwindow.h"
#include "server.h"
#include "includes/command.h"
#include <cstddef>

class ServerWindow : public QWidget, private Ui::ServerWindow
{
    Q_OBJECT

    public:
        ServerWindow();
        ~ServerWindow();

    public slots:
        void sendCommand();
        void onServerStateChange();
        void onStartServerButtonClicked();
        void onStopServerButtonClicked();
        void onClearButtonClicked();
        void onCursorPositionChanged();
        void onLog(QString const, LogType const);

    private:
        void writeALog(const QString&, LogType c);
        Logger *m_logger;
        Server *m_server;

};

#endif // LOGWINDOW_H
