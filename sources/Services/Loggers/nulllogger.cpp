#include "includes/Services/Loggers/nulllogger.h"

NullLogger::NullLogger() : Logger("null.log")
{

}

void NullLogger::log(QString log, LogType logType)
{

}
