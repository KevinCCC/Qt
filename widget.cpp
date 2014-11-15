#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include "delaythread.h"
#include <time.h>
#include <windows.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked,this, &Widget::init);
    connect(ui->helpButton, &QPushButton::clicked,this, &Widget::help);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init(){
    QRegExp rxDate("^[0-9]{4}-(((0[13578]|(10|12))-(0[1-9]|[1-2][0-9]|3[0-1]))|(02-(0[1-9]|[1-2][0-9]))|((0[469]|11)-(0[1-9]|[1-2][0-9]|30)))$");
    QRegExp rxTime("^(([1-9]{1})|([0-1][0-9])|([1-2][0-3])):([0-5][0-9])$");
    QRegExp rxNum("^[0-9].*$");
    QString date=ui->dateText->text().trimmed();
    QString time=ui->timeText->text().trimmed();
    QString delay=ui->delayText->text().trimmed();
    if(!rxDate.exactMatch(date)){
        QMessageBox::information(this,"注意","日期输入格式不正确！（如2012-12-21）");
    }else if(!rxTime.exactMatch(time)){
        QMessageBox::information(this,"注意","时间输入格式不正确！（如12:00）");
    }else if(!rxNum.exactMatch((delay))){
        QMessageBox::information(this,"注意","延迟时间请正确输入！（可以是小数）");
    }else{
        ui->addButton->setText("已启动");
        ui->addButton->setEnabled(false);
        QStringList qlDate=date.split("-");  //日期
        QStringList qlTime=time.split(":");    //时间
        year=qlDate.at(0).toInt();
        month=qlDate.at(1).toInt();
        day=qlDate.at(2).toInt();
        hour=qlTime.at(0).toInt();
        minute=qlTime.at(1).toInt();
        DelayThread *dt=new DelayThread((long)(delay.toDouble()*3600));
        connect(dt, &DelayThread::stopDelay,this, &Widget::setTime);
        dt->start();
    }
}

void Widget::setTime(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    st.wYear=year;
    st.wMonth=month;
    st.wDay=day;
    st.wHour=hour;
    st.wMinute=minute;
    SetLocalTime(&st);
    ui->addButton->setEnabled(true);
    ui->addButton->setText("启动");
}

void Widget::help(){
    QMessageBox::information(this,tr("帮助(1.1)"),"<p>1.时间日期格式（2012-12-21 12:00）</p><p>2.请分别输入到两个文本框中</p><p>3.延迟时间单位为小时，可以输入小数</p><p>4.多次设定可以开启多个</p><p>by <a href='http://weibo.com/dryheart'>DryHeart</a> 2014-11-11</p>");
}
