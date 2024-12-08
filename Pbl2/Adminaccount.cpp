#include "Adminaccount.h"
#include "ui_Adminaccount.h"
#include "Account.h"
#include <QMessageBox>

Adminaccount::Adminaccount(bool check, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Adminaccount), check(check)
{
    ui->setupUi(this);
    if (check){
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

Adminaccount::~Adminaccount()
{
    delete ui;
}


void Adminaccount::on_Changepass_clicked()
{
    if (!Account::changePassword(ui->oldpass->text().toStdString(), ui->newpass->text().toStdString())){
        QMessageBox::warning(this, "Warning", "Nhập sai Password cũ. Vui lòng thử lại!");
        return;
    } else {
        this->close();
    }
}


void Adminaccount::on_Changecode_clicked()
{
    if (!Account::setAdminCode(ui->Oldcode->text().toStdString(), ui->Newcode->text().toStdString())){
        QMessageBox::warning(this, "Warning", "Nhập sai Admincode cũ. Vui lòng thử lại!");
        return;
        ui->Oldcode->clear();
    } else {
        this->close();
    }
}

