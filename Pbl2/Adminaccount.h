#ifndef ADMINACCOUNT_H
#define ADMINACCOUNT_H

#include <QDialog>

namespace Ui {
class Adminaccount;
}

class Adminaccount : public QDialog
{
    Q_OBJECT

public:
    explicit Adminaccount(bool check, QWidget *parent = nullptr);
    ~Adminaccount();

private slots:

    void on_Changepass_clicked();

    void on_Changecode_clicked();

private:
    Ui::Adminaccount *ui;
    bool check;
};

#endif // ADMINACCOUNT_H
