#include "lib/network/include/Services/Loggers/networklogger.h"

NetworkLogger::NetworkLogger() : Logger("network.log")
{
}

void NetworkLogger::log(std::string log, LogType logType)
{
    std::string type = typeToString(logType);
    std::transform(type.begin(), type.end(),type.begin(), ::toupper);
    std::string message = "[" + QDateTime::currentDateTime().toString("HH:mm:ss").toStdString() + "] [";
    message += type;
    message += "] ";
    message += log;
    message += "\n";
    QTextStream stream(&m_logFile);
    stream << QString::fromStdString(message);
    std::cout << message;
}
