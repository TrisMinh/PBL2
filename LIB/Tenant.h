#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Tenant {
    string tenant_ID;
    string CCCD;
    string name;
    string phone;
    int age;
public:
    Tenant() {}
    Tenant(const string& id, const string& cccd, const string& n, const string& ph, int a)
        : tenant_ID(id), CCCD(cccd), name(n), phone(ph), age(a) {}

    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, tenant_ID, ',');
        getline(ss, CCCD, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        ss >> age;
    }
    friend ostream& operator<<(ostream& os, const Tenant& t) {
        os << "Tenant [ID: " << t.tenant_ID << ", CCCD: " << t.CCCD
           << ", Name: " << t.name << ", Phone: " << t.phone << ", Age: " << t.age << "]\n";
        return os;
    }
};

#endif
