#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>

class Client
{
    public:
        Client(QTcpSocket* socket);
        QTcpSocket* getSocket() const;
        QString pseudo() const;
        int grade() const;

        void setSocket(QTcpSocket *socket);
        void setPseudo(QString pseudo);
        void setGrade(int grade);

        void send(QString);

    private:
        QString m_pseudo;
        QTcpSocket *m_socket;
        int m_grade;

};

#endif // CLIENT_H
