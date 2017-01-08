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

class Logger : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Logger)

    public:
        static Logger* Instance();
        static void kill();

        bool openLogFile();
        bool closeLogFile();
        void log(QString log, LogType logType);

    signals:
        void logging(QString, LogType);

    public slots:
        void writeToLogFile(QString log);

    private:
        Logger();
        ~Logger(){};

        static Logger *m_pInstance;
        QFile m_logFile;
        QTextStream m_stream;
};

#endif // LOGGER_H
