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
#include <QDebug>
#include "includes/commandmanager.h"
#include "locator.h"

class Server : public QObject
{
    Q_OBJECT

    public:
        Server();
        ~Server();

        void startServer();
        void stopServer();
        void sendToAll(QString command);
        //void commandProcess(Command &cmd);
        void update();
        QList<Client*> clients();

        /***********/
        /* GETTERS */
        /***********/
        bool isStarted() const;
        //const CommandManager& getCommandManager();

    signals:
        void serverStateChange();

    protected slots:
        void onNewConnection();
        void onConnectionLost();

    protected:
        bool checkConnexion();
        Client* getClientBySocket(QTcpSocket*);
        QTcpServer *m_server;
        QList<Client*> m_clients;
        bool m_serverStarted;
        CommandManager m_commandManager;
};

#endif // SERVER_H
