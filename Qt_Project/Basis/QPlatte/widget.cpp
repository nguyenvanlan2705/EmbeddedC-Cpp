#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
    //retrieve the color
    QPalette palette = ui->label->palette();
    // modify the color
    palette.setColor(QPalette::Window, Qt::blue);
    palette.setColor(QPalette::WindowText, Qt::red);
    // reset the color
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui-> activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disableButtonColorGroup = ui-> disableButton_2->palette().currentColorGroup();
    qDebug()<<"Active color group"<<activeButtonColorGroup;
    qDebug()<<"Disable color group"<<disableButtonColorGroup;

}

