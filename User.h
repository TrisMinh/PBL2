#ifndef USER_H
#define USER_H

#include "Account.h"

class User : public Account {
public:
    User() {}
    void displayTenantMenu();
    void controlTenantMenu();
};

#endif 