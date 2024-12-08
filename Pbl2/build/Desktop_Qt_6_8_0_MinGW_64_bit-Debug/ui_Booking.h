/********************************************************************************
** Form generated from reading UI file 'Booking.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Booking
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_21;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_20;
    QLineEdit *stay;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Datbtn;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Booking)
    {
        if (Booking->objectName().isEmpty())
            Booking->setObjectName("Booking");
        Booking->resize(217, 235);
        verticalLayout_3 = new QVBoxLayout(Booking);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(5);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(Booking);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_6->setFont(font);

        verticalLayout_8->addWidget(label_6);

        line_2 = new QFrame(Booking);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_8->addWidget(line_2);


        verticalLayout_3->addLayout(verticalLayout_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_21 = new QLabel(Booking);
        label_21->setObjectName("label_21");

        verticalLayout->addWidget(label_21);

        dateEdit = new QDateEdit(Booking);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setMinimumSize(QSize(0, 35));
        dateEdit->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(11);
        dateEdit->setFont(font1);
        dateEdit->setAutoFillBackground(false);
        dateEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(dateEdit);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_20 = new QLabel(Booking);
        label_20->setObjectName("label_20");

        verticalLayout_2->addWidget(label_20);

        stay = new QLineEdit(Booking);
        stay->setObjectName("stay");
        stay->setMinimumSize(QSize(0, 35));
        stay->setFont(font1);
        stay->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(stay);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Datbtn = new QPushButton(Booking);
        Datbtn->setObjectName("Datbtn");
        Datbtn->setMinimumSize(QSize(55, 30));
        QFont font2;
        font2.setPointSize(10);
        Datbtn->setFont(font2);
        Datbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Datbtn->setCheckable(true);

        horizontalLayout->addWidget(Datbtn);

        pushButton_2 = new QPushButton(Booking);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(18, 30));
        pushButton_2->setFont(font2);
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


        retranslateUi(Booking);
        QObject::connect(pushButton_2, &QPushButton::toggled, Booking, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Booking);
    } // setupUi

    void retranslateUi(QDialog *Booking)
    {
        Booking->setWindowTitle(QCoreApplication::translate("Booking", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("Booking", "\304\220\341\272\267t ph\303\262ng", nullptr));
        label_21->setText(QCoreApplication::translate("Booking", "Nh\341\272\255p StayDate", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Booking", "dd/MM/yyyy", nullptr));
        label_20->setText(QCoreApplication::translate("Booking", "Nh\341\272\255p Stay Time (s\341\273\221 th\303\241ng)", nullptr));
        stay->setPlaceholderText(QString());
        Datbtn->setText(QCoreApplication::translate("Booking", "\304\220\341\272\267t", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Booking", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Booking: public Ui_Booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
