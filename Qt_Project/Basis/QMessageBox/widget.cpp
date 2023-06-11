#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QPushButton"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btt = new QPushButton(this);
    btt->setText("Click me");
    btt->move(250, 250);
    connect(btt, &QPushButton::clicked, [=](){
//        QMessageBox *message = new QMessageBox(this);

//        message->setMinimumSize(500,300);
//        message->setWindowTitle("Clicky");
//        message->setIcon(QMessageBox::Critical);
//        message->setText("Hello0");
//        message-> setInformativeText("You just Cliked me! \n You just Cliked me!");
//        message-> setStandardButtons(QMessageBox::Yes|QMessageBox::No);
//        message -> setDefaultButton(QMessageBox::Yes);
//        int ret= message->exec();
        //int ret= QMessageBox::critical(this, "Clicky !", "You just Cliked me!", QMessageBox::Yes|QMessageBox::No);
        //int ret= QMessageBox::information(this, "Clicky !", "You just Cliked me!", QMessageBox::Yes|QMessageBox::No);
        //int ret= QMessageBox::warning(this, "Clicky !", "You just Cliked me!", QMessageBox::Yes|QMessageBox::No);
        int ret= QMessageBox::question(this, "Clicky !", "You just Cliked me!", QMessageBox::Yes|QMessageBox::No);
        if(ret== QMessageBox::Yes)
        {
            qDebug()<<"clicked Yes";
        }
        else qDebug()<<"clicked No";

    });
}

Widget::~Widget()
{
    delete ui;
}

