#include "lib/UI/include/mmi.h"

MMI::MMI()
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
}

void MMI::readCommand()
{
    std::string inputCommand;
    std::getline(std::cin, inputCommand);
    emit commandReceived(inputCommand);
}
