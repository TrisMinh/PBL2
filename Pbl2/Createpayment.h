#ifndef CREATEPAYMENT_H
#define CREATEPAYMENT_H

#include <QDialog>

class Room;

namespace Ui {
class Createpayment;
}

class Createpayment : public QDialog
{
    Q_OBJECT

public:
    void show(int billMonth, int billYear);
    void displayRooms(const Room& room);
    explicit Createpayment(QWidget *parent = nullptr);
    ~Createpayment();

private slots:
    void on_Enterbtn_clicked();

    void on_Okbtn_clicked();

private:
    Ui::Createpayment *ui;
};

#endif // CREATEPAYMENT_H
