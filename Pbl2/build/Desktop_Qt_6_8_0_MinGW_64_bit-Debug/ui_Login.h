/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *Signinbtn;
    QPushButton *Signupbtn;
    QLabel *label;
    QWidget *SignInpage;
    QLabel *loginfailed;
    QLineEdit *UserName;
    QPushButton *Loginbtn;
    QLineEdit *Password;
    QWidget *page_2;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(562, 548);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Resources/logoooo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        Signinbtn = new QPushButton(page);
        Signinbtn->setObjectName("Signinbtn");
        Signinbtn->setGeometry(QRect(70, 210, 251, 51));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        Signinbtn->setFont(font);
        Signinbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Signupbtn = new QPushButton(page);
        Signupbtn->setObjectName("Signupbtn");
        Signupbtn->setGeometry(QRect(70, 280, 251, 51));
        Signupbtn->setFont(font);
        Signupbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 291, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(40);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page);
        SignInpage = new QWidget();
        SignInpage->setObjectName("SignInpage");
        loginfailed = new QLabel(SignInpage);
        loginfailed->setObjectName("loginfailed");
        loginfailed->setGeometry(QRect(70, 380, 271, 16));
        QFont font2;
        font2.setPointSize(7);
        loginfailed->setFont(font2);
        loginfailed->setStyleSheet(QString::fromUtf8("color: red;"));
        UserName = new QLineEdit(SignInpage);
        UserName->setObjectName("UserName");
        UserName->setGeometry(QRect(71, 211, 281, 41));
        UserName->setMinimumSize(QSize(281, 41));
        QFont font3;
        font3.setPointSize(11);
        UserName->setFont(font3);
        Loginbtn = new QPushButton(SignInpage);
        Loginbtn->setObjectName("Loginbtn");
        Loginbtn->setGeometry(QRect(71, 333, 281, 41));
        Loginbtn->setMinimumSize(QSize(281, 41));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        Loginbtn->setFont(font4);
        Loginbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Password = new QLineEdit(SignInpage);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(71, 272, 281, 41));
        Password->setMinimumSize(QSize(281, 41));
        Password->setFont(font3);
        Password->setEchoMode(QLineEdit::EchoMode::Password);
        stackedWidget->addWidget(SignInpage);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Room Management System", nullptr));
        Signinbtn->setText(QCoreApplication::translate("Login", "Sign in", nullptr));
        Signupbtn->setText(QCoreApplication::translate("Login", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("Login", "WELCOME", nullptr));
        loginfailed->setText(QString());
        UserName->setPlaceholderText(QCoreApplication::translate("Login", " Username ", nullptr));
        Loginbtn->setText(QCoreApplication::translate("Login", "Log in", nullptr));
        Password->setText(QString());
        Password->setPlaceholderText(QCoreApplication::translate("Login", " Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
