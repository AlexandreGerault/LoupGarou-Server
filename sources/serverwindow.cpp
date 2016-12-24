#include "includes/serverwindow.h"

ServerWindow::ServerWindow()
{
    setupUi(this);

    m_server = new Server;

    QString labelContent("État du serveur : ");
    if(m_server->isStarted())
        labelContent += "<span style=\"color: green;\">ON</span>";
    else
        labelContent += "<span style=\"color: red;\">OFF</span>";

    m_serverStateLabel->setText(labelContent);

    connect(m_sendCommandButton, SIGNAL(clicked()), this, SLOT(sendCommand()));
    connect(m_commandLineEditor, SIGNAL(returnPressed()), this, SLOT(sendCommand()));
    connect(m_server, SIGNAL(serverStateChange()), this, SLOT(onServerStateChange()));
    connect(m_server, SIGNAL(log(QString, LogType)), this, SLOT(onLog(QString, LogType)));
    connect(m_startButton, SIGNAL(clicked(bool)), this, SLOT(onStartServerButtonClicked()));
    connect(m_stopButton, SIGNAL(clicked(bool)), this, SLOT(onStopServerButtonClicked()));
    connect(m_clearButton, SIGNAL(clicked(bool)), this, SLOT(onClearButtonClicked()));
    connect(m_logsList, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChanged()));

    m_commandLineEditor->setFocus();
}

void ServerWindow::onLog(QString message, LogType c)
{
    writeALog(message, c);
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
    QString message = "<span style=\"" + style + "\"> " + log + "</span><br />";

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
        Command *cmd = m_server->getCommandManager().getCommand(cmdArgs.at(0));
        cmd->execute(m_server);
    }
    catch(QString e)
    {
        writeALog(e, LogType::Error);
    }
}

void ServerWindow::onServerStateChange()
{
    QString labelContent("État du serveur : ");
    if(m_server->isStarted())
        labelContent += "<span style=\"color: green;\">ON</span>";
    else
        labelContent += "<span style=\"color: red;\">OFF</span>";

    m_serverStateLabel->setText(labelContent);

}

void ServerWindow::onStartServerButtonClicked()
{
    m_server->startServer();
}
void ServerWindow::onStopServerButtonClicked()
{
    m_server->stopServer();
}
void ServerWindow::onClearButtonClicked()
{
    m_logsList->clear();
}
void ServerWindow::onCursorPositionChanged()
{
}

ServerWindow::~ServerWindow()
{
    delete m_server;
}


