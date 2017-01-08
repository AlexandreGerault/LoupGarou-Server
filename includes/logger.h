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

enum class LogType {Info, Warning, Error, Send};

class Logger : public QObject
{
    Q_OBJECT

    public:
        static Logger* Instance();
        static void kill();

        bool openLogFile(std::string logFile);
        bool closeLogFile();
        void log(QString log, LogType logType);

    signals:
        void logging(QString, LogType);

    public slots:
        void writeToLogFile(QString log, LogType logType);

    private:
        Logger();
        ~Logger(){};

        Logger(Logger const&){};
        Logger& operator=(Logger const&){}

        static Logger *m_pInstance;
        QFile m_logFile;
        QTextStream m_stream;
};

#endif // LOGGER_H
