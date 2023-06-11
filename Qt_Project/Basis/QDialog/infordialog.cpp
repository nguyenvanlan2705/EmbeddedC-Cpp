#include "infordialog.h"
#include "ui_infordialog.h"

InforDialog::InforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InforDialog)
{
    ui->setupUi(this);
}

InforDialog::~InforDialog()
{
    delete ui;
}

void InforDialog::on_okButton_clicked()
{
    //colect information
    QString userPosition = ui->PoslineEdit->text();
    if(!userPosition.isEmpty())
    {
        this->position= userPosition;
        if(ui->windowRadioButton->isChecked())
        {
            this->favoriteOs= "Window";
        }
        if(ui->macRadioButton->isChecked())
        {
            this->favoriteOs= "Mac";
        }
        if(ui->linuxRadioButton->isChecked())
        {
            this->favoriteOs= "Linux";
        }

    }
    //
    accept();
}


void InforDialog::on_cancelButton_clicked()
{
    reject();
}

QString InforDialog::getFavoriteOs() const
{
    return favoriteOs;
}

QString InforDialog::getPosition() const
{
    return position;
}

