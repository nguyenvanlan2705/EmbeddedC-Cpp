#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QLabel>
#include <QPixmap>

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


void Widget::on_pushButton_clicked()
{
    //getExistingDirectory
    /*QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                        | QFileDialog::DontResolveSymlinks);
    qDebug()<<"Your chosen dir is "<<dir;*/

    //getOpenFileName
    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    qDebug()<<"Your chosen dir is "<<fileName;
    //show image
    QLabel *label = new QLabel(this);
    QPixmap pixmap(fileName);
    label-> move(100, 100);
    label->setScaledContents(true);
    label ->setPixmap(pixmap.scaled(40,40));
    label-> show();
    */

    // Select one or more files to open (getOpenFileNames)
    /*QStringList files = QFileDialog::getOpenFileNames(
                        this,
                        "Select one or more files to open",
                        "/home",
                        "Images (*.png *.xpm *.jpg)");
    qDebug()<<"Your chosen files are "<<files;*/

    //getSaveFileName
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/jana/untitled.png",
                                                    tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"));
    qDebug()<<"Your chosen files is "<<fileName;
}

