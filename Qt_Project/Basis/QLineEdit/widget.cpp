#include "widget.h"
#include "ui_widget.h"
#include "QLineEdit"
#include "QDebug"
#include "QLabel"
#include <QPushButton>
#include <QFont>
#include <QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //First Name
    QLabel *firstNameLable= new QLabel("First Name", this);
    firstNameLable-> setMinimumSize(70,50);
    firstNameLable -> move(10,10);

    QLineEdit *firstNameEdit = new QLineEdit(this);
    firstNameEdit-> setMinimumSize(200,50);
    firstNameEdit->move(100,10);

    //Last Name
    QLabel *lastNameLable= new QLabel("last Name", this);
    lastNameLable-> setMinimumSize(70,50);
    lastNameLable -> move(10,70);

    QLineEdit *lastNameEdit = new QLineEdit(this);
    lastNameEdit-> setMinimumSize(200,50);
    lastNameEdit->move(100,70);

    //City
    QLabel *cityLable= new QLabel("city ", this);
    cityLable-> setMinimumSize(70,50);
    cityLable -> move(10,130);

    QLineEdit *cityEdit = new QLineEdit(this);
    cityEdit-> setMinimumSize(200,50);
    cityEdit->move(100,130);

    //Grab information button
    QFont btFont("Times", 20, QFont::Bold);
    QPushButton *btt= new QPushButton("Grap Data", this);
    btt->setMinimumSize(200, 50);
    btt->setFont(btFont);
    btt->move(80, 190);

    //connect
    connect(btt, &QPushButton::clicked,[=](){
        QString saveFristName = firstNameEdit->text();
        QString saveLastName= lastNameEdit->text();
        QString saveCityName = cityEdit->text();
        //print on Terminal

        if(!(saveFristName.isEmpty() && saveLastName. isEmpty() && saveCityName.isEmpty()))
        {
            qDebug()<< "First Name is: "<< saveFristName;
            qDebug()<< "Last Name is: "<< saveLastName;
            qDebug()<< "City Name is: "<< saveCityName;
        }
        else
            qDebug()<< "Empty Data ! ";
    });

    //Respond Singal
    // cursorPositionChanged
//    connect(firstNameEdit, &QLineEdit::cursorPositionChanged, [=](){
//        qDebug()<<"The current cursor position is: "<< firstNameEdit->cursorPosition();
//    });
    //edittingFinished
//    connect(firstNameEdit, &QLineEdit::editingFinished, [=](){
//        qDebug()<<"Editting Finished !";
//    });
    //returnPressed
//    connect(firstNameEdit, &QLineEdit::returnPressed, [=](){
//        qDebug()<<"Return pressed ";
//    });
    //selectionChanged
//    connect(firstNameEdit, &QLineEdit::selectionChanged, [=](){
//        qDebug()<<"Selection Changed ";
//    });
    //textChanged
//       connect(firstNameEdit, &QLineEdit::textChanged, [=](){
//        qDebug()<<"Text Changed "<<firstNameEdit->text();
//       });
    //textEdited
    connect(firstNameEdit, &QLineEdit::textEdited, [=](){
        qDebug()<<"Text Edited "<<firstNameEdit->text();
    });
    firstNameEdit->setPlaceholderText("fill first name !");
    lastNameEdit->setPlaceholderText("fill last name !");
    cityEdit->setPlaceholderText("fill city name !");
}

Widget::~Widget()
{
    delete ui;
}

