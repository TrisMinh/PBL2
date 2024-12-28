#include "Createpayment.h"
#include "ui_Createpayment.h"
#include "Room.h"
#include "Payment.h"
#include "ServiceUsage.h"

Createpayment::Createpayment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Createpayment)
{
    ui->setupUi(this);
}

Createpayment::~Createpayment()
{
    delete ui;
}

void Createpayment::displayRooms(const Room& room) {
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem* item0 = new QTableWidgetItem(QString::fromStdString(room.getID()));
    item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(row, 0, item0);

    QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(room.getTenantID()));
    item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(row, 1, item1);
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem("0"));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem("0"));
}



void Createpayment::on_Enterbtn_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    int m = ui->CBSP->currentText().toInt();
    int y = ui->Year->text().toInt();
    Payment::createPayment(m, y, this);
}


void Createpayment::on_Okbtn_clicked()
{
    for (int i=0; i<ui->tableWidget->rowCount(); i++){
        bool c, d;
        int e, w;
        string roomID = ui->tableWidget->item(i, 0)->text().toStdString();
        e = ui->tableWidget->item(i, 2)->text().toInt(&c);
        if (!c){
            QMessageBox::warning(this, "Warning", "Nhập chỉ số điện nước không hợp lệ");
            return;
        }
        w = ui->tableWidget->item(i, 3)->text().toInt(&d);
        if (!d){
            QMessageBox::warning(this, "Warning", "Nhập chỉ số điện nước không hợp lệ");
            return;
        }
        ServiceUsage::enterquantity(roomID, e, w);
    }
    Payment::autocreatePayment(ui->CBSP->currentText().toInt(), ui->Year->text().toInt());
    this->close();
}

