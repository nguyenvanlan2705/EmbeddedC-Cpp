#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Add the planets to the combo box
    ui->comboBox->addItem("Eearth");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Saturn");

    //Make combobox editable
    ui->comboBox->setEditable(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureValButt_clicked()
{
    qDebug()<< "The currently selected item in the combo is"<< ui->comboBox->currentText();
}


void Widget::on_setValButt_clicked()
{
    ui->comboBox->setCurrentIndex(2);
}


void Widget::on_getValButt_clicked()
{
    qDebug()<<"the comboBox currently has "<< ui->comboBox->count()<<"They are: ";
    for(int i=0; i<ui->comboBox->count(); i++)
    {
        qDebug()<<"Index "<<QString::number(i)<<" : "<<ui->comboBox->itemText(i);
    }
}

