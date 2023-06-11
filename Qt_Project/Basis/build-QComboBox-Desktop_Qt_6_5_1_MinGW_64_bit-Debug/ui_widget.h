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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QPushButton *captureValButt;
    QPushButton *setValButt;
    QPushButton *getValButt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(296, 125);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        captureValButt = new QPushButton(Widget);
        captureValButt->setObjectName("captureValButt");

        verticalLayout->addWidget(captureValButt);

        setValButt = new QPushButton(Widget);
        setValButt->setObjectName("setValButt");

        verticalLayout->addWidget(setValButt);

        getValButt = new QPushButton(Widget);
        getValButt->setObjectName("getValButt");

        verticalLayout->addWidget(getValButt);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        captureValButt->setText(QCoreApplication::translate("Widget", "Capture Value", nullptr));
        setValButt->setText(QCoreApplication::translate("Widget", "Set Value", nullptr));
        getValButt->setText(QCoreApplication::translate("Widget", "Get Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
