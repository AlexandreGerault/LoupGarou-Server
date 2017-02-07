#include "lib/core/include/logger.h"

Logger::Logger(std::string fileName) : m_fileName(QString::fromStdString(fileName)), m_logFile(m_fileName), m_stream(&m_logFile)
{
    if(!m_logFile.open(QIODevice::ReadWrite | QIODevice::Text))
        throw("Le fichier journal n'a pas été chargé");
}

std::string Logger::typeToString(LogType logType)
{
    std::string type;
    switch(logType)
    {
        case LogType::Info:    type = "info";    break;
        case LogType::Error:   type = "error";   break;
        case LogType::Send:    type = "send";    break;
        case LogType::Warning: type = "warning"; break;
        case LogType::Data:    type=  "data";     break;
    }
    return type;
}
