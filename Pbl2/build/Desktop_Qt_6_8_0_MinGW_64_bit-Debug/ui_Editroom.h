/********************************************************************************
** Form generated from reading UI file 'Editroom.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROOM_H
#define UI_EDITROOM_H

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

class Ui_Editroom
{
public:
    QFrame *line;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newRT;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Updateroombtn;
    QPushButton *pushButton_2;
    QLabel *ID;
    QLabel *label_22;

    void setupUi(QDialog *Editroom)
    {
        if (Editroom->objectName().isEmpty())
            Editroom->setObjectName("Editroom");
        Editroom->resize(234, 239);
        line = new QFrame(Editroom);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 30, 211, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_3 = new QLabel(Editroom);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 161, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_3->setFont(font);
        layoutWidget = new QWidget(Editroom);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 70, 221, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
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
        newRT->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(newRT);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 35));

        verticalLayout_2->addWidget(comboBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Updateroombtn = new QPushButton(layoutWidget);
        Updateroombtn->setObjectName("Updateroombtn");
        Updateroombtn->setMinimumSize(QSize(55, 25));
        Updateroombtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Updateroombtn->setCheckable(false);

        horizontalLayout->addWidget(Updateroombtn);

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


        verticalLayout_3->addLayout(horizontalLayout_2);

        ID = new QLabel(Editroom);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(74, 40, 123, 24));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        ID->setFont(font2);
        label_22 = new QLabel(Editroom);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 40, 60, 24));
        label_22->setMaximumSize(QSize(60, 16777215));
        label_22->setFont(font2);

        retranslateUi(Editroom);
        QObject::connect(pushButton_2, &QPushButton::toggled, Editroom, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Editroom);
    } // setupUi

    void retranslateUi(QDialog *Editroom)
    {
        Editroom->setWindowTitle(QCoreApplication::translate("Editroom", "Edit Room", nullptr));
        label_3->setText(QCoreApplication::translate("Editroom", "Edit Room", nullptr));
        label->setText(QCoreApplication::translate("Editroom", "Enter New RoomType", nullptr));
        newRT->setPlaceholderText(QCoreApplication::translate("Editroom", "RT. ...", nullptr));
        label_2->setText(QCoreApplication::translate("Editroom", "Status", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Editroom", "Tr\341\273\221ng", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Editroom", "\304\220ang b\341\272\243o tr\303\254", nullptr));

        Updateroombtn->setText(QCoreApplication::translate("Editroom", "Update Room", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Editroom", "Cancel", nullptr));
        ID->setText(QString());
        label_22->setText(QCoreApplication::translate("Editroom", "Room ID: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editroom: public Ui_Editroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROOM_H
