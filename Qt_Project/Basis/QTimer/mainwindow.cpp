#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>
#include <QDebug>
QTimer *qtimer;
int count =0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qtimer = new QTimer(this);
    qtimer->setInterval(1000);
    connect(qtimer, SIGNAL(timeout()),SLOT(countTimer()));
    qtimer->start();
}
void MainWindow::countTimer()
{
    count ++;
    if(count!=20)
    ui->label->setText(QString::number(count));
    else this->close();
    qDebug()<<count;
}
MainWindow::~MainWindow()
{
    delete ui;
}


