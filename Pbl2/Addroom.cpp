#include "Addroom.h"
#include "ui_Addroom.h"
#include "Room.h"
#include <QMessageBox>

Addroom::Addroom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Addroom)
{
    ui->setupUi(this);
}

Addroom::~Addroom()
{
    delete ui;
}


void Addroom::on_Addroombtn_clicked()
{
    string roomtype = ui->newRT->text().toStdString();
    RoomType *rt = RoomType::roomTypeList.searchID(roomtype);
    if (!rt)
    {
        QMessageBox::warning(this, "Lỗi!", "Loại phòng không hợp lệ");
        return;
    }
    Room::addRoom(roomtype);
    this->close();
}

