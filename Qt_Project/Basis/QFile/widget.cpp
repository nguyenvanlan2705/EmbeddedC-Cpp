#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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


void Widget::on_writeButton_clicked()
{
    //Save file to disk
    QString filename= QFileDialog::getSaveFileName(this, "Save as");
    if(filename.isEmpty())
    {
        return ;
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text |QIODevice::Append)){
        return;
    }
    QTextStream out(&file);
    out<< ui->textEdit->toPlainText()<<"\n";
    file.close();
}


void Widget::on_readButton_clicked()
{
    QString fileContent;
    QString filename= QFileDialog::getOpenFileName(this, "Open File");
    if(filename.isEmpty())
    {
        return ;
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        fileContent.append(line);
    }
    file.close();
    ui->textEdit->clear();
    ui->textEdit->setText(fileContent);
}


void Widget::on_selectFileButton_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, "Select file");
    if(filename.isEmpty())
    {
        return ;
    }
    ui->srcLineEdit->setText(filename);
}


void Widget::on_copyButton_clicked()
{
    QString srcFile = ui->srcLineEdit->text();
    QString desFile = ui->desLineEdit->text();

    if(srcFile.isEmpty()||desFile.isEmpty()) return;
    QFile file(srcFile);
    if(file.copy(desFile))
    {
        QMessageBox::information(this, "Success", "Successful");
    }
    else
    {
        QMessageBox::information(this, "Failure", "Copy fail");
    }
}

