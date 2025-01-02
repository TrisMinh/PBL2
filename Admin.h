#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"

class Admin : public Account {
public:
    Admin() {}
    void displayAdminMenu();
    void controlAdminMenu();
};
#endif