#include "includes/application.h"

Application *Application::m_instance = NULL;

Application::Application()
{
    m_console = new MMI();
    m_commandManager = new CommandManager();
    m_server = new Server();
    connect(m_console, &MMI::commandReceived, m_commandManager, &CommandManager::commandProcess);
}

Application* Application::getInstance()
{
    if(m_instance == NULL)
        m_instance = new Application();

    return m_instance;
}

void Application::kill()
{
    if(m_instance != NULL)
    {
        delete m_instance;
        m_instance = NULL;
    }
}

CommandManager* Application::commandManager() const
{
    return m_commandManager;
}

Server* Application::getServer() const
{
    return m_server;
}

Application::~Application()
{

}
