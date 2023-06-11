#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int i=0; i<9; i++)
    {
        colorList.append( Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton1_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[0]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton1->setStyleSheet(css);
    }
}


void Widget::on_pushButton2_clicked()
{
    QColor color = QColorDialog::getColor(colorList[1], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[1]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton2->setStyleSheet(css);
    }
}


void Widget::on_pushButton3_clicked()
{
    QColor color = QColorDialog::getColor(colorList[2], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[2]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton3->setStyleSheet(css);
    }
}


void Widget::on_pushButton4_clicked()
{
    QColor color = QColorDialog::getColor(colorList[3], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[3]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton4->setStyleSheet(css);
    }
}


void Widget::on_pushButton5_clicked()
{
    QColor color = QColorDialog::getColor(colorList[4], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[4]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton5->setStyleSheet(css);
    }
}


void Widget::on_pushButton6_clicked()
{
    QColor color = QColorDialog::getColor(colorList[5], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[5]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton6->setStyleSheet(css);
    }
}


void Widget::on_pushButton7_clicked()
{
    QColor color = QColorDialog::getColor(colorList[6], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[6]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton7->setStyleSheet(css);
    }
}


void Widget::on_pushButton8_clicked()
{
    QColor color = QColorDialog::getColor(colorList[7], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[7]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton8->setStyleSheet(css);
    }
}


void Widget::on_pushButton9_clicked()
{
    QColor color = QColorDialog::getColor(colorList[8], this, "Choose background color");
    if(color.isValid())
    {
        //save the color in memory
        colorList[8]= color;
        //set background color to button 1
        QString css= QString("background-color: %1") .arg(color.name());
        ui->pushButton9->setStyleSheet(css);
    }
}


void Widget::on_loadButton_clicked()
{
    setLoadedColor("button1",0, ui->pushButton1);
    setLoadedColor("button2",1, ui->pushButton2);
    setLoadedColor("button3",2, ui->pushButton3);
    setLoadedColor("button4",3, ui->pushButton4);
    setLoadedColor("button5",4, ui->pushButton5);
    setLoadedColor("button6",5, ui->pushButton6);
    setLoadedColor("button7",6, ui->pushButton7);
    setLoadedColor("button8",7, ui->pushButton8);
    setLoadedColor("button9",8, ui->pushButton9);
}


void Widget::on_saveButton_clicked()
{
    saveColor("button1", colorList[0]);
    saveColor("button2", colorList[1]);
    saveColor("button3", colorList[2]);
    saveColor("button4", colorList[3]);
    saveColor("button5", colorList[4]);
    saveColor("button6", colorList[5]);
    saveColor("button7", colorList[6]);
    saveColor("button8", colorList[7]);
    saveColor("button9", colorList[8]);
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green= color.green();
    int blue = color. blue();

    QSettings settings("NVL", "SettingsColor");
    settings.beginGroup("ButtonColor");
    settings.setValue(key+"r", red);
    settings.setValue(key+"g", green);
    settings.setValue(key+"b", blue);
    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("NVL", "SettingsColor");
    settings.beginGroup("ButtonColor");
    red= settings.value(key+"r", QVariant(0)).toInt();
    green= settings.value(key+"g", QVariant(0)).toInt();
    blue= settings.value(key+"b", QVariant(0)).toInt();
    settings.endGroup();
    return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    colorList[index]= color;
    QString css= QString("background-color: %1") .arg(color.name());
    button->setStyleSheet(css);
}

