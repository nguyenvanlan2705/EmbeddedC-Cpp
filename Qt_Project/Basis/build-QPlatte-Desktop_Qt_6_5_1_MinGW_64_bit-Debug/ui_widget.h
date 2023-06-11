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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *activeButton;
    QPushButton *disableButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(448, 304);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 120, 251, 141));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        activeButton = new QPushButton(Widget);
        activeButton->setObjectName("activeButton");
        activeButton->setGeometry(QRect(70, 50, 93, 29));
        disableButton_2 = new QPushButton(Widget);
        disableButton_2->setObjectName("disableButton_2");
        disableButton_2->setEnabled(true);
        disableButton_2->setGeometry(QRect(220, 50, 93, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "My Label", nullptr));
        activeButton->setText(QCoreApplication::translate("Widget", "Active", nullptr));
        disableButton_2->setText(QCoreApplication::translate("Widget", "Disable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
