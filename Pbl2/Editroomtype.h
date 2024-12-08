#ifndef EDITROOMTYPE_H
#define EDITROOMTYPE_H

#include "RoomType.h"

#include <QDialog>

namespace Ui {
class Editroomtype;
}

class Editroomtype : public QDialog
{
    Q_OBJECT

public:
    explicit Editroomtype(const string& id, const string& name, const string& des, double price, QWidget *parent = nullptr);
    ~Editroomtype();

private slots:
    void on_Update_clicked();

private:
    Ui::Editroomtype *ui;
    string type_ID;         // ID của loại phòng
    string name;           // Tên loại phòng
    string description;     // Mô tả loại phòng
    double price;
};

#endif // EDITROOMTYPE_H
