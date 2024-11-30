#include "Edittenant.h"
#include "ui_Edittenant.h"
#include "Tenant.h"
#include <qDebug>

Edittenant::Edittenant(const string& tenantID, const string& name, const string& phone, int age, const string& cccd, const string& gender,  QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Edittenant)
    , tenant_ID(tenantID)
    , name(name)
    , phone(phone)
    , birthyear(Edittenant::getbirthyear(age))
    , cccd(cccd)
    , gender(gender)
{
    ui->setupUi(this);
    ui->newname->setPlaceholderText(QString::fromStdString(name));
    ui->newsdt->setPlaceholderText(QString::fromStdString(phone));
    ui->newage->setPlaceholderText(QString::number(birthyear));
    ui->newcccd->setPlaceholderText(QString::fromStdString(cccd));
    if (gender == "Nam"){
        ui->comboBox->setCurrentIndex(0);
    } else {
        ui->comboBox->setCurrentIndex(1);
    }
}

Edittenant::~Edittenant()
{
    delete ui;
}

int Edittenant::getbirthyear(int age){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    return currentYear - age;
}

void Edittenant::on_Edittenantbtn_clicked()
{
    string firstName;
    string lastName;
    QString newname = ui->newname->text();
    string newsdt = ui->newsdt->text().toStdString();
    string newcccd = ui->newcccd->text().toStdString();
    bool newgender;
    int lastSpaceIndex = newname.lastIndexOf(' ');
    if (lastSpaceIndex != -1) {
        lastName = newname.left(lastSpaceIndex).toStdString();
        firstName = newname.mid(lastSpaceIndex + 1).toStdString();
    }
    if (ui->comboBox->currentText() == "Nam"){
        newgender = 0;
    } else {
        newgender = 1;
    }
    int newage = ui->newage->text().toInt();
    if (ui->newname->text().isEmpty()){
        int lastSpaceIndex = QString::fromStdString(name).lastIndexOf(' ');
        if (lastSpaceIndex != -1) {
            lastName = QString::fromStdString(name).left(lastSpaceIndex).toStdString();
            firstName = QString::fromStdString(name).mid(lastSpaceIndex + 1).toStdString();
    }
    }
    if (ui->newsdt->text().isEmpty()){
        newsdt = phone;
    }
    if (ui->newcccd->text().isEmpty()){
        newcccd = cccd;
    }
    if (ui->newage->text().isEmpty()){
        newage = birthyear;
    }
    Tenant::updateTenant(tenant_ID, lastName, firstName, newsdt, newcccd, newage, newgender);
}

