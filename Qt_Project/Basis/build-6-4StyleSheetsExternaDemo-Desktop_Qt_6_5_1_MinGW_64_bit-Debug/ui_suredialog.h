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
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SureDialog)
    {
        if (SureDialog->objectName().isEmpty())
            SureDialog->setObjectName("SureDialog");
        SureDialog->resize(400, 124);
        verticalLayout = new QVBoxLayout(SureDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SureDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Adobe Arabic")});
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SureDialog);
        okButton->setObjectName("okButton");

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SureDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SureDialog);

        QMetaObject::connectSlotsByName(SureDialog);
    } // setupUi

    void retranslateUi(QDialog *SureDialog)
    {
        SureDialog->setWindowTitle(QCoreApplication::translate("SureDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SureDialog", "Are you sure ? ", nullptr));
        okButton->setText(QCoreApplication::translate("SureDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("SureDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SureDialog: public Ui_SureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUREDIALOG_H
