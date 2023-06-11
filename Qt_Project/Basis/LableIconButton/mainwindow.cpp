#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelButton->setText("<a href='https'>Click me!</a>");
    ui->labelButton->setOpenExternalLinks(false);
    ui->labelButton->setCursor(Qt::PointingHandCursor);
    connect(ui->labelButton, &QLabel::linkActivated, this, &MainWindow::on_labelButton_linkActivated);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_labelButton_linkActivated(const QString &link)
{
    qDebug() << "Clicked on label with link: " << link;
    this -> close();
}

