#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemButt_clicked()
{
    ui->listWidget->addItem("My Item");
}


void Widget::on_delItemButt_clicked()
{
    // Delete Item : use takeItem
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}


void Widget::on_selectItemButt_clicked()
{
    // Get the list of selected items
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    for(int i=0; i<list.count(); i++)
        qDebug()<<list.at(i)->text()<<" row: "<<ui->listWidget->row(list.at(i));
}

