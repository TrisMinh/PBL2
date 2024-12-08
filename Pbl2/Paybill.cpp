#include "Paybill.h"
#include "ui_Paybill.h"
#include "Payment.h"
#include <QMessageBox>

Paybill::Paybill(const std::string &id, QWidget *parent)
    : QDialog(parent)
    , id(id), ui(new Ui::Paybill)
{
    ui->setupUi(this);
    for (LinkedList<Payment>::Node* current = Payment::paymentList.begin(); current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getID() == id) {
            ui->paymentID->setText(QString::fromStdString(payment.getID()));
            ui->roomID->setText(QString::fromStdString(payment.getRoomID()));
            ui->deposit->setText(QString::number(payment.getdepositAmount(), 'f', 2));
            ui->remaining->setText(QString::number(payment.getRemainingAmount(), 'f', 2));
            remaining = payment.getRemainingAmount();
        }
    }
}

Paybill::~Paybill()
{
    delete ui;
}

void Paybill::on_Datbtn_clicked()
{
    bool c;
    double amount = ui->amount->text().toDouble(&c);
    if (!c || amount < 0){
        QMessageBox::warning(this, "Warning", "Nhap so tien khong hop le");
        return;
    }
    const double epsilon = 0.0001;
    if (qAbs(amount - remaining) < epsilon) {
    } else
    if (amount > remaining){
        QMessageBox::warning(this, "Warning", "Số tiền vượt qua số tiền cần thanh toán");
        return;
    }
    Payment::managePayments(id, amount);
    this->close();
}

