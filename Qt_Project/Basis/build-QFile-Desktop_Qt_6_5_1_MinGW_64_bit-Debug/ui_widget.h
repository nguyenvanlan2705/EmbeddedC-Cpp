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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *writeButton;
    QPushButton *readButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *srcLineEdit;
    QPushButton *selectFileButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *desLineEdit;
    QPushButton *copyButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(512, 406);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        writeButton = new QPushButton(Widget);
        writeButton->setObjectName("writeButton");

        verticalLayout->addWidget(writeButton);

        readButton = new QPushButton(Widget);
        readButton->setObjectName("readButton");

        verticalLayout->addWidget(readButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        srcLineEdit = new QLineEdit(Widget);
        srcLineEdit->setObjectName("srcLineEdit");

        horizontalLayout_2->addWidget(srcLineEdit);

        selectFileButton = new QPushButton(Widget);
        selectFileButton->setObjectName("selectFileButton");

        horizontalLayout_2->addWidget(selectFileButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        desLineEdit = new QLineEdit(Widget);
        desLineEdit->setObjectName("desLineEdit");

        horizontalLayout_3->addWidget(desLineEdit);

        copyButton = new QPushButton(Widget);
        copyButton->setObjectName("copyButton");

        horizontalLayout_3->addWidget(copyButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        writeButton->setText(QCoreApplication::translate("Widget", "Write", nullptr));
        readButton->setText(QCoreApplication::translate("Widget", "Read", nullptr));
        selectFileButton->setText(QCoreApplication::translate("Widget", "Select File", nullptr));
        copyButton->setText(QCoreApplication::translate("Widget", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
