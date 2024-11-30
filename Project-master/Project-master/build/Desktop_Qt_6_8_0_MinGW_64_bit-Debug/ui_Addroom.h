/********************************************************************************
** Form generated from reading UI file 'Addroom.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROOM_H
#define UI_ADDROOM_H

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

class Ui_Addroom
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newRT;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Addroombtn;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Addroom)
    {
        if (Addroom->objectName().isEmpty())
            Addroom->setObjectName("Addroom");
        Addroom->resize(219, 111);
        Addroom->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:white;\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid gray;\n"
"border-radius: 6px;\n"
"padding-left: 15px;\n"
"height: 25px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(Addroom);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Addroom);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        newRT = new QLineEdit(Addroom);
        newRT->setObjectName("newRT");
        newRT->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(newRT);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Addroombtn = new QPushButton(Addroom);
        Addroombtn->setObjectName("Addroombtn");
        Addroombtn->setMinimumSize(QSize(55, 18));
        Addroombtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Addroombtn->setCheckable(true);

        horizontalLayout->addWidget(Addroombtn);

        pushButton_2 = new QPushButton(Addroom);
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


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Addroom);
        QObject::connect(pushButton_2, &QPushButton::toggled, Addroom, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Addroom);
    } // setupUi

    void retranslateUi(QDialog *Addroom)
    {
        Addroom->setWindowTitle(QCoreApplication::translate("Addroom", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Addroom", "Nh\341\272\255p lo\341\272\241i ph\303\262ng", nullptr));
        newRT->setPlaceholderText(QCoreApplication::translate("Addroom", "RT. ...", nullptr));
        Addroombtn->setText(QCoreApplication::translate("Addroom", "Add Room", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Addroom", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addroom: public Ui_Addroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROOM_H
