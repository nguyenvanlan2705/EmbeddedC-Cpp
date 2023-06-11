#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QDebug>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_textColorButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::WindowText);
    QColor chooseColor = QColorDialog::getColor(color, this, "choose text color");
    if(chooseColor.isValid())
    {
        palette.setColor(QPalette::WindowText, chooseColor);
        ui->label->setPalette(palette);
        qDebug()<<"User choose a valid color";
    }
    else
    {
        qDebug()<<"User choose a invalid color";
    }
}


void Widget::on_backGroundButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::Window);
    QColor chooseColor = QColorDialog::getColor(color, this, "choose text color");
    if(chooseColor.isValid())
    {
        palette.setColor(QPalette::Window, chooseColor);
        ui->label->setPalette(palette);
        qDebug()<<"User choose a valid color";
    }
    else
    {
        qDebug()<<"User choose a invalid color";
    }
}


void Widget::on_fontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
        &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        ui->label->setFont(font);
    } else {
    }
}

