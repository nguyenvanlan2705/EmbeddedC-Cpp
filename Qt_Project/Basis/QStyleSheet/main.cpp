
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set style sheet application wise
    //a.setStyleSheet("QPushButton{color: red; backgound-color : white;}");

    Widget w;
    w.show();
    return a.exec();
}
