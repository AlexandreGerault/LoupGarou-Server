#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <memory>
#include "commandmanager.h"
#include "locator.h"
#include "server.h"
#include "mmi.h"

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
