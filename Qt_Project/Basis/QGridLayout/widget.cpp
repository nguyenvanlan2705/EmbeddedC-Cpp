#include "widget.h"
#include "ui_widget.h"
#include "QGridLayout"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout *glayout = new QGridLayout(this);
    glayout -> addWidget(ui->b1,0,0);
    glayout -> addWidget(ui->b2,0,1);
    glayout -> addWidget(ui->b3,0,2);
    glayout -> addWidget(ui->b4,1,0);
    glayout -> addWidget(ui->b5,1,1);
    glayout -> addWidget(ui->b6,1,2);
    glayout -> addWidget(ui->b7,2,0);
    glayout -> addWidget(ui->b8,2,1);
    glayout -> addWidget(ui->b9,2,2);
}

Widget::~Widget()
{
    delete ui;
}

