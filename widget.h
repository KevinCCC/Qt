#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    int year;
    int month;
    int day;
    int hour;
    int minute;
public slots:
    void init();
    void setTime();
    void help();
};

#endif // WIDGET_H
