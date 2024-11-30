#ifndef EDITTENANT_H
#define EDITTENANT_H

#include <QDialog>

using namespace std;

namespace Ui {
class Edittenant;
}

class Edittenant : public QDialog
{
    Q_OBJECT

public:
    static int getbirthyear(int age);
    explicit Edittenant(const string& tenantID, const string& name, const string& phone, int age, const string& cccd, const string& gender, QWidget *parent = nullptr);
    ~Edittenant();

private slots:

    void on_Edittenantbtn_clicked();

private:
    Ui::Edittenant *ui;
    string tenant_ID;
    string name;
    string phone;
    int birthyear;
    string cccd;
    string gender;
};

#endif // EDITTENANT_H
