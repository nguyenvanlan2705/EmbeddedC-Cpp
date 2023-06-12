#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;
    mDataBuffer = new QByteArray();

    //Define net request
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.qt.io"));

    netReply = netManager->get(request);
    connect(netReply, &QIODevice::readyRead, this, &Widget::dataReadytoRead);
    connect(netReply,&QNetworkReply::finished, this ,&Widget::dataReadFinished);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::dataReadytoRead()
{
    qDebug()<<"Some data available";
    mDataBuffer->append(netReply->readAll());
}

void Widget::dataReadFinished()
{
    if(netReply->error())
    {
        qDebug()<<"Error: "<<netReply->errorString();
    }
    else
    {
        ui->textEdit->setPlainText(QString(*mDataBuffer));
    }
}

