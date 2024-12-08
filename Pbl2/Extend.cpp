#include "Extend.h"
#include "ui_Extend.h"
#include "Contract.h"
#include <QMessageBox>

Extend::Extend(const std::string id, QWidget *parent)
    : QDialog(parent)
    , id(id), ui(new Ui::Extend)
{
    ui->setupUi(this);
}

Extend::~Extend()
{
    delete ui;
}

void Extend::on_Extenbtn_clicked()
{
    bool c;
    int staymont = ui->newRT->text().toInt(&c);
    if (!c){
        QMessageBox::information(this, "Error", "Nhập số tháng không hợp lệ");
        return;
    }
    Contract::extensionContract(staymont, id);
    this->close();
}

