#ifndef PAYBILL_H
#define PAYBILL_H

#include <QDialog>

namespace Ui {
class Paybill;
}

class Paybill : public QDialog
{
    Q_OBJECT

public:
    explicit Paybill(const std::string& id, QWidget *parent = nullptr);
    ~Paybill();

private slots:
    void on_Datbtn_clicked();

private:
    double remaining;
    std::string id;
    Ui::Paybill *ui;
};

#endif // PAYBILL_H
