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
    QLabel *codeTextLabel;
    QLabel *uiTextLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(428, 352);
        codeTextLabel = new QLabel(Widget);
        codeTextLabel->setObjectName("codeTextLabel");
        codeTextLabel->setGeometry(QRect(20, 200, 201, 61));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        codeTextLabel->setFont(font);
        uiTextLabel = new QLabel(Widget);
        uiTextLabel->setObjectName("uiTextLabel");
        uiTextLabel->setGeometry(QRect(20, 70, 191, 91));
        uiTextLabel->setFont(font);
        uiTextLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(85, 170, 0);"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 40, 93, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        codeTextLabel->setText(QCoreApplication::translate("Widget", "CodeText", nullptr));
        uiTextLabel->setText(QCoreApplication::translate("Widget", "Uitext", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Click me !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
