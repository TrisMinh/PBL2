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
#include <QtWidgets/QCheckBox>
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

class Ui_AddService
{
public:
    QFrame *line;
    QLabel *label_4;
    QWidget *layoutWidget;
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddSerbtn;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddService)
    {
        if (AddService->objectName().isEmpty())
            AddService->setObjectName("AddService");
        AddService->resize(246, 296);
        line = new QFrame(AddService);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 221, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_4 = new QLabel(AddService);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_4->setFont(font);
        layoutWidget = new QWidget(AddService);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 51, 221, 231));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        newname = new QLineEdit(layoutWidget);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(newname);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        newprice = new QLineEdit(layoutWidget);
        newprice->setObjectName("newprice");
        newprice->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(newprice);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        newdes = new QLineEdit(layoutWidget);
        newdes->setObjectName("newdes");
        newdes->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(newdes);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(55, 0));
        checkBox->setAutoExclusive(true);

        horizontalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setAutoExclusive(true);

        horizontalLayout_3->addWidget(checkBox_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddSerbtn = new QPushButton(layoutWidget);
        AddSerbtn->setObjectName("AddSerbtn");
        AddSerbtn->setMinimumSize(QSize(55, 25));
        AddSerbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        AddSerbtn->setCheckable(false);

        horizontalLayout->addWidget(AddSerbtn);

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


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(AddService);
        QObject::connect(pushButton_2, &QPushButton::toggled, AddService, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(AddService);
    } // setupUi

    void retranslateUi(QDialog *AddService)
    {
        AddService->setWindowTitle(QCoreApplication::translate("AddService", "Add Service", nullptr));
        label_4->setText(QCoreApplication::translate("AddService", " Add Service", nullptr));
        label->setText(QCoreApplication::translate("AddService", "Enter Service Name", nullptr));
        newname->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("AddService", "Enter Service Price", nullptr));
        newprice->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("AddService", "Enter Service Description", nullptr));
        newdes->setPlaceholderText(QString());
        label_5->setText(QCoreApplication::translate("AddService", "Service Type", nullptr));
        checkBox->setText(QCoreApplication::translate("AddService", "C\341\273\221 \304\221\341\273\213nh", nullptr));
        checkBox_2->setText(QCoreApplication::translate("AddService", "T\341\273\261 do", nullptr));
        AddSerbtn->setText(QCoreApplication::translate("AddService", "Add Service", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddService", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddService: public Ui_AddService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSERVICE_H
