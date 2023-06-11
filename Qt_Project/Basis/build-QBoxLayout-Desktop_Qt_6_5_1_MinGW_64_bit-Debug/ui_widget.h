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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    QPushButton *b5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        b1 = new QPushButton(Widget);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(40, 220, 93, 29));
        b2 = new QPushButton(Widget);
        b2->setObjectName("b2");
        b2->setGeometry(QRect(180, 220, 93, 29));
        b3 = new QPushButton(Widget);
        b3->setObjectName("b3");
        b3->setGeometry(QRect(320, 220, 93, 29));
        b4 = new QPushButton(Widget);
        b4->setObjectName("b4");
        b4->setGeometry(QRect(450, 220, 93, 29));
        b5 = new QPushButton(Widget);
        b5->setObjectName("b5");
        b5->setGeometry(QRect(630, 230, 93, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        b1->setText(QCoreApplication::translate("Widget", "b1", nullptr));
        b2->setText(QCoreApplication::translate("Widget", "b2", nullptr));
        b3->setText(QCoreApplication::translate("Widget", "b3", nullptr));
        b4->setText(QCoreApplication::translate("Widget", "b4", nullptr));
        b5->setText(QCoreApplication::translate("Widget", "b5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
