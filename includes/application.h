#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "locator.h"
#include "server.h"

class Application
{
    public:
        Application();

    private:
        std::unique_ptr<Server> m_server;
};

#endif // APPLICATION_H
