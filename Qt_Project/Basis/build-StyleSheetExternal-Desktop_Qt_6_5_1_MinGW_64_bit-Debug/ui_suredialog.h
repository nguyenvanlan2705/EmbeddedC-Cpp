/********************************************************************************
** Form generated from reading UI file 'suredialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUREDIALOG_H
#define UI_SUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SureDialog)
    {
        if (SureDialog->objectName().isEmpty())
            SureDialog->setObjectName("SureDialog");
        SureDialog->resize(274, 113);
        verticalLayout = new QVBoxLayout(SureDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SureDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SureDialog);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SureDialog);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SureDialog);

        QMetaObject::connectSlotsByName(SureDialog);
    } // setupUi

    void retranslateUi(QDialog *SureDialog)
    {
        SureDialog->setWindowTitle(QCoreApplication::translate("SureDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SureDialog", "Are you sure ?", nullptr));
        pushButton->setText(QCoreApplication::translate("SureDialog", "Ok", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SureDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SureDialog: public Ui_SureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUREDIALOG_H
