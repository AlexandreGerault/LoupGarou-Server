#include "includes/serverwindow.h"

ServerWindow::ServerWindow() : Server()
{
    setupUi(this);

    connect(m_sendCommandButton, SIGNAL(clicked()), this, SLOT(sendCommand()));
    connect(m_commandLineEditor, SIGNAL(returnPressed()), this, SLOT(sendCommand()));

    m_commandLineEditor->setFocus();
}

void ServerWindow::writeALog(const QString &log, LogType c)
{
    QString type = "unknown", style;

    switch(c)
    {
        case LogType::Info:
            type = "info";
            style = "color: black;";
        break;

        case LogType::Error:
            type = "error";
            style = "color: red;";
        break;

        case LogType::Send:
            style = "color: black;";
            type = "command";
        break;

        case LogType::Warning:
            style = "color: orange;";
            type = "warning";
        break;
    }
    QString message = "<span style=\"" + style + "\">[" + type.toUpper() + "] " + log + "</span><br />";

    m_logsList->insertHtml(message);
}

void ServerWindow::sendCommand()
{
    QString command = m_commandLineEditor->text();

    writeALog(command, LogType::Send);
    m_commandLineEditor->clear();

    QStringList cmdArgs = command.split("[ ]");

    try
    {
        Command *cmd = m_commandManager.getCommand(cmdArgs.at(0));
        cmd->execute(this);
    }
    catch(QString e)
    {
        writeALog(e, LogType::Error);
    }
}

ServerWindow::~ServerWindow()
{
}
