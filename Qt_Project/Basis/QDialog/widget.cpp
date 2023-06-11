#include "widget.h"
#include "ui_widget.h"
#include "infordialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_provideInfoButton_clicked()
{
    InforDialog *dialog = new InforDialog(this);
    //int ret = dialog->exec();
    //modal
    /*
    if(ret== QDialog::Accepted)
    {
        QString position = dialog->getPosition();
        QString os = dialog-> getFavoriteOs();

        qDebug()<< "Dialog Accepted, position is: "<<position<<" and the favorite OS is "<<os;
        ui->infoLabel->setText("Your position is "+position + " and the favorite OS is "+ os);
    }
    if(ret== QDialog::Rejected)
    {
        qDebug()<< "Dialog Rejected";
    }
*/
    //non modal
    connect(dialog, &InforDialog::accepted, [=](){

        QString position = dialog->getPosition();
        QString os = dialog-> getFavoriteOs();

        qDebug()<< "Dialog Accepted, position is: "<<position<<" and the favorite OS is "<<os;
        ui->infoLabel->setText("Your position is "+position + " and the favorite OS is "+ os);
    });
    connect(dialog, &InforDialog::rejected, [=](){
        qDebug()<< "Dialog Rejected";
    });

    //Show dialog
    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}

