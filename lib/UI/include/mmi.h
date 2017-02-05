#ifndef MMI_H
#define MMI_H

#include <iostream>
#include <QObject>
#include <QSocketNotifier>

class MMI : public QObject
{
    Q_OBJECT

    public:
        MMI();
    public slots:
        void readCommand();
    signals:
        void commandReceived(std::string);
    private:
        QSocketNotifier *m_notifier;

};

#endif // MMI_H
