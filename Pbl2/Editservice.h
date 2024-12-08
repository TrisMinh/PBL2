#ifndef EDITSERVICE_H
#define EDITSERVICE_H

#include <QDialog>

using namespace std;

namespace Ui {
class Editservice;
}

class Editservice : public QDialog
{
    Q_OBJECT

public:
    explicit Editservice(const string& service_ID, const string& name, int price, const string& des, QWidget *parent = nullptr);
    ~Editservice();

private slots:
    void on_UpdateSerbtn_clicked();

private:
    Ui::Editservice *ui;
    string service_ID;
    string name;
    int unit_price;
    string description;
};

#endif // EDITSERVICE_H
