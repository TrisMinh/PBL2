#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Service {
    string service_ID;
    string name;
    int unit_price;
    string description;
public:
    Service() {}
    Service(const string& id, const string& n, int price, const string& desc)
        : service_ID(id), name(n), unit_price(price), description(desc) {}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, service_ID, ',');
        getline(ss, name, ',');
        ss >> unit_price;
        ss.ignore(1);
        getline(ss, description, ',');
    }
    friend ostream& operator<<(ostream& os, const Service& s) {
        os << "Service [ID: " << s.service_ID << ", Name: " << s.name
           << ", Unit Price: " << s.unit_price << ", Description: " << s.description << "]\n";
        return os;
    }
};

#endif
