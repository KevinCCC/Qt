#ifndef DELAYTHREAD_H
#define DELAYTHREAD_H

#include <QThread>

class DelayThread : public QThread
{
    Q_OBJECT
private:
    long delayTime;
public:
    explicit DelayThread(QObject *parent = 0);
    DelayThread(long delayTime);
    virtual void run();
    ~DelayThread(){}
signals:
    void stopDelay();
};

#endif // DELAYTHREAD_H
