#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

//    ui->setupUi(this);
//    QHBoxLayout *layout = new QHBoxLayout(this);
//    layout->addWidget(ui->b1);
//    layout->addWidget(ui->b2);
//    layout->addWidget(ui->b3);
//    layout->addWidget(ui->b4);
//    layout->addWidget(ui->b5);

//    setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

