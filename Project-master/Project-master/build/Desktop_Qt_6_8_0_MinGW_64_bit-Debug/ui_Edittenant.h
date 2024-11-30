/********************************************************************************
** Form generated from reading UI file 'Edittenant.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTENANT_H
#define UI_EDITTENANT_H

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

class Ui_Edittenant
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *newname;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *newsdt;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *newcccd;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *newage;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Edittenantbtn;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Edittenant)
    {
        if (Edittenant->objectName().isEmpty())
            Edittenant->setObjectName("Edittenant");
        Edittenant->resize(237, 287);
        verticalLayout = new QVBoxLayout(Edittenant);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(Edittenant);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        newname = new QLineEdit(Edittenant);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newname);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(Edittenant);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font);

        verticalLayout_5->addWidget(label_5);

        newsdt = new QLineEdit(Edittenant);
        newsdt->setObjectName("newsdt");
        newsdt->setMinimumSize(QSize(0, 25));

        verticalLayout_5->addWidget(newsdt);


        verticalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(Edittenant);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setFont(font);

        verticalLayout_6->addWidget(label_6);

        newcccd = new QLineEdit(Edittenant);
        newcccd->setObjectName("newcccd");
        newcccd->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(newcccd);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(Edittenant);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setFont(font);

        verticalLayout_7->addWidget(label_7);

        newage = new QLineEdit(Edittenant);
        newage->setObjectName("newage");
        newage->setMinimumSize(QSize(0, 25));

        verticalLayout_7->addWidget(newage);


        verticalLayout->addLayout(verticalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_8 = new QLabel(Edittenant);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        comboBox = new QComboBox(Edittenant);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Edittenantbtn = new QPushButton(Edittenant);
        Edittenantbtn->setObjectName("Edittenantbtn");
        Edittenantbtn->setMinimumSize(QSize(55, 18));
        Edittenantbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Edittenantbtn->setCheckable(true);

        horizontalLayout_4->addWidget(Edittenantbtn);

        pushButton_3 = new QPushButton(Edittenant);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(18, 18));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #585858;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        pushButton_3->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_3);


        horizontalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Edittenant);
        QObject::connect(Edittenantbtn, &QPushButton::toggled, Edittenant, qOverload<>(&QDialog::close));
        QObject::connect(pushButton_3, &QPushButton::toggled, Edittenant, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Edittenant);
    } // setupUi

    void retranslateUi(QDialog *Edittenant)
    {
        Edittenant->setWindowTitle(QCoreApplication::translate("Edittenant", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Edittenant", "Nh\341\272\255p h\341\273\215 v\303\240 t\303\252n", nullptr));
        newname->setPlaceholderText(QString());
        label_5->setText(QCoreApplication::translate("Edittenant", "Nh\341\272\255p s\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
        newsdt->setPlaceholderText(QString());
        label_6->setText(QCoreApplication::translate("Edittenant", "Nh\341\272\255p CCCD", nullptr));
        newcccd->setPlaceholderText(QString());
        label_7->setText(QCoreApplication::translate("Edittenant", "Nh\341\272\255p n\304\203m sinh", nullptr));
        newage->setPlaceholderText(QString());
        label_8->setText(QCoreApplication::translate("Edittenant", "Gi\341\273\233i t\303\255nh", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Edittenant", "Nam", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Edittenant", "N\341\273\257", nullptr));

        Edittenantbtn->setText(QCoreApplication::translate("Edittenant", "Update Tenant", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Edittenant", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Edittenant: public Ui_Edittenant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTENANT_H
