#include "mainwindow.h"
#include <QDebug>
#include <QString>
#include <QApplication>

QString str = "Hello world";
int i=10;
QString str1;
QString str2="127854";
int num;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    str1= QString::number(i);
    num= str2.toDouble();
    qDebug()<< str2<<"\n"; //chuỗi sang số
    qDebug()<< str1<<"\n"; // số san chuỗi
    qDebug()<< str;
    w.show();
    return a.exec();
}
