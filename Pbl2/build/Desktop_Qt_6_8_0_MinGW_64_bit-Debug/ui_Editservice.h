/********************************************************************************
** Form generated from reading UI file 'Editservice.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSERVICE_H
#define UI_EDITSERVICE_H

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

class Ui_Editservice
{
public:
    QFrame *line;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *name;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *price;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *des;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *UpdateSerbtn;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Editservice)
    {
        if (Editservice->objectName().isEmpty())
            Editservice->setObjectName("Editservice");
        Editservice->resize(221, 265);
        line = new QFrame(Editservice);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 201, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_3 = new QLabel(Editservice);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_3->setFont(font);
        widget = new QWidget(Editservice);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 50, 201, 201));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        name = new QLineEdit(widget);
        name->setObjectName("name");
        name->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(name);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        price = new QLineEdit(widget);
        price->setObjectName("price");
        price->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(price);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);

        des = new QLineEdit(widget);
        des->setObjectName("des");
        des->setMinimumSize(QSize(0, 25));

        verticalLayout_4->addWidget(des);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        UpdateSerbtn = new QPushButton(widget);
        UpdateSerbtn->setObjectName("UpdateSerbtn");
        UpdateSerbtn->setMinimumSize(QSize(55, 18));
        UpdateSerbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        UpdateSerbtn->setCheckable(true);

        horizontalLayout_6->addWidget(UpdateSerbtn);

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


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(Editservice);

        QMetaObject::connectSlotsByName(Editservice);
    } // setupUi

    void retranslateUi(QDialog *Editservice)
    {
        Editservice->setWindowTitle(QCoreApplication::translate("Editservice", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Editservice", "Edit Service", nullptr));
        label->setText(QCoreApplication::translate("Editservice", "Nh\341\272\255p t\303\252n d\341\273\213ch v\341\273\245", nullptr));
        name->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("Editservice", "Nh\341\272\255p gi\303\241 d\341\273\213ch v\341\273\245", nullptr));
        price->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("Editservice", "Nh\341\272\255p m\303\264 t\341\272\243 d\341\273\213ch v\341\273\245", nullptr));
        des->setPlaceholderText(QString());
        UpdateSerbtn->setText(QCoreApplication::translate("Editservice", "Update Service", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Editservice", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editservice: public Ui_Editservice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSERVICE_H
