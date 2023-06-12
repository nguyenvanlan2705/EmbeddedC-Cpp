#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);

    //capture the root item
    QStandardItem *rootItem = model->invisibleRootItem();
    //defining a couple of items
    QStandardItem *africaItem = new QStandardItem("Africa");
    QStandardItem *rwandaItem = new QStandardItem("rwanda");
    QStandardItem *musanzeItem = new QStandardItem("musanze");
    QStandardItem *kigaliItem = new QStandardItem("kigali");
    QStandardItem *ugandaItem = new QStandardItem("uganda");
    QStandardItem *kampalaItem = new QStandardItem("kampala");
    QStandardItem *entebbeItem = new QStandardItem("entebbe");
    QStandardItem *asiaItem  = new QStandardItem("Asia");
    QStandardItem *chinaItem = new QStandardItem("China");
    QStandardItem *shanghaiItem = new QStandardItem("shanghai");
    QStandardItem *beijingItem = new QStandardItem("beijing");
    QStandardItem *europeItem  = new QStandardItem("europe");
    QStandardItem *franceItem = new QStandardItem("france");
    QStandardItem *parisItem = new QStandardItem("paris");
    QStandardItem *tolouseItem = new QStandardItem("tolouse");

    //define the tre structure

    rootItem->appendRow(africaItem);
    africaItem->appendRow(rwandaItem);
    africaItem->appendRow(ugandaItem);

    rwandaItem->appendRow(kigaliItem);
    rwandaItem->appendRow(musanzeItem);

    ugandaItem->appendRow(kampalaItem);
    ugandaItem->appendRow(entebbeItem);

    rootItem->appendRow(asiaItem);
    asiaItem->appendRow(chinaItem);
    chinaItem->appendRow(shanghaiItem);
    chinaItem->appendRow(beijingItem);

    rootItem->appendRow(europeItem);
    europeItem->appendRow(franceItem);
    franceItem->appendRow(parisItem);
    franceItem->appendRow(tolouseItem);

    ui->treeView->setModel(model);
    ui->treeView->expandAll();
    QItemSelectionModel *select = ui->treeView->selectionModel();
    connect(select, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(selectioChangedSlot(QItemSelection,QItemSelection)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectioChangedSlot(const QItemSelection &oldSelection, const QItemSelection &newSelection)
{
    qDebug()<<"Click something in the tree";
    QModelIndex currentIndex = ui->treeView->selectionModel()->currentIndex();
    QString data = model->data(currentIndex, Qt::DisplayRole).toString();

    //find the hierachy of the selected item
    int hierachy =1;
    QModelIndex seekRoot= currentIndex;
    while(seekRoot!=QModelIndex())
    {
        seekRoot = seekRoot.parent();
        hierachy++;
    }
    QString dataShow= QString("%1 level %2").arg(data).arg(QString::number(hierachy));
    setWindowTitle(dataShow);
}

