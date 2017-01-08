#include "includes/client.h"

Client::Client()
{
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
