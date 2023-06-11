#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QButtonGroup *bttGroup = new QButtonGroup(this);
    bttGroup->addButton(ui->winkBox);
    bttGroup->addButton(ui->mackBox);
    bttGroup->addButton(ui->linuxBox);

    bttGroup->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_winkBox_toggled(bool checked)
{
    if(checked==true)
    {
        qDebug()<<"Window is checked";
    }
    else qDebug()<<"Window is unchecked";

}


void Widget::on_radioButton_toggled(bool checked)
{
    if(checked==true)
    {
        qDebug()<<" A is checked";
    }
    else qDebug()<<"A is unchecked";
}


void Widget::on_winkBox_3_toggled(bool checked)
{
    if(checked==true)
    {
        qDebug()<<" STM is checked";
    }
    else qDebug()<<"STM is unchecked";
}


void Widget::on_pushButton_clicked()
{
    if(ui->winkBox->isChecked())
        qDebug()<<"Window is submitted";
    else
        qDebug()<<"Window is unsubmitted";
}


void Widget::on_pushButton_2_clicked()
{
    //Exclusive
    if(ui->winkBox->isChecked())
        ui->winkBox->setChecked(false);
    else ui->winkBox->setChecked(true);
    //NonExclusive
    if(ui->winkBox_3->isChecked())
        ui->winkBox_3->setChecked(false);
    else ui->winkBox_3->setChecked(true);
}

