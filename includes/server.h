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
#include "parser.h"
#include <QDebug>
#include "includes/commandmanager.h"

enum class LogType {Info, Warning, Error, Send};

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
        virtual void writeALog(const QString& log, LogType c);

        /***********/
        /* GETTERS */
        /***********/
        bool isStarted() const;
        CommandManager getCommandManager() const;

    signals:
        void serverStateChange();

    protected slots:
        void onNewConnection();
        void dataReceived();
        void onConnectionLost();

    protected:
        bool checkConnexion();
        Client* getClientBySocket(QTcpSocket*);
        QTcpServer *m_server;
        QList<Client*> m_clients;
        quint16 m_tailleMessage;
        QFile m_logFile;
        QTimer *m_timer;
        QTextStream *m_logger;
        bool m_serverStarted;
        CommandManager m_commandManager;
};

#endif // SERVER_H
