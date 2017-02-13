#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QtNetwork>
#include <iostream>
#include <list>
#include <algorithm>
#include "lib/network/include/client.h"
#include "lib/core/include/locator.h"

class Server : public QObject
{
    Q_OBJECT

    public:
        Server();
        ~Server();

        void startServer();
        void stopServer();
        void sendToAll(QString command);
        std::list<Client*> clients();

        /***********/
        /* GETTERS */
        /***********/
        bool isStarted() const;
    signals:
        void serverStateChange();

    protected slots:
        void onNewConnection();
        void onConnectionLost();

    protected:
        bool checkConnexion();
        Client* getClientBySocket(QTcpSocket*);
        QTcpServer *m_server;
        std::list<Client*> m_clients;
        bool m_serverStarted;
};

#endif // SERVER_H
