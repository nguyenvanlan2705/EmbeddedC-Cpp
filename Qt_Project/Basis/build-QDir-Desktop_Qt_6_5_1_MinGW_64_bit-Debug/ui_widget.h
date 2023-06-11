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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *chooseDirButton;
    QPushButton *creatDirButton;
    QPushButton *dirExistButton;
    QPushButton *dirOrFileButton;
    QPushButton *folderContentButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(551, 347);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        chooseDirButton = new QPushButton(Widget);
        chooseDirButton->setObjectName("chooseDirButton");

        verticalLayout_2->addWidget(chooseDirButton);

        creatDirButton = new QPushButton(Widget);
        creatDirButton->setObjectName("creatDirButton");

        verticalLayout_2->addWidget(creatDirButton);

        dirExistButton = new QPushButton(Widget);
        dirExistButton->setObjectName("dirExistButton");

        verticalLayout_2->addWidget(dirExistButton);

        dirOrFileButton = new QPushButton(Widget);
        dirOrFileButton->setObjectName("dirOrFileButton");

        verticalLayout_2->addWidget(dirOrFileButton);

        folderContentButton = new QPushButton(Widget);
        folderContentButton->setObjectName("folderContentButton");

        verticalLayout_2->addWidget(folderContentButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        chooseDirButton->setText(QCoreApplication::translate("Widget", "Choose Dir", nullptr));
        creatDirButton->setText(QCoreApplication::translate("Widget", "Creat Dir", nullptr));
        dirExistButton->setText(QCoreApplication::translate("Widget", "Dir Exist ?", nullptr));
        dirOrFileButton->setText(QCoreApplication::translate("Widget", "Dir or File", nullptr));
        folderContentButton->setText(QCoreApplication::translate("Widget", "Folder Content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
