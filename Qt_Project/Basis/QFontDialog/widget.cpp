#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QMessageBox"
#include "QFontDialog"

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
    bool ok;
    QFont font = QFontDialog::getFont(
        &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        ui->label->setFont(font);
    } else {
        QMessageBox::information(this,"Message", "User did not choose this font");
    }
}

