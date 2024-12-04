#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>

namespace Ui {
class Signin;
}

class Signin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signin(QWidget *parent = nullptr);
    ~Signin();
private slots:
    void on_Loginbtn_clicked();
    void on_Signupbtn_clicked();

    void on_backbtn_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_DKadminbtn_clicked();

    void on_tieptucbtn_clicked();
    void on_Dktenantbtn_clicked();

    void on_tieptucpr_clicked();

    void on_pushButton_clicked();

private:
    Ui::Signin *ui;
};

#endif // SIGNIN_H
