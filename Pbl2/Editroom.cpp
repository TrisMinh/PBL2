#include "Editroom.h"
#include "ui_Editroom.h"
#include "Room.h"

Editroom::Editroom(const string& roomID, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Editroom)
    , room_ID(roomID)
{
    ui->setupUi(this);
    Room *r = Room::roomList.searchID(room_ID);
    if (r->getStatus()==3){
        ui->comboBox->setCurrentIndex(1);
    }
    string RT = r->getRoomType()->getID();
    ui->newRT->setText(QString::fromStdString(RT));
    ui->ID->setText(QString::fromStdString(room_ID));
}

Editroom::~Editroom()
{
    delete ui;
}

void Editroom::on_Updateroombtn_clicked()
{
    int newst;
    string st = ui->comboBox->currentText().toStdString();
    if (st == "Trống") newst = 0;
    else newst = 3;
    if (!RoomType::roomTypeList.searchID(ui->newRT->text().toStdString())){
        QMessageBox::warning(this, "Warning", "Room Type ID không tồn tại");
        return;
    } else {
    string newrt = ui->newRT->text().toStdString();
    string rt = this->room_ID;
    Room::updateRoom(room_ID, newst, newrt);
    this->close();
    }
}

