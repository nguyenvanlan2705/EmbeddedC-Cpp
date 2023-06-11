#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Declare the Widget
    QWidget *widget = new QWidget(this);

    // Delare the layout for the widget
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(new QPushButton("Button 1", this));
    layout->addWidget(new QPushButton("Button 2", this));
    layout->addWidget(new QPushButton("Button 3", this));
    QPushButton *button4 = new QPushButton("Button 4", this);
    connect(button4, &QPushButton::clicked,[=](){
        qDebug()<<"Button 4 from custom tab clicked";
    });
    layout->addWidget(button4);
    layout->addSpacerItem(new QSpacerItem(100,200));

    //set the layout to the widget
    widget->setLayout(layout);

    //add the widget to the layout
    ui->tabWidget->addTab(widget,"Tab 4");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<<"Tab1 button clicked";
}

