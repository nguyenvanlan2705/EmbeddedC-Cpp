#include "widget.h"
#include "ui_widget.h"
#include "QPixmap"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap image("://Image/minion.jpg");
    ui->labelImage->setScaledContents(true);
    ui->labelImage->setPixmap(image.scaled(400,400));
}

Widget::~Widget()
{
    delete ui;
}

