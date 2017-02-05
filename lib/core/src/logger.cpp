#include "lib/core/include/logger.h"

Logger::Logger(QString fileName) : m_fileName(fileName), m_logFile(m_fileName), m_stream(&m_logFile)
{
    if(!m_logFile.open(QIODevice::ReadWrite | QIODevice::Text))
        throw("Le fichier journal n'a pas été chargé");
}

QString Logger::typeToString(LogType logType)
{
    QString type;
    switch(logType)
    {
        case LogType::Info:    type = "info";    break;
        case LogType::Error:   type = "error";   break;
        case LogType::Send:    type = "send";    break;
        case LogType::Warning: type = "warning"; break;
        case LogType::Data:    type= "data";     break;
    }
    return type;
}
