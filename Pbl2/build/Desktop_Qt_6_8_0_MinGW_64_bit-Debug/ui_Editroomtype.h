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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editroomtype
{
public:
    QFrame *line;
    QLabel *label_2;
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
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Update;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Editroomtype)
    {
        if (Editroomtype->objectName().isEmpty())
            Editroomtype->setObjectName("Editroomtype");
        Editroomtype->resize(219, 249);
        line = new QFrame(Editroomtype);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 201, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(Editroomtype);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_2->setFont(font);
        widget = new QWidget(Editroomtype);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 50, 201, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        newname = new QLineEdit(widget);
        newname->setObjectName("newname");
        newname->setMinimumSize(QSize(0, 25));

        verticalLayout_3->addWidget(newname);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Update = new QPushButton(widget);
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

        pushButton_3 = new QPushButton(widget);
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


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Editroomtype);

        QMetaObject::connectSlotsByName(Editroomtype);
    } // setupUi

    void retranslateUi(QDialog *Editroomtype)
    {
        Editroomtype->setWindowTitle(QCoreApplication::translate("Editroomtype", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Editroomtype", "Edit Room Type", nullptr));
        label_3->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p t\303\252n lo\341\272\241i ph\303\262ng", nullptr));
        newname->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p m\303\264 t\341\272\243", nullptr));
        newdes->setPlaceholderText(QString());
        label_5->setText(QCoreApplication::translate("Editroomtype", "Nh\341\272\255p gi\303\241", nullptr));
        newprice->setPlaceholderText(QString());
        Update->setText(QCoreApplication::translate("Editroomtype", "Update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Editroomtype", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editroomtype: public Ui_Editroomtype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROOMTYPE_H
