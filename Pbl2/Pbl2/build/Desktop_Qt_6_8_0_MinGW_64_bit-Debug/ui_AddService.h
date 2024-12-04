/********************************************************************************
** Form generated from reading UI file 'AddService.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSERVICE_H
#define UI_ADDSERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddService
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newname;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *newprice;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *newdes;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddSerbtn;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddService)
    {
        if (AddService->objectName().isEmpty())
            AddService->setObjectName("AddService");
        AddService->resize(212, 244);
        verticalLayout_4 = new QVBoxLayout(AddService);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddService);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        newname = new QLineEdit(AddService);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(newname);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(AddService);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        newprice = new QLineEdit(AddService);
        newprice->setObjectName("newprice");
        newprice->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(newprice);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(AddService);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        newdes = new QLineEdit(AddService);
        newdes->setObjectName("newdes");
        newdes->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newdes);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddSerbtn = new QPushButton(AddService);
        AddSerbtn->setObjectName("AddSerbtn");
        AddSerbtn->setMinimumSize(QSize(55, 18));
        AddSerbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        AddSerbtn->setCheckable(true);

        horizontalLayout->addWidget(AddSerbtn);

        pushButton_2 = new QPushButton(AddService);
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


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(AddService);

        QMetaObject::connectSlotsByName(AddService);
    } // setupUi

    void retranslateUi(QDialog *AddService)
    {
        AddService->setWindowTitle(QCoreApplication::translate("AddService", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddService", "Nh\341\272\255p t\303\252n d\341\273\213ch v\341\273\245", nullptr));
        newname->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("AddService", "Nh\341\272\255p gi\303\241 d\341\273\213ch v\341\273\245", nullptr));
        newprice->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("AddService", "Nh\341\272\255p m\303\264 t\341\272\243 d\341\273\213ch v\341\273\245", nullptr));
        newdes->setPlaceholderText(QString());
        AddSerbtn->setText(QCoreApplication::translate("AddService", "Add Serive", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddService", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddService: public Ui_AddService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSERVICE_H
