#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "MessageBox", "Hello");
}


void MainWindow::on_pushButton_2_clicked()
{
    if(QMessageBox::question(this, "Mess2", "Hi, Are you fine ?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        this->setWindowTitle("Yes");
    }
    else
    {
        this->setWindowTitle("No");
    }
}

