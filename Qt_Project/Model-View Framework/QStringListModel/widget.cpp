#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    QStringList list;
    list <<"Cow" <<"Rooster"<<"Hyena"<< "Bufferlo";
    model->setStringList(list);
    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QStringList data = model->stringList();
    qDebug()<<"The current data" << data;
}

