#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "admin.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Signinbtn_clicked();

    void on_SigninBackButton_clicked();

    void on_Loginbtn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
