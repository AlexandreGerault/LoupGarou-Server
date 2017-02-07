#include "lib/core/include/Services/Loggers/nulllogger.h"

NullLogger::NullLogger() : Logger("null.log")
{

}

void NullLogger::log(std::string log, LogType logType)
{

}
