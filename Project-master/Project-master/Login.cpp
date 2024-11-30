#include "Login.h"
#include "ui_Login.h"
#include "Account.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->UserName, &QLineEdit::returnPressed, this, [this]() {
        ui->Password->setFocus();
    });
    connect(ui->Password, &QLineEdit::returnPressed, this, [this]() {
        ui->Loginbtn->click();
    });
}

Login::~Login()
{
    delete ui;
}

void Login::on_Signinbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->UserName->setFocus();
}


void Login::on_SigninBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Login::on_Loginbtn_clicked()
{
    string username = ui->UserName->text().toStdString();
    string password = ui->Password->text().toStdString();
    if (Account::signin(username, password)){
        qDebug() << "Ok";
        Admin *admin = new Admin();
        admin->show();
        this->hide();
    } else{ qDebug() <<"not OK";}
}

