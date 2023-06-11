#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("://Images/173986_minion_happy_icon.png");
    ui->label->setPixmap(pixmap);
//    QPixmap copyIcon("://Images/8530597_copy_icon.png");
//    ui->actionCopy->setIcon(copyIcon); //đặt icon thủ công

}

MainWindow::~MainWindow()
{
    delete ui;
}

