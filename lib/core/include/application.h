/**
 * @file        /lib/core/include/application.h
 * @author      alexan14
 * @version     1.0
 * @date        05 Janvier 2017
 * @brief       Classe centrale de toute l'application
 *
 * @details     Cette classe représente l'application et utilise les modules de celles-ci.
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "lib/UI/include/commandmanager.h"
#include "lib/core/include/locator.h"
#include "lib/network/include/server.h"
#include "lib/UI/include/mmi.h"

class Application
{
    public:
        Application();
        static Application* getInstance();
        static void kill();
        ~Application();
        void run();

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
