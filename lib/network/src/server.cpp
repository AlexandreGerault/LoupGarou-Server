#include "lib/network/include/server.h"

Server::Server() : m_serverStarted(false)
{
    m_server = new QTcpServer(this);
    if(!m_serverStarted)
    {
        Locator::getLogger()->log("Démarrage du serveur", LogType::Info);
        if(!m_server->listen(QHostAddress::Any, 56565))
        {
            Locator::getLogger()->log("Le serveur n'a pas pu démarrer", LogType::Error);
        }
        else
        {
            m_serverStarted = true;
            Locator::getLogger()->log("Le serveur a pu démarrer sur le port " + QString::number(m_server->serverPort()), LogType::Info);
            Locator::getLogger()->log("En attente de clients", LogType::Info);
            connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
            emit serverStateChange();
        }
    }
    else
        Locator::getLogger()->log("Le serveur est déjà lancé", LogType::Error);
}

void Server::stopServer()
{
    if(m_serverStarted)
    {
        m_serverStarted = false;
        Locator::getLogger()->log("Arrêt du serveur.", LogType::Info);
        m_server->close();
    }
    else
    {
        Locator::getLogger()->log("Le serveur n'a pas encore démarré.", LogType::Error);
    }
}

/*********
 * SLOTS *
 *********/
void Server::onNewConnection()
{
    Locator::getLogger()->log("Un nouveau client vient de se connecter", LogType::Info);

    QTcpSocket *newClientSocket = m_server->nextPendingConnection();

    Client *newClient = new Client(newClientSocket);

    connect(newClient->socket(), SIGNAL(disconnected()), this, SLOT(onConnectionLost()));
    newClient->setPseudo("Client " + QString::number(m_clients.size()+1));

    m_clients.append(newClient);

    Locator::getLogger()->log(newClient->pseudo() + " is now connected.", LogType::Info);
}

void Server::onConnectionLost()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(socket == 0){
        Locator::getLogger()->log("Client not found", LogType::Info);
        return;
    }

    Client *c = getClientBySocket(socket);
    QString name = c->pseudo();
    Locator::getLogger()->log(c->pseudo() + " has been disconnected.", LogType::Info);

    //We delete the socket
    socket->close();            //Closing socket
    m_clients.removeOne(c);     //Remove from QMap
    socket->deleteLater();      //Finnaly delete it

    //Then we delete the client which was attached
    delete c;

    Locator::getLogger()->log(name + " has been removed.", LogType::Info);
}

/***********************
 * Protected functions *
 ***********************/

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
         return c->socket() == sock;
     });

     if(it == m_clients.end())
     {
         throw std::runtime_error( "Client not found." );
     }

     return *it;
}

bool Server::isStarted() const
{
    return m_serverStarted;
}

QList<Client*> Server::clients()
{
    return m_clients;
}

Server::~Server()
{
    stopServer();
}
