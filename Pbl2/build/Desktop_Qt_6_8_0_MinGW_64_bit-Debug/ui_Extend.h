/********************************************************************************
** Form generated from reading UI file 'Extend.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTEND_H
#define UI_EXTEND_H

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

class Ui_Extend
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newRT;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Extenbtn;
    QPushButton *pushButton_2;
    QFrame *line;
    QLabel *label_2;

    void setupUi(QDialog *Extend)
    {
        if (Extend->objectName().isEmpty())
            Extend->setObjectName("Extend");
        Extend->resize(218, 148);
        layoutWidget = new QWidget(Extend);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 201, 97));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        newRT = new QLineEdit(layoutWidget);
        newRT->setObjectName("newRT");
        newRT->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(newRT);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Extenbtn = new QPushButton(layoutWidget);
        Extenbtn->setObjectName("Extenbtn");
        Extenbtn->setMinimumSize(QSize(55, 25));
        Extenbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Extenbtn->setCheckable(false);

        horizontalLayout->addWidget(Extenbtn);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(18, 25));
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


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(Extend);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 20, 201, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(Extend);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 161, 21));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);

        retranslateUi(Extend);
        QObject::connect(pushButton_2, &QPushButton::toggled, Extend, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Extend);
    } // setupUi

    void retranslateUi(QDialog *Extend)
    {
        Extend->setWindowTitle(QCoreApplication::translate("Extend", "Extend", nullptr));
        label->setText(QCoreApplication::translate("Extend", "Enter Months to Extend", nullptr));
        newRT->setPlaceholderText(QString());
        Extenbtn->setText(QCoreApplication::translate("Extend", "Extend", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Extend", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("Extend", "Extend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Extend: public Ui_Extend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTEND_H
