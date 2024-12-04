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
    if (!(roomtype == "RT.01" || roomtype == "RT.02" || roomtype == "RT.03" || roomtype == "RT.05"))
    {
        QMessageBox::warning(this, "Lỗi!", "Bạn đã nhập sai loại phòng. Vui lòng nhập lại!");
        return;
    }
    Room::addRoom(roomtype);
    this->close();
}

