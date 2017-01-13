#ifndef LOCATOR_H
#define LOCATOR_H

#include "includes/logger.h"
#include "includes/Services/Loggers/networklogger.h"
#include "includes/Services/Loggers/nulllogger.h"

class Locator
{
public:
    static void initialize()
    {
        m_service = &m_nullService;
    }
    static Logger* getLogger()
    {
        return m_service;
    }
    static void provide(Logger* service)
    {
        if (service == NULL)
            m_service = &m_nullService;
        else
            m_service = service;
    }

private:
    static Logger *m_service;
    static NullLogger m_nullService;
};

#endif // LOCATOR_H
