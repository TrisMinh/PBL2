#include "Booking.h"
#include "ui_Booking.h"
#include "Reservation.h"
#include "Date.h"

Booking::Booking(const std::string &id, QWidget *parent)
    : QDialog(parent)
    , id(id), ui(new Ui::Booking)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

Booking::~Booking()
{
    delete ui;
}

void Booking::on_Datbtn_clicked()
{
    DATE date;
    date.fromQDate(ui->dateEdit->date());
    bool c;
    int stay = ui->stay->text().toInt(&c);
    if (!c){
        QMessageBox::warning(this, "Warning", "Stay time không hợp lệ");
        return;
    }
    if (ui->dateEdit->date() < QDate::currentDate()) {
        QMessageBox::warning(this, "Lỗi", "Ngày không được nhỏ hơn ngày hiện tại!");
        ui->dateEdit->setDate(QDate::currentDate());
        return;
    }
    Reservation::addReservation(id, date, stay);
    this->close();
}

