#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <memory>

class Client
{
    public:
        Client();
        QString pseudo() const;
        int grade() const;

        void setSocket(QTcpSocket *socket);
        void setPseudo(QString pseudo);
        void setGrade(int grade);

        void send(QString);

    private:
        QString m_pseudo;
        int m_grade;

};

#endif // CLIENT_H
