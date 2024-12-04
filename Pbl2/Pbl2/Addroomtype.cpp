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
    string newname = ui->newname->text().toStdString();
    string newdes = ui->newdes->text().toStdString();
    double newprice = ui->newprice->text().toInt();
    RoomType::addRoomType(newname, newdes, newprice);
    this->close();
}

