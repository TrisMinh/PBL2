#ifndef TENANT_H
#define TENANT_H

#include <string>
#include <sstream>
#include "LinkedList.h"
#include "admin.h"

class Tenant
{
    string tenant_ID;
    string lastName;
    string firstName;
    string phone;
    int birthyear;
    string cccd;
    bool gender;
public:
    friend class Admin;
    static int total;
    static int currentNumber;
    static LinkedList<Tenant> tenantList;
    Tenant();
    Tenant(const string& lastName, const string& firstName, const string& phone, const string& cccd, int birthyear, bool gender);
    ~Tenant();
    static string generateID(int number);
    string getID() const;
    string getLastName() const;
    string getFirstName() const;
    string getFullName() const;
    string getPhone() const;
    int getAge() const;
    string getCCCD() const;
    bool getGender() const;

    void fromString(const string& line);
    string toString() const;

    void setLastName(const string& lastName);
    void setFirstName(const string& firstName);
    void setPhone(const string& phone);
    void setBirthyear(int birthyear);
    void setCCCD(const string& cccd);
    void setGender(bool gender);

    void display(Admin* adminWindow) const;

    static void sortID(bool sx);
    static void sortName(bool sx);
    static void showAllTenants(Admin* adminWindow);
    static void searchByGender(int gender, Admin* adminWindow);
    static void searchByID(const string& id, Admin* adminWindow);
    static void searchByName(const string& name, Admin* adminWindow);
    static void load(const string& filename);
    static void updateFile(const string& filename);
    static void updateTenant(const string& tenantId, const string& lastname, const string& firstname, const string& phone, const string& cccd, int age, bool genderInput);
};

#endif // TENANT_H
