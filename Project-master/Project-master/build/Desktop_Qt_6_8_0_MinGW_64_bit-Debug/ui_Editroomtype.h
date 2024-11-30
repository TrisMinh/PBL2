/********************************************************************************
** Form generated from reading UI file 'Editroomtype.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROOMTYPE_H
#define UI_EDITROOMTYPE_H

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

class Ui_Editroomtype
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *newname;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *newdes;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *newprice;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Update;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Editroomtype)
    {
        if (Editroomtype->objectName().isEmpty())
            Editroomtype->setObjectName("Editroomtype");
        Editroomtype->resize(206, 238);
        verticalLayout_6 = new QVBoxLayout(Editroomtype);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(Editroomtype);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        newname = new QLineEdit(Editroomtype);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newname);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(Editroomtype);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setFont(font);

        verticalLayout_4->addWidget(label_4);

        newdes = new QLineEdit(Editroomtype);
        newdes->setObjectName("newdes");
        newdes->setMinimumSize(QSize(0, 25));

        verticalLayout_4->addWidget(newdes);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(Editroomtype);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font);

        verticalLayout_5->addWidget(label_5);

        newprice = new QLineEdit(Editroomtype);
        newprice->setObjectName("newprice");
        newprice->setMinimumSize(QSize(0, 25));

        verticalLayout_5->addWidget(newprice);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Update = new QPushButton(Editroomtype);
        Update->setObjectName("Update");
        Update->setMinimumSize(QSize(55, 18));
        Update->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Update->setCheckable(true);

        horizontalLayout_4->addWidget(Update);

        pushButton_3 = new QPushButton(Editroomtype);
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


        verticalLayout_6->addLayout(horizontalLayout_3);


        retranslateUi(Editroomtype);

        QMetaObject::connectSlotsByName(Editroomtype);
    } // setupUi

    void retranslateUi(QDialog *Editroomtype)
    {
        Editroomtype->setWindowTitle(QCoreApplication::translate("Editroomtype", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p t\303\252n lo\341\272\241i ph\303\262ng", nullptr));
        newname->setPlaceholderText(QCoreApplication::translate("Editroomtype", "RT. ...", nullptr));
        label_4->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p m\303\264 t\341\272\243", nullptr));
        newdes->setPlaceholderText(QCoreApplication::translate("Editroomtype", "RT. ...", nullptr));
        label_5->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p gi\303\241", nullptr));
        newprice->setPlaceholderText(QCoreApplication::translate("Editroomtype", "RT. ...", nullptr));
        Update->setText(QCoreApplication::translate("Editroomtype", "Update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Editroomtype", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editroomtype: public Ui_Editroomtype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROOMTYPE_H
