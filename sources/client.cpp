#include "includes/client.h"

Client::Client(QTcpSocket* socket) : m_authenticated(false), m_messageSize(0), m_socket(socket)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onDataReceived);
}

QTcpSocket* Client::socket() const
{
    return m_socket;
}
void Client::setPseudo(QString pseudo)
{
    m_pseudo = pseudo;
}
QString Client::pseudo() const
{
    return m_pseudo;
}
void Client::setGrade(int grade)
{
    m_grade = grade;
}
int Client::grade() const
{
    return m_grade;
}

void Client::send(QString command)
{
}


void Client::onDataReceived()
{
    std::cout << "TEST TEST TEST TEST" << std::endl;
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if(socket == 0)
        return;
    else if(socket != m_socket)
        throw("Client socket is different than the called one");

    QDataStream in(socket);
    QString data;

    while(true) {
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

        in >> data;
    }
}

bool Client::isAuthenticated() const
{
    return m_authenticated;
}
