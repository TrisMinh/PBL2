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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addroom
{
public:
    QFrame *line;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newRT;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Addroombtn;
    QPushButton *pushButton_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *newRT_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Addroombtn_2;
    QPushButton *pushButton_3;
    QFrame *line_2;
    QLabel *label_4;

    void setupUi(QDialog *Addroom)
    {
        if (Addroom->objectName().isEmpty())
            Addroom->setObjectName("Addroom");
        Addroom->resize(219, 154);
        Addroom->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:white;\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid gray;\n"
"border-radius: 6px;\n"
"padding-left: 15px;\n"
"height: 25px;\n"
"}"));
        line = new QFrame(Addroom);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 201, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(Addroom);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_2->setFont(font);
        layoutWidget = new QWidget(Addroom);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 50, 201, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        newRT = new QLineEdit(layoutWidget);
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
        Addroombtn = new QPushButton(layoutWidget);
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

        pushButton_2 = new QPushButton(layoutWidget);
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

        layoutWidget_2 = new QWidget(Addroom);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(70, 110, 201, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        label_3->setFont(font1);

        verticalLayout_4->addWidget(label_3);

        newRT_2 = new QLineEdit(layoutWidget_2);
        newRT_2->setObjectName("newRT_2");
        newRT_2->setMinimumSize(QSize(0, 25));

        verticalLayout_4->addWidget(newRT_2);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Addroombtn_2 = new QPushButton(layoutWidget_2);
        Addroombtn_2->setObjectName("Addroombtn_2");
        Addroombtn_2->setMinimumSize(QSize(55, 18));
        Addroombtn_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Addroombtn_2->setCheckable(true);

        horizontalLayout_4->addWidget(Addroombtn_2);

        pushButton_3 = new QPushButton(layoutWidget_2);
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


        verticalLayout_3->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Addroom);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(70, 90, 201, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_4 = new QLabel(Addroom);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 70, 161, 21));
        label_4->setFont(font);

        retranslateUi(Addroom);
        QObject::connect(pushButton_2, &QPushButton::toggled, Addroom, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Addroom);
    } // setupUi

    void retranslateUi(QDialog *Addroom)
    {
        Addroom->setWindowTitle(QCoreApplication::translate("Addroom", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Addroom", " Add Room", nullptr));
        label->setText(QCoreApplication::translate("Addroom", "Nh\341\272\255p lo\341\272\241i ph\303\262ng", nullptr));
        newRT->setPlaceholderText(QCoreApplication::translate("Addroom", "RT. ...", nullptr));
        Addroombtn->setText(QCoreApplication::translate("Addroom", "Add Room", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Addroom", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("Addroom", "Nh\341\272\255p lo\341\272\241i ph\303\262ng", nullptr));
        newRT_2->setPlaceholderText(QCoreApplication::translate("Addroom", "RT. ...", nullptr));
        Addroombtn_2->setText(QCoreApplication::translate("Addroom", "Add Room", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Addroom", "Cancel", nullptr));
        label_4->setText(QCoreApplication::translate("Addroom", " Add Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addroom: public Ui_Addroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROOM_H
