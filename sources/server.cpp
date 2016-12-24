#include "includes/server.h"

Server::Server() : m_logFile("logs.txt"), m_messageSize(0), m_serverStarted(false)
{
    m_server = new QTcpServer(this);
    startServer();
}

void Server::writeALog(const QString &logMessage, LogType c)
{
    QString type;

    switch(c)
    {
        case LogType::Info:    type = "info";    break;
        case LogType::Error:   type = "error";   break;
        case LogType::Send:    type = "send";    break;
        case LogType::Warning: type = "warning"; break;
    }
    QString message = "[" + QDateTime::currentDateTime().toString("HH:mm:ss") + "] [" + type.toUpper() + "] " + logMessage;

    emit log(message, c);

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
            emit serverStateChange();
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
        emit serverStateChange();
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
    Client *newClient = new Client(newClientSocket);
    newClient->setPseudo("NewClient");

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

    writeALog(c->pseudo() + "] " + data, LogType::Send);
}

void Server::onConnectionLost()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0){
        writeALog("Client not found \n", LogType::Info);
        return;
    }
    Client *c = getClientBySocket(socket);

    writeALog(c->pseudo() + " has been disconnected.\n", LogType::Info);
    c->getSocket()->close();
    QString name = c->pseudo();
    m_clients.removeOne(c);
    c->getSocket()->deleteLater();
    delete c;
    writeALog(name + " has been removed.\n", LogType::Info);
}

/***********************
 * protected functions *
 ***********************/

void Server::commandProcess(Command &cmd)
{
    try {
        cmd.execute(this);
    } catch(QString error) {
        writeALog(error, LogType::Error);
    }

}

void Server::sendToAll(QString message)
{
    for(Client *c : m_clients)
    {
        c->send(message);
    }
}

Client * Server::getClientBySocket( QTcpSocket * sock )
{
    auto it = std::find_if( m_clients.cbegin(), m_clients.cend(), [&sock]( Client const * const c )
    {
        return c->getSocket() == sock;
    });

    if(it == m_clients.end())
    {
        throw std::runtime_error( "Client not found." );
    }

    return *it;
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
