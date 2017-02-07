#include "lib/network/include/Services/Loggers/networklogger.h"

NetworkLogger::NetworkLogger() : Logger("./network-" + QDateTime::currentDateTime().toString("dd-MM-yyyy").toStdString() + ".log")
{
}

void NetworkLogger::log(std::string log, LogType logType)
{
    std::string type = typeToString(logType);
    std::transform(type.begin(), type.end(),type.begin(), ::toupper);
    std::string message = "[" + QDateTime::currentDateTime().toString("HH:mm:ss").toStdString() + "] [" + type + "] " + log + "\n";
    QTextStream stream(&m_logFile);
    stream << QString::fromStdString(message);
    std::cout << message;
}
