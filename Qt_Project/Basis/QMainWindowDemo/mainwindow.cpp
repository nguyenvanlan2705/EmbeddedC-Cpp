#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QMenuBar"
#include "QStatusBar"
#include <QAction>
//#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Add central widget
    //QPixmap icon("QMainWindowDemo\Icon\play-button.png");
    QPushButton *btt = new QPushButton("Click me");
    //btt->setIcon(QIcon(icon));
    //btt->show();
    setCentralWidget(btt);
    //Declare action
    QAction *quitAction = new QAction("Quit");
    connect(quitAction, QAction::triggered, [=](){
        this->close();
    });
    //Add menu bar
    QMenu *fileMenu= menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    QMenu *editMenu= menuBar()->addMenu("Edit");
    QMenu *windowMenu= menuBar()->addMenu("Window");
    QMenu *settingMenu= menuBar()->addMenu("Setting");
    QMenu *helpMenu= menuBar()->addMenu("Help");

    //Add status bar
    statusBar()->showMessage("Uploading.....",1000); // Display 1s
    //statusBar()->clearMessage();

}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(200,200);
}

