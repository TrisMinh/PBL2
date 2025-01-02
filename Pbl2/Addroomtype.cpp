#include "Addroomtype.h"
#include "ui_Addroomtype.h"
#include "RoomType.h"

Addroomtype::Addroomtype(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Addroomtype)
{
    ui->setupUi(this);
}

Addroomtype::~Addroomtype()
{
    delete ui;
}

void Addroomtype::on_AddRTbtn_clicked()
{
    bool c;
    string newname = ui->newname->text().toStdString();
    string newdes = ui->newdes->text().toStdString();
    double newprice = ui->newprice->text().toDouble(&c);
    if (ui->newname->text().isEmpty()){
        QMessageBox::warning(this, "Warning", "Vui lòng nhập tên RoomType");
        return;
    }
    if (ui->newdes->text().isEmpty()){
        QMessageBox::warning(this, "Warning", "Vui lòng nhập Mô tả");
        return;
    }
    if (!c || newprice<0){
        QMessageBox::warning(this, "Warning", "Giá không hợp lệ");
        return;
    }
    RoomType::addRoomType(newname, newdes, newprice);
    this->close();
}

