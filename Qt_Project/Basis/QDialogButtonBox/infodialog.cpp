#include "infodialog.h"
#include "ui_infodialog.h"
#include <infodialog.h>

#include <QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButt = ui->buttonBox->standardButton(button);
    if(stdButt== QDialogButtonBox::Ok)
    {
        qDebug()<<"Ok button is clicked";
        accept();
    }
    if(stdButt== QDialogButtonBox::Yes)
    {
        qDebug()<<"Yes button is clicked";
    }
    if(stdButt== QDialogButtonBox::No)
    {
        qDebug()<<"No button is clicked";
    }
    if(stdButt== QDialogButtonBox::Save)
    {
        qDebug()<<"Save button is clicked";
    }
    if(stdButt== QDialogButtonBox::Open)
    {
        qDebug()<<"Open button is clicked";
    }
    if(stdButt== QDialogButtonBox::Cancel)
    {
        qDebug()<<"Cancel button is clicked";
        reject();
    }

}

