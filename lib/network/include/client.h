#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <memory>
#include <iostream>
#include "lib/core/include/locator.h"

class Client : public QObject
{
    Q_OBJECT

    public:
        Client(QTcpSocket* socket);
        bool isAuthenticated() const;
        QTcpSocket* socket() const;
        std::string pseudo() const;
        int grade() const;

        void setSocket(QTcpSocket *socket);
        void setPseudo(std::string pseudo);
        void setGrade(int grade);

        void send(const QString&);

    public slots:
        void onDataReceived();

    private:
        std::string m_pseudo;
        bool m_authenticated;
        quint16 m_messageSize;
        QTcpSocket *m_socket;
        int m_grade;

};

#endif // CLIENT_H
