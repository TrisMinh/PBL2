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
    QLabel *label_2;
    QPushButton *SigninBackButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *UserName;
    QLineEdit *Password;
    QPushButton *Loginbtn;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(428, 455);
        Login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
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
        label_2 = new QLabel(SignInpage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 60, 191, 91));
        QFont font2;
        font2.setPointSize(40);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SigninBackButton = new QPushButton(SignInpage);
        SigninBackButton->setObjectName("SigninBackButton");
        SigninBackButton->setGeometry(QRect(10, 10, 81, 31));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        SigninBackButton->setFont(font3);
        layoutWidget = new QWidget(SignInpage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 210, 283, 165));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        UserName = new QLineEdit(layoutWidget);
        UserName->setObjectName("UserName");
        UserName->setMinimumSize(QSize(281, 41));
        QFont font4;
        font4.setPointSize(11);
        UserName->setFont(font4);

        verticalLayout_2->addWidget(UserName);

        Password = new QLineEdit(layoutWidget);
        Password->setObjectName("Password");
        Password->setMinimumSize(QSize(281, 41));
        Password->setFont(font4);
        Password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(Password);

        Loginbtn = new QPushButton(layoutWidget);
        Loginbtn->setObjectName("Loginbtn");
        Loginbtn->setMinimumSize(QSize(281, 41));
        Loginbtn->setFont(font3);
        Loginbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_2->addWidget(Loginbtn);

        stackedWidget->addWidget(SignInpage);

        verticalLayout->addWidget(stackedWidget);

        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        Signinbtn->setText(QCoreApplication::translate("Login", "Sign in", nullptr));
        Signupbtn->setText(QCoreApplication::translate("Login", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("Login", "WELCOME", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Sign In", nullptr));
        SigninBackButton->setText(QCoreApplication::translate("Login", "< Back", nullptr));
        UserName->setPlaceholderText(QCoreApplication::translate("Login", " Username ", nullptr));
        Password->setText(QString());
        Password->setPlaceholderText(QCoreApplication::translate("Login", " Password", nullptr));
        Loginbtn->setText(QCoreApplication::translate("Login", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
