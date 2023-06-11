#include "mywidget.h"
#include "QLabel"
#include <QPalette>
myWidget::myWidget(QWidget *parent)
    : QWidget{parent}
{
    QLabel *lable= new QLabel(this);
    lable->setText("This is My Widget");
    setWindowTitle("My Widget");

    QLabel *lable1= new QLabel(this);
    lable1->setText("This is Lable 2");
    lable1->move(0,100);
    QFont label1Font("Times", 14, QFont::Bold);
    lable1->setFont(label1Font);
    QPalette Palete;
    Palete.setColor(QPalette::Window, Qt::yellow);
    Palete.setColor(QPalette::WindowText, Qt::red);
    lable1->setAutoFillBackground(true);
    lable1->setPalette(Palete);
}
