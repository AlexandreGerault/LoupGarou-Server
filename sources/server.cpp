#include "includes/server.h"

Server::Server() : m_logFile("logs.txt"), m_tailleMessage(0), m_serverStarted(false)
{
    m_server = new QTcpServer(this);
}

void Server::writeALog(const QString &log, LogType c)
{
    QString type;

    switch(c)
    {
        case LogType::Info:    type = "info";    break;
        case LogType::Error:   type = "error";   break;
        case LogType::Send:    type = "send";    break;
        case LogType::Warning: type = "warning"; break;
    }
    QString message = "[" + type.toUpper() + "] <span class=\"" + type + "\">" + log + "</span>";

    std::cout << message.toStdString() << std::endl;
}

void Server::startServer()
{
    if(!m_serverStarted)
    {
        writeALog("Démarrage du serveur", LogType::Info);
        if(!m_server->listen(QHostAddress::Any, 56565))
        {
            writeALog("Le serveur n'a pas pu démarrer", LogType::Error);
        }
        else
        {
            if(m_logFile.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                writeALog("Chargement du fichier <em>logs.txt</em>", LogType::Info);
            }
            else
            {
                return;
            }
            m_serverStarted = true;
            writeALog("Le serveur a pu démarrer sur le port " + QString::number(m_server->serverPort()), LogType::Info);
            writeALog("En attente de clients", LogType::Info);
            connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        }
    }
    else
        writeALog("Le serveur est déjà lancé", LogType::Error);
}

void Server::startGame()
{
    sendToAll("say The game is started");
    m_timer->start();
}

void Server::stopServer()
{
    if(m_serverStarted)
    {
        m_logFile.close();
        m_serverStarted = false;
        writeALog("Arrêt du serveur.", LogType::Info);
        m_server->close();
    }
    else
    {
        writeALog("Le serveur n'a pas encore démarré.", LogType::Error);
    }

}

void Server::update()
{

}

/*********
 * SLOTS *
 *********/
void Server::onNewConnection()
{
    writeALog("Un nouveau client vient de se connecter", LogType::Info);

    QTcpSocket *newClientSocket = m_server->nextPendingConnection();
    Client *newClient = new Client();
    newClient->setPseudo("NewClient");
    newClient->setSocket(newClientSocket);

    m_clients << newClient;
    connect(newClient->getSocket(), SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(newClient->getSocket(), SIGNAL(disconnected()), this, SLOT(onConnectionLost()));
}

void Server::dataReceived()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if(socket == 0)
        return;

    Client *c = getClientBySocket(socket);
    QDataStream in(socket);

    //Receive the data size (the first 16 bits)
    //The Slot is called each sub-packet received
    if(m_tailleMessage == 0)
    {
        if(socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> m_tailleMessage;
    }

    //if we don't have the whole data
    if(socket->bytesAvailable() < m_tailleMessage)
        return;

    QString data;
    in >> data;

    writeALog(data, LogType::Send);
}

void Server::onConnectionLost()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0)
        return;
    Client *c = getClientBySocket(socket);
}

/***********************
 * protected functions *
 ***********************/

void Server::commandProcess(Command cmd)
{
    cmd.execute(this);
}

void Server::sendToAll(QString command)
{
    for(Client *c : m_clients)
    {
        c->send(command);
    }
}

void Server::sendToAsleep(QString command)
{
}

void Server::sendToAwoken(QString command)
{
}

Client* Server::getClientBySocket(QTcpSocket *sock)
{
    for(Client *c : m_clients)
    {
        if(c->getSocket() == sock)
        {
            return c;
        }
    }
    return NULL;
}

CommandManager Server::getCommandManager() const
{
    return m_commandManager;
}

Server::~Server()
{
}
