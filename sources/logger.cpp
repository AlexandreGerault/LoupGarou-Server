#include "includes/logger.h"

Logger::Logger(QString fileName) : m_fileName(fileName), m_logFile(m_fileName), m_stream(&m_logFile)
{
    if(!m_logFile.open(QIODevice::ReadWrite | QIODevice::Text))
        throw("Le fichier journal n'a pas été chargé");
}
