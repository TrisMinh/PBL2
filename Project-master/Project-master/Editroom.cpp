#include "Editroom.h"
#include "ui_Editroom.h"
#include "Room.h"

Editroom::Editroom(const string& roomID, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Editroom)
    , room_ID(roomID)
{
    ui->setupUi(this);
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
    else newst = 2;
    string newrt = ui->newRT->text().toStdString();
    string rt = this->room_ID;
    Room::updateRoom(rt, newst, newrt);
}

