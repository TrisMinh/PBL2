#include "Editroomtype.h"
#include "ui_Editroomtype.h"
#include <QMessageBox>

Editroomtype::Editroomtype(const string& id, const string& name, const string& des, double price, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Editroomtype), type_ID(id), name(name), description(des), price(price)
{
    ui->setupUi(this);
    ui->newname->setPlaceholderText(QString::fromStdString(name));
    ui->newprice->setPlaceholderText(QString::number(price));
    ui->newdes->setPlaceholderText(QString::fromStdString(des));
}

Editroomtype::~Editroomtype()
{
    delete ui;
}

void Editroomtype::on_Update_clicked()
{
    bool c;
    string newname = ui->newname->text().toStdString();
    int newprice = ui->newprice->text().toInt(&c);
    string newdes = ui->newdes->text().toStdString();
    if (ui->newname->text().isEmpty()){
        newname = name;
    }
    if (ui->newprice->text().isEmpty()){
        newprice = price;
    }
    if (ui->newdes->text().isEmpty()){
        newdes = description;
    }
    if (!ui->newprice->text().isEmpty()){
        if(!c){
            QMessageBox::warning(this, "Lỗi", "Giá dịch vụ không hợp lệ. Vui lòng nhập lại!");
            return;
        }
    }
    RoomType::updateRoomType(type_ID, newname, newdes, newprice);
    this->close();
}

