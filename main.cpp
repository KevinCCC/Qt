#include "widget.h"
#include <QApplication>
#include <time.h>
#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(360,115);
    w.show();
    return a.exec();
}
