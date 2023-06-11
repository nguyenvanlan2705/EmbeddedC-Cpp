#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QFileInfo>

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


void Widget::on_chooseDirButton_clicked()
{
    QString foldername = QFileDialog::getExistingDirectory(this, "Choose foler");
    if(foldername.isEmpty())
        return;
    ui->lineEdit->setText(foldername);
}


void Widget::on_creatDirButton_clicked()
{
    //Creat a folder if it doesn't exist
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty()) return;
    QDir dir(dirPath);
    if(!dir.exists())
    {
        if(dir.mkpath(dirPath))
        {
            QMessageBox::information(this, "Message", "Dir created");
        }
    }
    else
    {
        QMessageBox::information(this, "Message", "Dir already exists");
    }
}


void Widget::on_dirExistButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;
    QDir dir(dirPath);
    if(!dir.exists())
    {
        QMessageBox::information(this, "Message", "Dir doesn't exists");
    }
    else
    {
        QMessageBox::information(this, "Message", "Dir already exists");
    }
}





void Widget::on_folderContentButton_clicked()
{
    ui->listWidget->clear();
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;
    QDir dir(dirPath);
    // Get the list of file in the forlder
    QList<QFileInfo> listFile = dir.entryInfoList();
    for(int i=0; i< listFile.size(); i++)
    {
        QString prefix;
//        if(listFile.at(i).isFile())
//        {
//            prefix = "FILE: ";
//        }
//        if(listFile.at(i).isDir())
//        {
//            prefix = "DIRECTORY: ";
//        }

        ui->listWidget->addItem(prefix+ listFile.at(i).absoluteFilePath());
    }
}
void Widget::on_dirOrFileButton_clicked()
{
    //check file or dir
    QFileInfo fileInfo (ui->listWidget->currentItem()->text());
    if(fileInfo.isDir())
    {
        QMessageBox::information(this, "Message", "This is a dir");
    }
    else if(fileInfo.isFile())
    {
        QMessageBox::information(this, "Message", "This is a file");
    }
    else
    {
        QMessageBox::information(this, "Message", "Something else");
    }
}
