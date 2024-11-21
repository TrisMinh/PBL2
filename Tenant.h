#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

class Tenant {
    string tenant_ID;
    string name;
    string phone;
    int birthyear;
    string cccd;
    bool gender;

public:
    static int total;
    static int currentNumber;  
    static LinkedList<Tenant> tenantList;
    Tenant();
    Tenant(const string& name, const string& phone, const string& cccd, int birthyear, bool gender);
    ~Tenant();
    static int get_currentNumber();
    static string generateID(int number);
    string getID() const;
    string getName() const;
    string getPhone() const;
    int getBirthyear() const;
    int getAge() const;
    string getCCCD() const;
    bool getGender() const;
    

    void setName(const string& name);
    void setPhone(const string& phone);
    void setBirthyear(int birthyear);
    void setCCCD(const string& cccd);
    void setGender(bool gender);

    void fromString(const string& line);
    string toString() const;

    static void load(const string& filename);
    static void updateFile(const string& filename);
    static void addTenant();
    static void searchByID();
    static void searchByName();
    static void searchAll();
    static void updateTenant();
    static void deleteTenant();
    static void showTenantDetails();
    static void showAllTenants();

    friend ostream& operator<<(ostream& os, const Tenant& t);
};

#include "Tenant.cpp"

#endif