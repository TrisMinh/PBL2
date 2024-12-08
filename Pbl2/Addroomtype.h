#ifndef ADDROOMTYPE_H
#define ADDROOMTYPE_H

#include <QDialog>

namespace Ui {
class Addroomtype;
}

class Addroomtype : public QDialog
{
    Q_OBJECT

public:
    explicit Addroomtype(QWidget *parent = nullptr);
    ~Addroomtype();

private slots:
    void on_AddRTbtn_clicked();

private:
    Ui::Addroomtype *ui;
};

#endif // ADDROOMTYPE_H
