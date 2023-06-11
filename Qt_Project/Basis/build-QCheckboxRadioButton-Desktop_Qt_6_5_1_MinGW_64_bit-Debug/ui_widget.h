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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QCheckBox *winkBox;
    QCheckBox *mackBox;
    QCheckBox *linuxBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QGroupBox *groupBox_3;
    QCheckBox *winkBox_3;
    QCheckBox *mackBox_3;
    QCheckBox *linuxBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(587, 294);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 40, 141, 151));
        winkBox = new QCheckBox(groupBox);
        winkBox->setObjectName("winkBox");
        winkBox->setGeometry(QRect(20, 40, 88, 24));
        mackBox = new QCheckBox(groupBox);
        mackBox->setObjectName("mackBox");
        mackBox->setGeometry(QRect(20, 70, 88, 24));
        linuxBox = new QCheckBox(groupBox);
        linuxBox->setObjectName("linuxBox");
        linuxBox->setGeometry(QRect(20, 100, 88, 24));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(230, 40, 141, 151));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName("verticalLayout");
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName("radioButton");

        verticalLayout->addWidget(radioButton);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(420, 40, 141, 151));
        winkBox_3 = new QCheckBox(groupBox_3);
        winkBox_3->setObjectName("winkBox_3");
        winkBox_3->setGeometry(QRect(20, 40, 88, 24));
        mackBox_3 = new QCheckBox(groupBox_3);
        mackBox_3->setObjectName("mackBox_3");
        mackBox_3->setGeometry(QRect(20, 70, 88, 24));
        linuxBox_3 = new QCheckBox(groupBox_3);
        linuxBox_3->setObjectName("linuxBox_3");
        linuxBox_3->setGeometry(QRect(20, 100, 88, 24));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 210, 411, 29));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 250, 411, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Choose OS (Exclusive)", nullptr));
        winkBox->setText(QCoreApplication::translate("Widget", "Window", nullptr));
        mackBox->setText(QCoreApplication::translate("Widget", "Mac", nullptr));
        linuxBox->setText(QCoreApplication::translate("Widget", "Linux", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "A", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "B", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "C", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "Choose uC (NonExclusive)", nullptr));
        winkBox_3->setText(QCoreApplication::translate("Widget", "STM32", nullptr));
        mackBox_3->setText(QCoreApplication::translate("Widget", "AVR", nullptr));
        linuxBox_3->setText(QCoreApplication::translate("Widget", "PIC", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Grab Data", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Set State", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
