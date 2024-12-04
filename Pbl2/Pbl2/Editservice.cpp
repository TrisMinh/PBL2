#include "Editservice.h"
#include "ui_Editservice.h"
#include "Service.h"
#include <QMessageBox>

Editservice::Editservice(const string& service_ID, const string& name, int price, const string& des, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Editservice)
    , service_ID(service_ID)
    , name(name)
    , unit_price(price)
    , description(des)
{
    ui->setupUi(this);
    ui->name->setPlaceholderText(QString::fromStdString(name));
    ui->price->setPlaceholderText(QString::number(price));
    ui->des->setPlaceholderText(QString::fromStdString(des));
}

Editservice::~Editservice()
{
    delete ui;
}

void Editservice::on_UpdateSerbtn_clicked()
{
    bool c;
    string newname = ui->name->text().toStdString();
    int newprice = ui->price->text().toInt(&c);
    string newdes = ui->des->text().toStdString();
    if (ui->name->text().isEmpty()){
        newname = name;
    }
    if (ui->price->text().isEmpty()){
        newprice = unit_price;
    }
    if (ui->des->text().isEmpty()){
        newdes = description;
    }
    if (!ui->price->text().isEmpty()){
    if(!c){
        QMessageBox::warning(this, "Lỗi", "Giá dịch vụ không hợp lệ. Vui lòng nhập lại!");
        return;
    }
    }
    Service::updateService(service_ID, newname, newprice, newdes);
    this->close();
}

