#ifndef LOCATOR_H
#define LOCATOR_H

#include "lib/core/include/logger.h"
#include "lib/core/include/Services/Loggers/nulllogger.h"
#include "lib/network/include/Services/Loggers/networklogger.h"

class Locator
{
public:
    static void initialize()
    {
        m_service = &nullService();
    }
    static Logger* getLogger()
    {
        return m_service;
    }
    static void provide(Logger* service)
    {
        if (service == NULL)
            m_service = &nullService();
        else
            m_service = service;
    }

private:
    static Logger *m_service;
    static Logger& nullService();
};

#endif // LOCATOR_H
