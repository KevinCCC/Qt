#include "delaythread.h"
DelayThread::DelayThread(QObject *parent) :
    QThread(parent)
{
}
DelayThread::DelayThread(long delayTime) {
    this->delayTime=delayTime;
}

void DelayThread::run(){
    if(!delayTime) return;
    sleep(delayTime);
    emit stopDelay();   //发送信号
}
