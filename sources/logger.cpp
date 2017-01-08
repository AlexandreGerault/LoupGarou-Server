#include "includes/logger.h"

Logger *Logger::m_pInstance = NULL;

Logger::Logger() : m_logFile("logs.txt"), m_stream(&m_logFile)
{
    connect(this, SIGNAL(logging(QString,LogType)), this , SLOT(writeToLogFile(QString,LogType)));
}

Logger* Logger::Instance()
{
    if(m_pInstance == NULL)
        return m_pInstance = new Logger();

    return m_pInstance;
}

bool Logger::openLogFile(std::string logFile)
{
    if(!m_logFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        std::cout << "Le fichier journal n'a pas été chargé." << std::endl;
        return false;
    }
    return true;
}

bool Logger::closeLogFile()
{
    m_logFile.close();
    return true;
}

void Logger::log(QString log, LogType logType)
{
    QString type;
    switch(logType)
    {
        case LogType::Info:    type = "info";    break;
        case LogType::Error:   type = "error";   break;
        case LogType::Send:    type = "send";    break;
        case LogType::Warning: type = "warning"; break;
    }
    QString message = "[" + QDateTime::currentDateTime().toString("HH:mm:ss") + "] [" + type.toUpper() + "] " + log;
    emit logging(message, logType);
}

void Logger::writeToLogFile(QString log, LogType logType)
{
    m_stream << log << "\n";
}

void Logger::kill()
{

}


