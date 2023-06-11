#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Clicked Signal
    QFont btFont("Times", 20, QFont::Bold);
    QPushButton *btt= new QPushButton("Bt0", this);
    btt->setMinimumSize(200, 100);
    btt->setFont(btFont);
    btt->move(205, 0);
    connect(btt, &QPushButton::clicked, [=](){
        qDebug()<<"Button0 Clicked";
    });

    //Pressed Signal
    QPushButton *btt1= new QPushButton("Bt1", this);
    btt1->setMinimumSize(200, 100);
    btt1->setFont(btFont);
    btt1->move(205, 150);
    connect(btt1, &QPushButton::pressed, [=](){
        qDebug()<<"Button1 Pressed";
    });

    //Released Signal
    QPushButton *btt2= new QPushButton("Bt2", this);
    btt2->setMinimumSize(200, 100);
    btt2->setFont(btFont);
    btt2->move(205, 300);
    connect(btt2, &QPushButton::released, [=](){
        qDebug()<<"Button2 Released";
    });
}

Widget::~Widget()
{
    delete ui;
}

