#ifndef LOGGER_H
#define LOGGER_H

#include <QWidget>
#include <QDateTime>
#include <QTextStream>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QTimer>

enum class LogType {Info, Warning, Error, Send, Data};

class Logger
{
    public:
        Logger(QString fileName);
        virtual ~Logger() = default;

        virtual void log(QString log, LogType logType) = 0;

    protected:
        QString m_fileName;
        QFile m_logFile;
        QTextStream m_stream;
        QString typeToString(LogType logType);
};

#endif // LOGGER_H
