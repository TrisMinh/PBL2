#include "AddService.h"
#include "ui_AddService.h"
#include "Service.h"
#include <QMessageBox>

AddService::AddService(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddService)
{
    ui->setupUi(this);
    ui->checkBox_2->setChecked(true);
}

AddService::~AddService()
{
    delete ui;
}

void AddService::on_AddSerbtn_clicked()
{
    string name = ui->newname->text().toStdString();
    bool c, mandatory;
    int price = ui->newprice->text().toInt(&c);
    string des = ui->newdes->text().toStdString();
    if (ui->newname->text().isEmpty()){
        QMessageBox::warning(this, "Warning", "Vui lòng nhập tên RoomType");
        return;
    }
    if (ui->newdes->text().isEmpty()){
        QMessageBox::warning(this, "Warning", "Vui lòng nhập Mô tả");
        return;
    }
    if(!c){
        QMessageBox::warning(this, "Lỗi", "Giá dịch vụ không hợp lệ. Vui lòng nhập lại!");
        return;
    }
    if (ui->checkBox->isChecked()){
        mandatory=1;
    } else { mandatory=0;}
    Service::addService(name, price, des, mandatory);
    this->close();
}

