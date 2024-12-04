/********************************************************************************
** Form generated from reading UI file 'Adminaccount.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINACCOUNT_H
#define UI_ADMINACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adminaccount
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *Oldcode;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *Newcode;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Changecode;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *oldpass;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLineEdit *newpass;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Changepass;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Adminaccount)
    {
        if (Adminaccount->objectName().isEmpty())
            Adminaccount->setObjectName("Adminaccount");
        Adminaccount->resize(206, 250);
        verticalLayout = new QVBoxLayout(Adminaccount);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(Adminaccount);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);

        verticalLayout_4->addWidget(label);

        line = new QFrame(page);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        Oldcode = new QLineEdit(page);
        Oldcode->setObjectName("Oldcode");
        Oldcode->setMinimumSize(QSize(0, 25));
        Oldcode->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(Oldcode);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 15));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        Newcode = new QLineEdit(page);
        Newcode->setObjectName("Newcode");
        Newcode->setMinimumSize(QSize(0, 25));
        Newcode->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(Newcode);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Changecode = new QPushButton(page);
        Changecode->setObjectName("Changecode");
        Changecode->setMinimumSize(QSize(55, 18));
        Changecode->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Changecode->setCheckable(true);

        horizontalLayout->addWidget(Changecode);

        pushButton_2 = new QPushButton(page);
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


        verticalLayout_5->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_9 = new QVBoxLayout(page_2);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(10);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setMaximumSize(QSize(16777215, 20));
        label_6->setFont(font);

        verticalLayout_8->addWidget(label_6);

        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_8->addWidget(line_2);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setFont(font1);

        verticalLayout_7->addWidget(label_5);

        oldpass = new QLineEdit(page_2);
        oldpass->setObjectName("oldpass");
        oldpass->setMinimumSize(QSize(0, 25));
        oldpass->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_7->addWidget(oldpass);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setFont(font1);

        verticalLayout_6->addWidget(label_4);

        newpass = new QLineEdit(page_2);
        newpass->setObjectName("newpass");
        newpass->setMinimumSize(QSize(0, 25));
        newpass->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_6->addWidget(newpass);


        verticalLayout_9->addLayout(verticalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Changepass = new QPushButton(page_2);
        Changepass->setObjectName("Changepass");
        Changepass->setMinimumSize(QSize(55, 18));
        Changepass->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/background-color: #34D481;\n"
"/color:white;\n"
"/border:none;\n"
"/border-radius: 8px;\n"
"/font-weight:bold;\n"
"/font-size: 10px;\n"
"}"));
        Changepass->setCheckable(true);

        horizontalLayout_4->addWidget(Changepass);

        pushButton_3 = new QPushButton(page_2);
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


        verticalLayout_9->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Adminaccount);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Adminaccount);
    } // setupUi

    void retranslateUi(QDialog *Adminaccount)
    {
        Adminaccount->setWindowTitle(QCoreApplication::translate("Adminaccount", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Adminaccount", "Change Admin Code", nullptr));
        label_2->setText(QCoreApplication::translate("Adminaccount", "Nh\341\272\255p AdminCode c\305\251", nullptr));
        Oldcode->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("Adminaccount", "Nh\341\272\255p AdminCode m\341\273\233i", nullptr));
        Newcode->setPlaceholderText(QString());
        Changecode->setText(QCoreApplication::translate("Adminaccount", "Update", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Adminaccount", "Cancel", nullptr));
        label_6->setText(QCoreApplication::translate("Adminaccount", "Change Password", nullptr));
        label_5->setText(QCoreApplication::translate("Adminaccount", "Enter old password", nullptr));
        oldpass->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("Adminaccount", "Enter new password", nullptr));
        newpass->setPlaceholderText(QString());
        Changepass->setText(QCoreApplication::translate("Adminaccount", "Update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Adminaccount", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adminaccount: public Ui_Adminaccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINACCOUNT_H
