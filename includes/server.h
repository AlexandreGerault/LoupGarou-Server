#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork/QtNetwork>
#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "client.h"
#include "logger.h"
#include <QDebug>
#include "includes/commandmanager.h"

class Server : public QObject
{
    Q_OBJECT

    public:
        Server();
        ~Server();

        void startServer();
        void startGame();
        void stopServer();
        void sendToAll(QString command);
        void commandProcess(Command &cmd);
        void update();
        Logger *logger();

        /***********/
        /* GETTERS */
        /***********/
        bool isStarted() const;
        const CommandManager& getCommandManager();

    signals:
        void serverStateChange();

    protected slots:
        void onNewConnection();
        void dataReceived();
        void onConnectionLost();
        void onLog(const QString& log);

    protected:
        Logger *m_logger;
        bool checkConnexion();
        Client* getClientBySocket(QTcpSocket*);
        QTcpServer *m_server;
        QMap<QTcpSocket*, Client*> m_clients;
        quint16 m_messageSize;
        QTimer *m_timer;
        bool m_serverStarted;
        CommandManager m_commandManager;
};

#endif // SERVER_H
