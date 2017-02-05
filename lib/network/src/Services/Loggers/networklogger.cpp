#include "lib/network/include/Services/Loggers/networklogger.h"

NetworkLogger::NetworkLogger() : Logger("network.log")
{
}

void NetworkLogger::log(QString log, LogType logType)
{
    std::string message = QString("[" + QDateTime::currentDateTime().toString("HH:mm:ss") + "] [" + typeToString(logType).toUpper() + "] " + log + "\n").toStdString();
    QTextStream stream(&m_logFile);
    stream << QString::fromStdString(message);
    std::cout << message;
}
