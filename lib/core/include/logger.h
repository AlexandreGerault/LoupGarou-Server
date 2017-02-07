#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <QTextStream>
#include <iostream>
#include <QFile>
#include <QString>

enum class LogType {Info, Warning, Error, Send, Data};

class Logger
{
    public:
        Logger(std::string fileName);
        virtual ~Logger() = default;

        virtual void log(std::string log, LogType logType) = 0;

    protected:
        QString m_fileName;
        QFile m_logFile;
        QTextStream m_stream;
        std::string typeToString(LogType logType);
};

#endif // LOGGER_H
