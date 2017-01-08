#include "includes/server.h"

Server::Server() : m_logger(Logger::Instance()), m_messageSize(0), m_serverStarted(false)
{
    m_server = new QTcpServer(this);
    connect(m_logger, SIGNAL(logging(QString,LogType)), this, SLOT(onLog(QString)));
    startServer();
}

Logger *Server::logger()
{
    return m_logger;
}

void Server::onLog(const QString& log)
{
    std::cout << log.toStdString() << std::endl;
}

void Server::startServer()
{
    if(!m_serverStarted)
    {
        m_logger->log("Démarrage du serveur", LogType::Info);
        if(!m_server->listen(QHostAddress::Any, 56565))
        {
            m_logger->log("Le serveur n'a pas pu démarrer", LogType::Error);
        }
        else
        {
            m_serverStarted = true;
            m_logger->log("Le serveur a pu démarrer sur le port " + QString::number(m_server->serverPort()), LogType::Info);
            m_logger->log("En attente de clients", LogType::Info);
            connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
            emit serverStateChange();
        }
    }
    else
        m_logger->log("Le serveur est déjà lancé", LogType::Error);
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
        m_serverStarted = false;
        m_logger->log("Arrêt du serveur.", LogType::Info);
        m_server->close();
        emit serverStateChange();
    }
    else
    {
        m_logger->log("Le serveur n'a pas encore démarré.", LogType::Error);
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
    m_logger->log("Un nouveau client vient de se connecter", LogType::Info);

    QTcpSocket *newClientSocket = m_server->nextPendingConnection();
    Client *newClient = new Client;
    newClient->setPseudo("NewClient");

    m_clients.insert(m_clients.end(), newClientSocket, newClient);
    connect(newClientSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(newClientSocket, SIGNAL(disconnected()), this, SLOT(onConnectionLost()));
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
    if(m_messageSize == 0)
    {
        if(socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> m_messageSize;
    }

    //if we don't have the whole data
    if(socket->bytesAvailable() < m_messageSize)
        return;

    QString data;
    in >> data;

    m_logger->log(c->pseudo() + "] " + data, LogType::Send);
}

void Server::onConnectionLost()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0){
        m_logger->log("Client not found \n", LogType::Info);
        return;
    }

    Client *c = getClientBySocket(socket);
    QString name = c->pseudo();
    m_logger->log(c->pseudo() + " has been disconnected.\n", LogType::Info);

    //We delete the socket
    socket->close();            //Closing socket
    m_clients.remove(socket);   //Remove from QMap
    socket->deleteLater();      //Finnaly delete it

    //Then we delete the client which was attached
    delete c;

    m_logger->log(name + " has been removed.\n", LogType::Info);
}

/***********************
 * Protected functions *
 ***********************/
void Server::commandProcess(Command &cmd)
{
    try {
        cmd.execute(this);
    } catch(QString error) {
        m_logger->log(error, LogType::Error);
    }
}

void Server::sendToAll(QString message)
{
    for(Client *c : m_clients)
    {
        c->send(message);
    }
}

Client * Server::getClientBySocket(QTcpSocket * sock)
{
    auto client = m_clients.find(sock);
    Client *c = *client;
    std::cout << c->pseudo().toStdString();
    return *client;
}

const CommandManager& Server::getCommandManager()
{
    return m_commandManager;
}

bool Server::isStarted() const
{
    return m_serverStarted;
}

Server::~Server()
{
    stopServer();
}
