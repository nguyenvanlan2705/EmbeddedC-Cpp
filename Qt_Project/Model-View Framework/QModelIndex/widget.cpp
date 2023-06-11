#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model= new QFileSystemModel(this);
    parentIndex = model->setRootPath("D:/STM32-Tutorials");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int rowCount = model->rowCount(parentIndex);
    qDebug()<<"Row Count: "<<QString::number(rowCount);
    for(int i=0; i<rowCount; i++)
    {
        QModelIndex index =model->index(i, 0, parentIndex);
        QString data= model->data(index, Qt::DisplayRole).toString();
        qDebug()<<"Data item ["<<QString::number(i) << "] "<<data;
    }
}

