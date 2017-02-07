#include "lib/UI/include/mmi.h"
#include "lib/core/include/application.h"

MMI::MMI()
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    connect(this, &MMI::commandReceived, Application::getInstance()->commandManager(), &CommandManager::commandProcess);
}

void MMI::readCommand()
{
    std::string inputCommand;
    std::getline(std::cin, inputCommand);
    emit commandReceived(inputCommand);
}
