#ifndef NETWORKLOGGER_H
#define NETWORKLOGGER_H

#include "includes/logger.h"

class NetworkLogger : public Logger
{
public:
    NetworkLogger();
    void log(QString log, LogType logType) override;
};

#endif // NETWORKLOGGER_H
