#include "customdialog.h"
#include "ui_customdialog.h"

CustomDialog::CustomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: red; color: yellow");
}

CustomDialog::~CustomDialog()
{
    delete ui;
}
