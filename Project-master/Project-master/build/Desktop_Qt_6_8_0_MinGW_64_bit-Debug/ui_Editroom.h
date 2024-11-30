/********************************************************************************
** Form generated from reading UI file 'Editroom.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROOM_H
#define UI_EDITROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Editroom
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newRT;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Updateroombtn;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Editroom)
    {
        if (Editroom->objectName().isEmpty())
            Editroom->setObjectName("Editroom");
        Editroom->resize(256, 178);
        verticalLayout_3 = new QVBoxLayout(Editroom);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Editroom);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        newRT = new QLineEdit(Editroom);
        newRT->setObjectName("newRT");
        newRT->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(newRT);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(Editroom);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(Editroom);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(comboBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Updateroombtn = new QPushButton(Editroom);
        Updateroombtn->setObjectName("Updateroombtn");
        Updateroombtn->setMinimumSize(QSize(55, 18));
        Updateroombtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Updateroombtn->setCheckable(true);

        horizontalLayout->addWidget(Updateroombtn);

        pushButton_2 = new QPushButton(Editroom);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(18, 18));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #585858;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        pushButton_2->setCheckable(true);

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Editroom);
        QObject::connect(Updateroombtn, &QPushButton::toggled, Editroom, qOverload<>(&QDialog::close));
        QObject::connect(pushButton_2, &QPushButton::toggled, Editroom, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Editroom);
    } // setupUi

    void retranslateUi(QDialog *Editroom)
    {
        Editroom->setWindowTitle(QCoreApplication::translate("Editroom", "Edit Room", nullptr));
        label->setText(QCoreApplication::translate("Editroom", "Nh\341\272\255p lo\341\272\241i ph\303\262ng m\341\273\233i", nullptr));
        newRT->setPlaceholderText(QCoreApplication::translate("Editroom", "RT. ...", nullptr));
        label_2->setText(QCoreApplication::translate("Editroom", "Tr\341\272\241ng th\303\241i", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Editroom", "Tr\341\273\221ng", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Editroom", "\304\220ang b\341\272\243o tr\303\254", nullptr));

        Updateroombtn->setText(QCoreApplication::translate("Editroom", "Update Room", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Editroom", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editroom: public Ui_Editroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROOM_H
