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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Edittenant
{
public:
    QFrame *line;
    QLabel *label_2;
    QWidget *layoutWidget;
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
        Edittenant->resize(230, 339);
        line = new QFrame(Edittenant);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 221, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(Edittenant);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_2->setFont(font);
        layoutWidget = new QWidget(Edittenant);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 50, 211, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        newname = new QLineEdit(layoutWidget);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newname);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font1);

        verticalLayout_5->addWidget(label_5);

        newsdt = new QLineEdit(layoutWidget);
        newsdt->setObjectName("newsdt");
        newsdt->setMinimumSize(QSize(0, 25));

        verticalLayout_5->addWidget(newsdt);


        verticalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setFont(font1);

        verticalLayout_6->addWidget(label_6);

        newcccd = new QLineEdit(layoutWidget);
        newcccd->setObjectName("newcccd");
        newcccd->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(newcccd);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setFont(font1);

        verticalLayout_7->addWidget(label_7);

        newage = new QLineEdit(layoutWidget);
        newage->setObjectName("newage");
        newage->setMinimumSize(QSize(0, 25));

        verticalLayout_7->addWidget(newage);


        verticalLayout->addLayout(verticalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setFont(font1);

        horizontalLayout->addWidget(label_8);

        comboBox = new QComboBox(layoutWidget);
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
        Edittenantbtn = new QPushButton(layoutWidget);
        Edittenantbtn->setObjectName("Edittenantbtn");
        Edittenantbtn->setMinimumSize(QSize(55, 25));
        Edittenantbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Edittenantbtn->setCheckable(false);

        horizontalLayout_4->addWidget(Edittenantbtn);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(18, 25));
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
        QObject::connect(pushButton_3, &QPushButton::toggled, Edittenant, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Edittenant);
    } // setupUi

    void retranslateUi(QDialog *Edittenant)
    {
        Edittenant->setWindowTitle(QCoreApplication::translate("Edittenant", "Edit Tenant", nullptr));
        label_2->setText(QCoreApplication::translate("Edittenant", "Edit Tenant", nullptr));
        label_3->setText(QCoreApplication::translate("Edittenant", "Enter Full Name", nullptr));
        newname->setPlaceholderText(QString());
        label_5->setText(QCoreApplication::translate("Edittenant", "Enter Phone Number", nullptr));
        newsdt->setPlaceholderText(QString());
        label_6->setText(QCoreApplication::translate("Edittenant", "Enter CCCD", nullptr));
        newcccd->setPlaceholderText(QString());
        label_7->setText(QCoreApplication::translate("Edittenant", "Enter Year of Birth", nullptr));
        newage->setPlaceholderText(QString());
        label_8->setText(QCoreApplication::translate("Edittenant", "Gender", nullptr));
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
