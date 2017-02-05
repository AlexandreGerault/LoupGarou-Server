#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <memory>
#include "lib/UI/include/commandmanager.h"
#include "lib/core/include/locator.h"
#include "lib/network/include/server.h"
#include "lib/UI/include/mmi.h"

class Application : public QObject
{
    Q_OBJECT

    public:
        Application();
        static Application* getInstance();
        static void kill();
        ~Application();

        /***********
         * GETTERS *
         ***********/
        Server *getServer() const;
        CommandManager* commandManager() const;
    private:
        static Application *m_instance;
        Server* m_server;
        MMI *m_console;
        CommandManager *m_commandManager;

};

#endif // APPLICATION_H
