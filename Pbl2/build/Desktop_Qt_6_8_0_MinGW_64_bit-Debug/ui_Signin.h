/********************************************************************************
** Form generated from reading UI file 'Signin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QPushButton *Signupbtn;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Password_2;
    QPushButton *hidebtn_2;
    QPushButton *pushButton;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *UserName;
    QPushButton *Loginbtn;
    QLabel *label_2;
    QLabel *signinfailed;
    QWidget *page_8;
    QLabel *label_25;
    QPushButton *backbtn_2;
    QLineEdit *xmsdt;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *tieptucpr;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *xmcccd;
    QLabel *xmfail;
    QWidget *page_9;
    QLabel *label_3;
    QLabel *label_28;
    QLabel *label_4;
    QPushButton *backbtn_3;
    QLabel *mk;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QLabel *label_10;
    QLabel *label_12;
    QComboBox *comboBox;
    QPushButton *backbtn;
    QStackedWidget *stackedWidget_3;
    QWidget *page_5;
    QPushButton *DKadminbtn;
    QLabel *label_11;
    QLineEdit *UserNameadmin;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *Passwordadmin;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *Cfpassadmin;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *admincode;
    QLabel *label_17;
    QLabel *usernamefailadmin;
    QLabel *passfailadmin;
    QLabel *admincodefail;
    QWidget *page_6;
    QLabel *label_15;
    QLineEdit *UserNametenant;
    QPushButton *tieptucbtn;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *Passwordtenant;
    QLabel *label_16;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *Cfpasstenant;
    QLabel *label_18;
    QLabel *usernamefailtenant;
    QLabel *passfailtenant;
    QWidget *page_7;
    QLabel *label_19;
    QPushButton *Dktenantbtn;
    QLabel *label_20;
    QLineEdit *name;
    QLineEdit *sdt;
    QLabel *label_21;
    QLineEdit *cccd;
    QLabel *label_22;
    QLineEdit *birth;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *layoutWidget11;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *gender;
    QPushButton *hidebtn_3;
    QLabel *error;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QGraphicsView *graphicsView;
    QWidget *page_2;

    void setupUi(QMainWindow *Signin)
    {
        if (Signin->objectName().isEmpty())
            Signin->setObjectName("Signin");
        Signin->resize(833, 550);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Signin->sizePolicy().hasHeightForWidth());
        Signin->setSizePolicy(sizePolicy);
        Signin->setMinimumSize(QSize(417, 550));
        Signin->setMaximumSize(QSize(833, 530));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Resources/logoooo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Signin->setWindowIcon(icon);
        centralwidget = new QWidget(Signin);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(407, 16777215));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        stackedWidget_2 = new QStackedWidget(frame);
        stackedWidget_2->setObjectName("stackedWidget_2");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        layoutWidget10 = new QWidget(page_3);
        layoutWidget10->setObjectName("layoutWidget10");
        layoutWidget10->setGeometry(QRect(110, 400, 185, 16));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget10);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(label_6);

        Signupbtn = new QPushButton(layoutWidget10);
        Signupbtn->setObjectName("Signupbtn");
        QFont font;
        font.setBold(true);
        Signupbtn->setFont(font);
        Signupbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Signupbtn->setStyleSheet(QString::fromUtf8("border:none;"));

        horizontalLayout_4->addWidget(Signupbtn);

        label = new QLabel(page_3);
        label->setObjectName("label");
        label->setGeometry(QRect(32, 200, 171, 16));
        layoutWidget_2 = new QWidget(page_3);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(30, 290, 333, 42));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Password_2 = new QLineEdit(layoutWidget_2);
        Password_2->setObjectName("Password_2");
        Password_2->setMinimumSize(QSize(296, 40));
        Password_2->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(11);
        Password_2->setFont(font1);
        Password_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
"border-right: none;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        Password_2->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_5->addWidget(Password_2);

        hidebtn_2 = new QPushButton(layoutWidget_2);
        hidebtn_2->setObjectName("hidebtn_2");
        hidebtn_2->setMinimumSize(QSize(35, 40));
        hidebtn_2->setMaximumSize(QSize(35, 16777215));
        hidebtn_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        hidebtn_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 20px;\n"
"border-bottom-right-radius: 20px;\n"
"border-left: none;\n"
"background-color: rgb(255, 255, 255);\n"
"padding-left:-5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Resources/hide.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Resources/view.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        hidebtn_2->setIcon(icon1);
        hidebtn_2->setIconSize(QSize(15, 15));
        hidebtn_2->setCheckable(true);

        horizontalLayout_5->addWidget(hidebtn_2);

        pushButton = new QPushButton(page_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(269, 332, 91, 16));
        QFont font2;
        font2.setPointSize(8);
        pushButton->setFont(font2);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border:none;"));
        layoutWidget_3 = new QWidget(page_3);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(30, 120, 121, 42));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName("label_7");
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        label_7->setFont(font3);

        verticalLayout_8->addWidget(label_7);

        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName("label_8");

        verticalLayout_8->addWidget(label_8);

        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 30, 40, 40));
        label_9->setMinimumSize(QSize(40, 40));
        label_9->setMaximumSize(QSize(40, 40));
        QFont font4;
        font4.setPointSize(12);
        label_9->setFont(font4);
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/logoooo.png")));
        label_9->setScaledContents(true);
        UserName = new QLineEdit(page_3);
        UserName->setObjectName("UserName");
        UserName->setGeometry(QRect(32, 218, 330, 40));
        UserName->setMinimumSize(QSize(330, 40));
        UserName->setFont(font1);
        UserName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        Loginbtn = new QPushButton(page_3);
        Loginbtn->setObjectName("Loginbtn");
        Loginbtn->setGeometry(QRect(32, 360, 330, 40));
        Loginbtn->setMinimumSize(QSize(330, 40));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        Loginbtn->setFont(font5);
        Loginbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Loginbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"color:white;\n"
"}"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(33, 270, 181, 16));
        signinfailed = new QLabel(page_3);
        signinfailed->setObjectName("signinfailed");
        signinfailed->setGeometry(QRect(31, 331, 241, 16));
        signinfailed->setMinimumSize(QSize(241, 0));
        signinfailed->setFont(font2);
        signinfailed->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        stackedWidget_2->addWidget(page_3);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        label_25 = new QLabel(page_8);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(32, 110, 300, 41));
        label_25->setMinimumSize(QSize(300, 0));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        label_25->setFont(font6);
        backbtn_2 = new QPushButton(page_8);
        backbtn_2->setObjectName("backbtn_2");
        backbtn_2->setGeometry(QRect(10, 10, 51, 16));
        backbtn_2->setStyleSheet(QString::fromUtf8("padding-left:-5px;\n"
"border: 0.5px solid gray;\n"
"border-radius: 5px;\n"
"background-color: rgb(255, 255, 255);"));
        xmsdt = new QLineEdit(page_8);
        xmsdt->setObjectName("xmsdt");
        xmsdt->setGeometry(QRect(32, 218, 330, 40));
        xmsdt->setMinimumSize(QSize(330, 40));
        xmsdt->setFont(font1);
        xmsdt->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_26 = new QLabel(page_8);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(32, 270, 201, 16));
        label_27 = new QLabel(page_8);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(32, 200, 241, 16));
        tieptucpr = new QPushButton(page_8);
        tieptucpr->setObjectName("tieptucpr");
        tieptucpr->setGeometry(QRect(32, 362, 330, 40));
        tieptucpr->setMinimumSize(QSize(330, 40));
        tieptucpr->setFont(font5);
        tieptucpr->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tieptucpr->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"color:white;\n"
"}"));
        layoutWidget = new QWidget(page_8);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(32, 290, 332, 57));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        xmcccd = new QLineEdit(layoutWidget);
        xmcccd->setObjectName("xmcccd");
        xmcccd->setMinimumSize(QSize(330, 40));
        xmcccd->setFont(font1);
        xmcccd->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout_4->addWidget(xmcccd);

        xmfail = new QLabel(layoutWidget);
        xmfail->setObjectName("xmfail");
        xmfail->setFont(font2);
        xmfail->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        xmfail->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(xmfail);

        stackedWidget_2->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_3 = new QLabel(page_9);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 180, 70, 70));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/accept.png")));
        label_3->setScaledContents(true);
        label_28 = new QLabel(page_9);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(32, 110, 351, 41));
        label_28->setMinimumSize(QSize(351, 0));
        label_28->setFont(font6);
        label_4 = new QLabel(page_9);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 260, 201, 21));
        QFont font7;
        font7.setPointSize(13);
        label_4->setFont(font7);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backbtn_3 = new QPushButton(page_9);
        backbtn_3->setObjectName("backbtn_3");
        backbtn_3->setGeometry(QRect(10, 10, 51, 16));
        backbtn_3->setStyleSheet(QString::fromUtf8("padding-left:-5px;\n"
"border: 0.5px solid gray;\n"
"border-radius: 5px;\n"
"background-color: rgb(255, 255, 255);"));
        mk = new QLabel(page_9);
        mk->setObjectName("mk");
        mk->setGeometry(QRect(0, 300, 399, 18));
        QFont font8;
        font8.setPointSize(10);
        mk->setFont(font8);
        mk->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_2->addWidget(page_9);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_3 = new QFrame(page_4);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(0, 100));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:none;\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(32, 16, 141, 41));
        label_10->setMinimumSize(QSize(141, 0));
        label_10->setFont(font6);
        label_12 = new QLabel(frame_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(32, 70, 150, 16));
        label_12->setMinimumSize(QSize(150, 0));
        label_12->setFont(font1);
        comboBox = new QComboBox(frame_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(200, 67, 100, 25));
        comboBox->setMinimumSize(QSize(100, 25));
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        backbtn = new QPushButton(frame_3);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(0, 0, 51, 16));
        backbtn->setStyleSheet(QString::fromUtf8("padding-left:-5px;\n"
"border: 0.5px solid gray;\n"
"border-radius: 5px;\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(frame_3);

        stackedWidget_3 = new QStackedWidget(page_4);
        stackedWidget_3->setObjectName("stackedWidget_3");
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        DKadminbtn = new QPushButton(page_5);
        DKadminbtn->setObjectName("DKadminbtn");
        DKadminbtn->setGeometry(QRect(32, 260, 330, 40));
        DKadminbtn->setMinimumSize(QSize(330, 40));
        DKadminbtn->setFont(font5);
        DKadminbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        DKadminbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"color:white;\n"
"}"));
        label_11 = new QLabel(page_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(32, 21, 131, 16));
        UserNameadmin = new QLineEdit(page_5);
        UserNameadmin->setObjectName("UserNameadmin");
        UserNameadmin->setGeometry(QRect(32, 37, 191, 40));
        UserNameadmin->setMinimumSize(QSize(0, 40));
        UserNameadmin->setFont(font1);
        UserNameadmin->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        layoutWidget_4 = new QWidget(page_5);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(33, 111, 332, 42));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        Passwordadmin = new QLineEdit(layoutWidget_4);
        Passwordadmin->setObjectName("Passwordadmin");
        Passwordadmin->setMinimumSize(QSize(330, 40));
        Passwordadmin->setMaximumSize(QSize(300, 16777215));
        Passwordadmin->setFont(font1);
        Passwordadmin->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        Passwordadmin->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_7->addWidget(Passwordadmin);

        label_13 = new QLabel(page_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(33, 95, 121, 16));
        label_14 = new QLabel(page_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(32, 172, 221, 16));
        layoutWidget_5 = new QWidget(page_5);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(33, 188, 332, 42));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        Cfpassadmin = new QLineEdit(layoutWidget_5);
        Cfpassadmin->setObjectName("Cfpassadmin");
        Cfpassadmin->setMinimumSize(QSize(330, 40));
        Cfpassadmin->setMaximumSize(QSize(300, 16777215));
        Cfpassadmin->setFont(font1);
        Cfpassadmin->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        Cfpassadmin->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_8->addWidget(Cfpassadmin);

        layoutWidget_7 = new QWidget(page_5);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(231, 37, 131, 42));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        admincode = new QLineEdit(layoutWidget_7);
        admincode->setObjectName("admincode");
        admincode->setMinimumSize(QSize(129, 40));
        admincode->setMaximumSize(QSize(100, 16777215));
        admincode->setFont(font1);
        admincode->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        admincode->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_10->addWidget(admincode);

        label_17 = new QLabel(page_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(231, 21, 101, 16));
        usernamefailadmin = new QLabel(page_5);
        usernamefailadmin->setObjectName("usernamefailadmin");
        usernamefailadmin->setGeometry(QRect(32, 78, 181, 16));
        usernamefailadmin->setFont(font2);
        usernamefailadmin->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        passfailadmin = new QLabel(page_5);
        passfailadmin->setObjectName("passfailadmin");
        passfailadmin->setGeometry(QRect(32, 230, 241, 16));
        passfailadmin->setFont(font2);
        passfailadmin->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        admincodefail = new QLabel(page_5);
        admincodefail->setObjectName("admincodefail");
        admincodefail->setGeometry(QRect(230, 80, 141, 16));
        admincodefail->setFont(font2);
        admincodefail->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        stackedWidget_3->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label_15 = new QLabel(page_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(31, 96, 161, 16));
        UserNametenant = new QLineEdit(page_6);
        UserNametenant->setObjectName("UserNametenant");
        UserNametenant->setGeometry(QRect(32, 37, 330, 40));
        UserNametenant->setMinimumSize(QSize(330, 40));
        UserNametenant->setFont(font1);
        UserNametenant->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        tieptucbtn = new QPushButton(page_6);
        tieptucbtn->setObjectName("tieptucbtn");
        tieptucbtn->setGeometry(QRect(32, 260, 330, 40));
        tieptucbtn->setMinimumSize(QSize(330, 40));
        tieptucbtn->setFont(font5);
        tieptucbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tieptucbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"color:white;\n"
"}"));
        layoutWidget_6 = new QWidget(page_6);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(31, 112, 332, 42));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        Passwordtenant = new QLineEdit(layoutWidget_6);
        Passwordtenant->setObjectName("Passwordtenant");
        Passwordtenant->setMinimumSize(QSize(330, 40));
        Passwordtenant->setMaximumSize(QSize(300, 16777215));
        Passwordtenant->setFont(font1);
        Passwordtenant->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        Passwordtenant->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_9->addWidget(Passwordtenant);

        label_16 = new QLabel(page_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(32, 21, 191, 16));
        layoutWidget_8 = new QWidget(page_6);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(32, 189, 332, 42));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Cfpasstenant = new QLineEdit(layoutWidget_8);
        Cfpasstenant->setObjectName("Cfpasstenant");
        Cfpasstenant->setMinimumSize(QSize(330, 40));
        Cfpasstenant->setMaximumSize(QSize(300, 16777215));
        Cfpasstenant->setFont(font1);
        Cfpasstenant->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        Cfpasstenant->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_11->addWidget(Cfpasstenant);

        label_18 = new QLabel(page_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(32, 173, 171, 16));
        usernamefailtenant = new QLabel(page_6);
        usernamefailtenant->setObjectName("usernamefailtenant");
        usernamefailtenant->setGeometry(QRect(32, 78, 271, 16));
        usernamefailtenant->setFont(font2);
        usernamefailtenant->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        passfailtenant = new QLabel(page_6);
        passfailtenant->setObjectName("passfailtenant");
        passfailtenant->setGeometry(QRect(32, 230, 241, 16));
        passfailtenant->setFont(font2);
        passfailtenant->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        stackedWidget_3->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_19 = new QLabel(page_7);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(32, 10, 231, 31));
        label_19->setMinimumSize(QSize(231, 0));
        QFont font9;
        font9.setPointSize(13);
        font9.setBold(true);
        label_19->setFont(font9);
        Dktenantbtn = new QPushButton(page_7);
        Dktenantbtn->setObjectName("Dktenantbtn");
        Dktenantbtn->setGeometry(QRect(32, 350, 330, 40));
        Dktenantbtn->setMinimumSize(QSize(330, 40));
        Dktenantbtn->setFont(font5);
        Dktenantbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Dktenantbtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(0, 0, 0);\n"
"color:white;\n"
"}"));
        label_20 = new QLabel(page_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(33, 61, 241, 16));
        label_20->setMinimumSize(QSize(241, 0));
        name = new QLineEdit(page_7);
        name->setObjectName("name");
        name->setGeometry(QRect(33, 77, 330, 40));
        name->setMinimumSize(QSize(330, 40));
        name->setFont(font1);
        name->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        sdt = new QLineEdit(page_7);
        sdt->setObjectName("sdt");
        sdt->setGeometry(QRect(33, 147, 330, 40));
        sdt->setMinimumSize(QSize(330, 40));
        sdt->setFont(font1);
        sdt->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_21 = new QLabel(page_7);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(33, 131, 201, 16));
        label_21->setMinimumSize(QSize(201, 0));
        cccd = new QLineEdit(page_7);
        cccd->setObjectName("cccd");
        cccd->setGeometry(QRect(32, 210, 330, 40));
        cccd->setMinimumSize(QSize(330, 40));
        cccd->setFont(font1);
        cccd->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_22 = new QLabel(page_7);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(32, 194, 151, 16));
        label_22->setMinimumSize(QSize(151, 0));
        birth = new QLineEdit(page_7);
        birth->setObjectName("birth");
        birth->setGeometry(QRect(34, 280, 200, 40));
        birth->setMinimumSize(QSize(200, 40));
        birth->setFont(font1);
        birth->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:20px;\n"
"border: 1px solid gray;\n"
"border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_23 = new QLabel(page_7);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(32, 260, 101, 16));
        label_23->setMinimumSize(QSize(101, 0));
        label_24 = new QLabel(page_7);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(260, 260, 101, 16));
        label_24->setMinimumSize(QSize(101, 0));
        layoutWidget11 = new QWidget(page_7);
        layoutWidget11->setObjectName("layoutWidget11");
        layoutWidget11->setGeometry(QRect(262, 279, 102, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget11);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gender = new QComboBox(layoutWidget11);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName("gender");
        gender->setMinimumSize(QSize(65, 40));
        gender->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"padding-left:15px;\n"
"border: 1px solid gray;\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 20px;\n"
"border-right: none;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox::drop-down {\n"
"       border: none;\n"
"       background: transparent;\n"
" }"));

        horizontalLayout_2->addWidget(gender);

        hidebtn_3 = new QPushButton(layoutWidget11);
        hidebtn_3->setObjectName("hidebtn_3");
        hidebtn_3->setMinimumSize(QSize(35, 40));
        hidebtn_3->setMaximumSize(QSize(35, 16777215));
        hidebtn_3->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-top-right-radius: 20px;\n"
"border-bottom-right-radius: 20px;\n"
"border-left: none;\n"
"background-color: rgb(255, 255, 255);\n"
"padding-left:-5px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Resources/down-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Resources/down-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        hidebtn_3->setIcon(icon2);
        hidebtn_3->setIconSize(QSize(15, 15));
        hidebtn_3->setCheckable(true);

        horizontalLayout_2->addWidget(hidebtn_3);

        error = new QLabel(page_7);
        error->setObjectName("error");
        error->setGeometry(QRect(32, 320, 241, 16));
        error->setFont(font2);
        error->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border:none"));
        stackedWidget_3->addWidget(page_7);

        verticalLayout_3->addWidget(stackedWidget_3);

        stackedWidget_2->addWidget(page_4);

        verticalLayout_2->addWidget(stackedWidget_2);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(page);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(frame_2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/Resources/Pbl2.jpg);"));

        verticalLayout_5->addWidget(graphicsView);


        horizontalLayout->addWidget(frame_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        Signin->setCentralWidget(centralwidget);

        retranslateUi(Signin);

        stackedWidget_2->setCurrentIndex(3);
        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Signin);
    } // setupUi

    void retranslateUi(QMainWindow *Signin)
    {
        Signin->setWindowTitle(QCoreApplication::translate("Signin", "Room Management System", nullptr));
        label_6->setText(QCoreApplication::translate("Signin", "Don't have any account?", nullptr));
        Signupbtn->setText(QCoreApplication::translate("Signin", "Sign up", nullptr));
        label->setText(QCoreApplication::translate("Signin", "Username", nullptr));
        Password_2->setText(QString());
        Password_2->setPlaceholderText(QString());
        hidebtn_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("Signin", "Forgot Password?", nullptr));
        label_7->setText(QCoreApplication::translate("Signin", "Welcome", nullptr));
        label_8->setText(QCoreApplication::translate("Signin", "Sign in your account", nullptr));
        label_9->setText(QString());
        UserName->setPlaceholderText(QString());
        Loginbtn->setText(QCoreApplication::translate("Signin", "Log In", nullptr));
        label_2->setText(QCoreApplication::translate("Signin", "Password", nullptr));
        signinfailed->setText(QString());
        label_25->setText(QCoreApplication::translate("Signin", "Password recovery", nullptr));
        backbtn_2->setText(QCoreApplication::translate("Signin", "< Back", nullptr));
        xmsdt->setPlaceholderText(QString());
        label_26->setText(QCoreApplication::translate("Signin", "Enter CCCD", nullptr));
        label_27->setText(QCoreApplication::translate("Signin", "Enter Phone Number", nullptr));
        tieptucpr->setText(QCoreApplication::translate("Signin", "Ti\341\272\277p t\341\273\245c", nullptr));
        xmcccd->setPlaceholderText(QString());
        xmfail->setText(QString());
        label_3->setText(QString());
        label_28->setText(QCoreApplication::translate("Signin", "Password recovery", nullptr));
        label_4->setText(QCoreApplication::translate("Signin", "Verification Successful", nullptr));
        backbtn_3->setText(QCoreApplication::translate("Signin", "< Back", nullptr));
        mk->setText(QString());
        label_10->setText(QCoreApplication::translate("Signin", "Sign up", nullptr));
        label_12->setText(QCoreApplication::translate("Signin", "Select Account Type", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Signin", "Tenant", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Signin", "Admin", nullptr));

        backbtn->setText(QCoreApplication::translate("Signin", "< Back", nullptr));
        DKadminbtn->setText(QCoreApplication::translate("Signin", "\304\220\304\203ng k\303\275", nullptr));
        label_11->setText(QCoreApplication::translate("Signin", "Username", nullptr));
        UserNameadmin->setPlaceholderText(QString());
        Passwordadmin->setText(QString());
        Passwordadmin->setPlaceholderText(QString());
        label_13->setText(QCoreApplication::translate("Signin", "Password", nullptr));
        label_14->setText(QCoreApplication::translate("Signin", "Confirm Password", nullptr));
        Cfpassadmin->setText(QString());
        Cfpassadmin->setPlaceholderText(QString());
        admincode->setText(QString());
        admincode->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("Signin", "Admin Code", nullptr));
        usernamefailadmin->setText(QString());
        passfailadmin->setText(QString());
        admincodefail->setText(QString());
        label_15->setText(QCoreApplication::translate("Signin", "Password", nullptr));
        UserNametenant->setPlaceholderText(QString());
        tieptucbtn->setText(QCoreApplication::translate("Signin", "Ti\341\272\277p t\341\273\245c", nullptr));
        Passwordtenant->setText(QString());
        Passwordtenant->setPlaceholderText(QString());
        label_16->setText(QCoreApplication::translate("Signin", "Username", nullptr));
        Cfpasstenant->setText(QString());
        Cfpasstenant->setPlaceholderText(QString());
        label_18->setText(QCoreApplication::translate("Signin", "Confirm Password", nullptr));
        usernamefailtenant->setText(QString());
        passfailtenant->setText(QString());
        label_19->setText(QCoreApplication::translate("Signin", "Enter Personal Information", nullptr));
        Dktenantbtn->setText(QCoreApplication::translate("Signin", "\304\220\304\203ng k\303\275", nullptr));
        label_20->setText(QCoreApplication::translate("Signin", "Enter Full Name", nullptr));
        name->setPlaceholderText(QString());
        sdt->setPlaceholderText(QString());
        label_21->setText(QCoreApplication::translate("Signin", "Enter Phone Number", nullptr));
        cccd->setPlaceholderText(QString());
        label_22->setText(QCoreApplication::translate("Signin", "Enter CCCD", nullptr));
        birth->setPlaceholderText(QString());
        label_23->setText(QCoreApplication::translate("Signin", "Year of Birth", nullptr));
        label_24->setText(QCoreApplication::translate("Signin", "Gender", nullptr));
        gender->setItemText(0, QCoreApplication::translate("Signin", "Male", nullptr));
        gender->setItemText(1, QCoreApplication::translate("Signin", "Female", nullptr));

        hidebtn_3->setText(QString());
        error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Signin: public Ui_Signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
