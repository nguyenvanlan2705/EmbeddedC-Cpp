/********************************************************************************
** Form generated from reading UI file 'infordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORDIALOG_H
#define UI_INFORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InforDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *PoslineEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *windowRadioButton;
    QRadioButton *macRadioButton;
    QRadioButton *linuxRadioButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *InforDialog)
    {
        if (InforDialog->objectName().isEmpty())
            InforDialog->setObjectName("InforDialog");
        InforDialog->resize(388, 262);
        verticalLayout_2 = new QVBoxLayout(InforDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(InforDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(InforDialog);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        PoslineEdit = new QLineEdit(InforDialog);
        PoslineEdit->setObjectName("PoslineEdit");

        horizontalLayout->addWidget(PoslineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(InforDialog);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        windowRadioButton = new QRadioButton(groupBox);
        windowRadioButton->setObjectName("windowRadioButton");

        verticalLayout->addWidget(windowRadioButton);

        macRadioButton = new QRadioButton(groupBox);
        macRadioButton->setObjectName("macRadioButton");

        verticalLayout->addWidget(macRadioButton);

        linuxRadioButton = new QRadioButton(groupBox);
        linuxRadioButton->setObjectName("linuxRadioButton");

        verticalLayout->addWidget(linuxRadioButton);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(InforDialog);
        okButton->setObjectName("okButton");

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(InforDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(InforDialog);

        QMetaObject::connectSlotsByName(InforDialog);
    } // setupUi

    void retranslateUi(QDialog *InforDialog)
    {
        InforDialog->setWindowTitle(QCoreApplication::translate("InforDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("InforDialog", "Your information", nullptr));
        label_2->setText(QCoreApplication::translate("InforDialog", "Position: ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("InforDialog", "GroupBox", nullptr));
        windowRadioButton->setText(QCoreApplication::translate("InforDialog", "Window", nullptr));
        macRadioButton->setText(QCoreApplication::translate("InforDialog", "Mac", nullptr));
        linuxRadioButton->setText(QCoreApplication::translate("InforDialog", "Linux", nullptr));
        okButton->setText(QCoreApplication::translate("InforDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("InforDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InforDialog: public Ui_InforDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORDIALOG_H
