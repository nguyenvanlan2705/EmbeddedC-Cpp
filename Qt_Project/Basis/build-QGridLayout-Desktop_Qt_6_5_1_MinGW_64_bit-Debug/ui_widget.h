/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    QPushButton *b5;
    QPushButton *b6;
    QPushButton *b7;
    QPushButton *b8;
    QPushButton *b9;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 200, 295, 103));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        b1 = new QPushButton(widget);
        b1->setObjectName("b1");

        gridLayout->addWidget(b1, 0, 0, 1, 1);

        b2 = new QPushButton(widget);
        b2->setObjectName("b2");

        gridLayout->addWidget(b2, 0, 1, 1, 1);

        b3 = new QPushButton(widget);
        b3->setObjectName("b3");

        gridLayout->addWidget(b3, 0, 2, 1, 1);

        b4 = new QPushButton(widget);
        b4->setObjectName("b4");

        gridLayout->addWidget(b4, 1, 0, 1, 1);

        b5 = new QPushButton(widget);
        b5->setObjectName("b5");

        gridLayout->addWidget(b5, 1, 1, 1, 1);

        b6 = new QPushButton(widget);
        b6->setObjectName("b6");

        gridLayout->addWidget(b6, 1, 2, 1, 1);

        b7 = new QPushButton(widget);
        b7->setObjectName("b7");

        gridLayout->addWidget(b7, 2, 0, 1, 1);

        b8 = new QPushButton(widget);
        b8->setObjectName("b8");

        gridLayout->addWidget(b8, 2, 1, 1, 1);

        b9 = new QPushButton(widget);
        b9->setObjectName("b9");

        gridLayout->addWidget(b9, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        b1->setText(QCoreApplication::translate("Widget", "bt1", nullptr));
        b2->setText(QCoreApplication::translate("Widget", "bt2", nullptr));
        b3->setText(QCoreApplication::translate("Widget", "bt3", nullptr));
        b4->setText(QCoreApplication::translate("Widget", "bt4", nullptr));
        b5->setText(QCoreApplication::translate("Widget", "bt5", nullptr));
        b6->setText(QCoreApplication::translate("Widget", "bt6", nullptr));
        b7->setText(QCoreApplication::translate("Widget", "bt7", nullptr));
        b8->setText(QCoreApplication::translate("Widget", "bt8", nullptr));
        b9->setText(QCoreApplication::translate("Widget", "bt9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
