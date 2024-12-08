#ifndef EDITROOM_H
#define EDITROOM_H

#include <QDialog>

using namespace  std;

namespace Ui {
class Editroom;
}

class Editroom : public QDialog
{
    Q_OBJECT

public:
    // void setRI(const string &roomID);
    explicit Editroom(const string& roomID, QWidget *parent = nullptr);
    ~Editroom();

private slots:
    void on_Updateroombtn_clicked();

private:
    Ui::Editroom *ui;
    string room_ID;
};

#endif // EDITROOM_H
