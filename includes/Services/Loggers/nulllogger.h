#ifndef NULLLOGGER_H
#define NULLLOGGER_H

#include "includes/logger.h"

class NullLogger : public Logger
{
public:
    NullLogger();
    void log(QString log, LogType logType) override;
};

#endif // NULLLOGGER_H
