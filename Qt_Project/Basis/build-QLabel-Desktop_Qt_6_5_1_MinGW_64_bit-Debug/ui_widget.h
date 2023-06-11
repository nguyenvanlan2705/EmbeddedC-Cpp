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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelName;
    QLabel *labelImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(682, 564);
        labelName = new QLabel(Widget);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(230, 10, 191, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(28);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignCenter);
        labelImage = new QLabel(Widget);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(170, 120, 291, 291));
        labelImage->setScaledContents(false);
        labelImage->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelName->setText(QCoreApplication::translate("Widget", "Minion", nullptr));
        labelImage->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
