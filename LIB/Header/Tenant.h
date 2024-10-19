#ifndef TENANT_H
#define TENANT_H
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;
class Tenant {
    string tenant_ID;
    string CCCD;
    string name;
    string phone;
    int age;
public:
    Tenant();
    Tenant(const string& id, const string& cccd, const string& n, const string& ph, int a);
    string getID() const;
    string getname() const;
    void fromString(const string& line);
    friend ostream& operator<<(ostream& os, const Tenant& t);
    static void addTenant(LinkedList<Tenant>& tenantList);
    static void updateTenant(LinkedList<Tenant>& tenantList);
    static void deleteTenant(LinkedList<Tenant>& tenantList);
    static void showTenantDetails(LinkedList<Tenant>& tenantList);
    static void showAllTenants(LinkedList<Tenant>& tenantList);
};
#endif // TENANT_H
