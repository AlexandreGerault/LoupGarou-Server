#include "includes/application.h"

Application::Application() : m_server()
{
    Locator::initialize();
    Logger *nw = new NetworkLogger();
    Locator::provide(nw);
}
