#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

class Account; // Forward declaration

class Tenant {
    string tenant_ID;
    string lastName;
    string firstName;
    string phone;
    int birthyear;
    string cccd;
    bool gender;

public:
    static int total;
    static int currentNumber;  
    static LinkedList<Tenant> tenantList;
    static bool is_header_printed; 
    static void resetHeader();


    Tenant();
    Tenant(const string& lastName, const string& firstName, const string& phone, const string& cccd, int birthyear, bool gender);
    ~Tenant();
    static int get_currentNumber();
    static string generateID(int number);
    string getID() const;
    string getLastName() const;
    string getFirstName() const;
    string getFullName() const;
    string getPhone() const;
    int getBirthyear() const;
    int getAge() const;
    string getCCCD() const;
    bool getGender() const;
    

    void setLastName(const string& lastName);
    void setFirstName(const string& firstName);
    void setPhone(const string& phone);
    void setBirthyear(int birthyear);
    void setCCCD(const string& cccd);
    void setGender(bool gender);

    void fromString(const string& line);
    string toString() const;

    static void load(const string& filename);
    static void updateFile(const string& filename);

    static void addTenant();
    static void updateTenant();
    static void deleteTenant();
    static void showAllTenants();

    static void searchByID();
    static void searchByName();
    static void searchAll();

    friend ostream& operator<<(ostream& os, const Tenant& t);
};

#include "Tenant.cpp"

#endif