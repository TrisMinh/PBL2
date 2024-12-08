#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>

namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(const std::string& id, QWidget *parent = nullptr);
    ~Booking();

private slots:
    void on_Datbtn_clicked();

private:
    std::string id;
    Ui::Booking *ui;
};

#endif // BOOKING_H
