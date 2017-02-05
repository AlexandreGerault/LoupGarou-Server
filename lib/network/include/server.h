#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork/QtNetwork>
#include <iostream>
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
        QList<Client*> clients();

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
        QList<Client*> m_clients;
        bool m_serverStarted;
};

#endif // SERVER_H
