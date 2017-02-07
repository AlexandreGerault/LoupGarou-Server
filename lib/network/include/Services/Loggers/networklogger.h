#ifndef NETWORKLOGGER_H
#define NETWORKLOGGER_H

#include "lib/core/include/logger.h"

class NetworkLogger : public Logger
{
public:
    NetworkLogger();
    void log(std::string log, LogType logType) override;
};

#endif // NETWORKLOGGER_H
