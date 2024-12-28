#include "Signin.h"
#include "ui_Signin.h"
#include "Account.h"
#include "Tenant.h"
#include "User.h"

Signin::Signin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Signin)
{
    ui->setupUi(this);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(1);
    // this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    ui->UserName->setFocus();
    connect(ui->UserName, &QLineEdit::returnPressed, this, [this]() {
        ui->Password_2->setFocus();
    });
    connect(ui->Password_2, &QLineEdit::returnPressed, this, [this]() {
        ui->Loginbtn->click();
    });
    connect(ui->hidebtn_2, &QPushButton::toggled, this, [this](bool checked) {
        if (checked) {
            ui->Password_2->setEchoMode(QLineEdit::Normal);
        } else {
            ui->Password_2->setEchoMode(QLineEdit::Password);
        }
    });
}

Signin::~Signin()
{
    delete ui;
}

void Signin::on_Loginbtn_clicked()
{
    string username = ui->UserName->text().toStdString();
    string password = ui->Password_2->text().toStdString();
    if (Account::signin(username, password)){
        if (Account::currentRole == 1) {
            Admin *admin = new Admin();

            QScreen *screen = QGuiApplication::primaryScreen();
            if (screen) {
                QRect screenGeometry = screen->geometry();
                int x = (screenGeometry.width() - admin->width()) / 2;
                int y = (screenGeometry.height() - admin->height()) / 2;
                admin->move(x, y - 35);
            }

            admin->show();
            this->hide();
        } else {
            User *user = new User();

            QScreen *screen = QGuiApplication::primaryScreen();
            if (screen) {
                QRect screenGeometry = screen->geometry();
                int x = (screenGeometry.width() - user->width()) / 2;
                int y = (screenGeometry.height() - user->height()) / 2;
                user->move(x, y - 35);
            }

            user->show();
            this->hide();
        }
    } else{ ui->signinfailed->setText("Sai tên tài khoản hoặc mật khẩu");}
}


void Signin::on_Signupbtn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}


void Signin::on_backbtn_clicked()
{
    if (ui->stackedWidget_3->currentIndex() == 2){
        ui->comboBox->setEnabled(true);
        ui->comboBox->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->stackedWidget_3->setCurrentIndex(1);
    } else {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void Signin::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0){
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    if (index == 1){
        ui->stackedWidget_3->setCurrentIndex(0);
    }
}


void Signin::on_DKadminbtn_clicked()
{
    bool check=true;
    if (ui->admincode->text().toStdString() != Account::AdminCode){
        ui->admincodefail->setText("Admin code sai");
        check = false;
    } else { ui->admincodefail->setText("");}
    if (Account::searchByUsername(ui->UserNameadmin->text().toStdString(), 0) != NULL){
        ui->usernamefailadmin->setText("Username is already in use");
        check = false;
    } else {ui->usernamefailadmin->setText("");}
    if (ui->Passwordadmin->text()!=ui->Cfpassadmin->text()){
        ui->passfailadmin->setText("Mật khẩu không khớp");
        check = false;
    } else {ui->passfailadmin->setText("");}
    if (check){
        Account acc(ui->UserNameadmin->text().toStdString(), ui->Passwordadmin->text().toStdString(), "Admin",1);
        Account::accountList.add(acc);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->admincode->setText("");
        ui->UserNameadmin->setText("");
        ui->Passwordadmin->setText("");
        ui->Cfpassadmin->setText("");
        QMessageBox::information(this, "Đăng ký", "Đăng ký tài khoản thành công!");
        Account::accountList.updateFile("Account.txt");
    }
}

void Signin::on_tieptucbtn_clicked()
{
    bool check = true;
    if (Account::searchByUsername(ui->UserNametenant->text().toStdString(), 0) != NULL){
        ui->usernamefailtenant->setText("Username is already in use");
        check = false;
    } else {ui->usernamefailtenant->setText("");}
    if (ui->UserNametenant->text().isEmpty() || ui->Passwordtenant->text().isEmpty()){
        QMessageBox::information(this, "Thông báo", "Vui lòng nhập đầy đủ thông tin");
        check = false;
    }
    if (ui->Passwordtenant->text()!=ui->Cfpasstenant->text()){
        ui->passfailtenant->setText("Mật khẩu không khớp");
        check = false;
    } else {ui->passfailtenant->setText("");}
    if (check){
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->comboBox->setEnabled(false);
        ui->comboBox->setStyleSheet("background-color: #f3f3f3");
    }
}




void Signin::on_Dktenantbtn_clicked()
{
    bool c;
    string firstName, lastName;
    bool gender = ui->gender->currentIndex();
    QString name = ui->name->text();
    int lastSpaceIndex = name.lastIndexOf(' ');
    if (lastSpaceIndex != -1) {
        lastName = name.left(lastSpaceIndex).toStdString();
        firstName = name.mid(lastSpaceIndex + 1).toStdString();
    }
    string sdt = ui->sdt->text().toStdString();
    string cccd = ui->cccd->text().toStdString();
    int birth = ui->birth->text().toInt(&c);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    if (ui->name->text().isEmpty() || ui->sdt->text().isEmpty() || ui->birth->text().isEmpty()){
        QMessageBox::information(this, "Thông báo", "Vui lòng nhập đầy đủ thông tin");
    } else
    if (birth> (1900 + ltm->tm_year) || !c){
        ui->error->setText("Năm sinh không hợp lệ");
    } else {
        ui->error->setText("");
        Tenant tenant(lastName, firstName, sdt, cccd, birth, gender);
        Tenant::tenantList.add(tenant);

        Account acc(ui->UserNametenant->text().toStdString(), ui->Passwordtenant->text().toStdString(), tenant.getID(),0);
        Account::accountList.add(acc);
        Tenant::updateFile("Tenant.txt");
        ui->UserNametenant->setText("");
        ui->Passwordtenant->setText("");
        ui->Cfpasstenant->setText("");
        ui->name->setText("");
        ui->sdt->setText("");
        ui->cccd->setText("");
        ui->birth->setText("");
        ui->gender->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->comboBox->setEnabled(true);
        ui->comboBox->setStyleSheet("background-color: rgb(255, 255, 255);");
        QMessageBox::information(this, "Đăng ký", "Đăng ký tài khoản thành công!");
        Account::accountList.updateFile("Account.txt");
    }
}


void Signin::on_tieptucpr_clicked()
{
    string phone = ui->xmsdt->text().toStdString();
    string cccd = ui->xmcccd->text().toStdString();
    LinkedList<Account>::Node* account = Account::verifyTenantInfo(phone, cccd);

    if (account != nullptr) {
        ui->stackedWidget_2->setCurrentIndex(2);
        ui->mk->setText(QString::fromStdString("Mật khẩu của bạn là: " +account->data.getpassword()));
        // ui->stackedWidget_2->setCurrentIndex(3);
    } else {
        // QMessageBox::information(this, "Xác minh", "Thông tin xác minh không chính xác");
        ui->xmfail->setText("Thông tin xác minh không chính xác");
    }
}


void Signin::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void Signin::on_backbtn_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->xmsdt->clear();
    ui->xmcccd->clear();
}

