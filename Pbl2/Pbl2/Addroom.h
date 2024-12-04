#ifndef ADDROOM_H
#define ADDROOM_H

#include <QDialog>

namespace Ui {
class Addroom;
}

class Addroom : public QDialog
{
    Q_OBJECT

public:
    void addroom();
    explicit Addroom(QWidget *parent = nullptr);
    ~Addroom();

private slots:
    void on_Addroombtn_clicked();

private:
    Ui::Addroom *ui;
};

#endif // ADDROOM_H
