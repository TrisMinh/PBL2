/********************************************************************************
** Form generated from reading UI file 'Addroomtype.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROOMTYPE_H
#define UI_ADDROOMTYPE_H

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

class Ui_Addroomtype
{
public:
    QLabel *label;
    QFrame *line;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *newname;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *newdes;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *newprice;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *AddRTbtn;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Addroomtype)
    {
        if (Addroomtype->objectName().isEmpty())
            Addroomtype->setObjectName("Addroomtype");
        Addroomtype->resize(249, 294);
        Addroomtype->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 0.5px solid gray;\n"
"border-radius:5px;\n"
"}"));
        label = new QLabel(Addroomtype);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label->setFont(font);
        line = new QFrame(Addroomtype);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 231, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        widget = new QWidget(Addroomtype);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 50, 231, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        newname = new QLineEdit(widget);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newname);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);

        newdes = new QLineEdit(widget);
        newdes->setObjectName("newdes");
        newdes->setMinimumSize(QSize(0, 25));

        verticalLayout_4->addWidget(newdes);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font1);

        verticalLayout_5->addWidget(label_5);

        newprice = new QLineEdit(widget);
        newprice->setObjectName("newprice");
        newprice->setMinimumSize(QSize(0, 25));

        verticalLayout_5->addWidget(newprice);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        AddRTbtn = new QPushButton(widget);
        AddRTbtn->setObjectName("AddRTbtn");
        AddRTbtn->setMinimumSize(QSize(55, 18));
        AddRTbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        AddRTbtn->setCheckable(true);

        horizontalLayout_6->addWidget(AddRTbtn);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(18, 18));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #585858;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        pushButton_4->setCheckable(true);

        horizontalLayout_6->addWidget(pushButton_4);


        horizontalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Addroomtype);

        QMetaObject::connectSlotsByName(Addroomtype);
    } // setupUi

    void retranslateUi(QDialog *Addroomtype)
    {
        Addroomtype->setWindowTitle(QCoreApplication::translate("Addroomtype", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Addroomtype", " Add Room Type", nullptr));
        label_3->setText(QCoreApplication::translate("Addroomtype", "Nh\341\272\255p t\303\252n lo\341\272\241i ph\303\262ng", nullptr));
        newname->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("Addroomtype", "Nh\341\272\255p m\303\264 t\341\272\243", nullptr));
        newdes->setPlaceholderText(QString());
        label_5->setText(QCoreApplication::translate("Addroomtype", "Nh\341\272\255p gi\303\241", nullptr));
        newprice->setPlaceholderText(QString());
        AddRTbtn->setText(QCoreApplication::translate("Addroomtype", "Add Room Type", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Addroomtype", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addroomtype: public Ui_Addroomtype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROOMTYPE_H
