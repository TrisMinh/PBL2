#include "AddService.h"
#include "ui_AddService.h"
#include "Service.h"
#include <QMessageBox>

AddService::AddService(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddService)
{
    ui->setupUi(this);
}

AddService::~AddService()
{
    delete ui;
}

void AddService::on_AddSerbtn_clicked()
{
    string name = ui->newname->text().toStdString();
    bool c;
    int price = ui->newprice->text().toInt(&c);
    string des = ui->newdes->text().toStdString();
    if(!c){
        QMessageBox::warning(this, "Lỗi", "Giá dịch vụ không hợp lệ. Vui lòng nhập lại!");
        return;
    }
    Service::addService(name, price, des);
    this->close();
}

