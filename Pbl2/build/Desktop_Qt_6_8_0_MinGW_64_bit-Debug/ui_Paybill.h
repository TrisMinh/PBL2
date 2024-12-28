/********************************************************************************
** Form generated from reading UI file 'Paybill.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYBILL_H
#define UI_PAYBILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paybill
{
public:
    QFrame *line;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Datbtn;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *paymentID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *roomID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *deposit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *remaining;
    QLineEdit *amount;

    void setupUi(QDialog *Paybill)
    {
        if (Paybill->objectName().isEmpty())
            Paybill->setObjectName("Paybill");
        Paybill->resize(315, 262);
        Paybill->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line = new QFrame(Paybill);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 40, 301, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(Paybill);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 15, 241, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        layoutWidget_2 = new QWidget(Paybill);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(130, 210, 164, 34));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Datbtn = new QPushButton(layoutWidget_2);
        Datbtn->setObjectName("Datbtn");
        Datbtn->setMinimumSize(QSize(75, 30));
        QFont font1;
        font1.setPointSize(10);
        Datbtn->setFont(font1);
        Datbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Datbtn->setCheckable(false);

        horizontalLayout_6->addWidget(Datbtn);

        pushButton_2 = new QPushButton(layoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(18, 30));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #585858;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        pushButton_2->setCheckable(true);

        horizontalLayout_6->addWidget(pushButton_2);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        layoutWidget = new QWidget(Paybill);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 60, 259, 100));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(151, 0));
        label_2->setMaximumSize(QSize(151, 16777215));
        QFont font2;
        font2.setPointSize(11);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        paymentID = new QLabel(layoutWidget);
        paymentID->setObjectName("paymentID");
        paymentID->setMinimumSize(QSize(100, 0));
        paymentID->setFont(font1);

        horizontalLayout->addWidget(paymentID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(151, 0));
        label_3->setMaximumSize(QSize(151, 16777215));
        label_3->setFont(font2);

        horizontalLayout_3->addWidget(label_3);

        roomID = new QLabel(layoutWidget);
        roomID->setObjectName("roomID");
        roomID->setMinimumSize(QSize(100, 0));
        roomID->setFont(font1);

        horizontalLayout_3->addWidget(roomID);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(151, 0));
        label_4->setMaximumSize(QSize(151, 16777215));
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);

        deposit = new QLabel(layoutWidget);
        deposit->setObjectName("deposit");
        deposit->setMinimumSize(QSize(100, 0));
        deposit->setFont(font1);

        horizontalLayout_2->addWidget(deposit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(151, 0));
        label_5->setMaximumSize(QSize(151, 16777215));
        label_5->setFont(font2);

        horizontalLayout_4->addWidget(label_5);

        remaining = new QLabel(layoutWidget);
        remaining->setObjectName("remaining");
        remaining->setMinimumSize(QSize(100, 0));
        remaining->setFont(font1);

        horizontalLayout_4->addWidget(remaining);


        verticalLayout->addLayout(horizontalLayout_4);

        amount = new QLineEdit(Paybill);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(30, 170, 261, 35));
        amount->setMinimumSize(QSize(0, 35));
        amount->setFont(font2);
        amount->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Paybill);
        QObject::connect(pushButton_2, &QPushButton::toggled, Paybill, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Paybill);
    } // setupUi

    void retranslateUi(QDialog *Paybill)
    {
        Paybill->setWindowTitle(QCoreApplication::translate("Paybill", "Payment", nullptr));
        label->setText(QCoreApplication::translate("Paybill", "Payment", nullptr));
        Datbtn->setText(QCoreApplication::translate("Paybill", "Pay", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Paybill", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("Paybill", "Payment ID:", nullptr));
        paymentID->setText(QString());
        label_3->setText(QCoreApplication::translate("Paybill", "Room ID: ", nullptr));
        roomID->setText(QString());
        label_4->setText(QCoreApplication::translate("Paybill", "Amount Paid:", nullptr));
        deposit->setText(QString());
        label_5->setText(QCoreApplication::translate("Paybill", "Remaining Amount:", nullptr));
        remaining->setText(QString());
        amount->setText(QString());
        amount->setPlaceholderText(QCoreApplication::translate("Paybill", "Enter Amount to Pay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Paybill: public Ui_Paybill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYBILL_H
