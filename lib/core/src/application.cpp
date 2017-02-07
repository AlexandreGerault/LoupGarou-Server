#include "lib/core/include/application.h"

Application *Application::m_instance = NULL;

Application::Application()
{
}

void Application::run()
{
    try{m_server = new Server();}
    catch(std::string message){std::cout << message;}
    std::cout << "Serveur créé" << std::endl;
    m_commandManager = new CommandManager();
    std::cout << "CommandManager créé" << std::endl;
    m_console = new MMI();
    std::cout << "IHM créé" << std::endl;
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
