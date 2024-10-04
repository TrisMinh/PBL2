#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ServiceUsage {
    string usage_ID;
    string reservation_ID;
    string service_ID;
    int quantity;
    int usage_month;
public:
    ServiceUsage() {}
    ServiceUsage(const string& id, const string& resId, const string& servId, int qty, int month)
        : usage_ID(id), reservation_ID(resId), service_ID(servId), quantity(qty), usage_month(month) {}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, usage_ID, ',');
        getline(ss, reservation_ID, ',');
        getline(ss, service_ID, ',');
        ss >> quantity;
        ss.ignore(1);
        ss >> usage_month;
    }
    friend ostream& operator<<(ostream& os, const ServiceUsage& su) {
        os << "ServiceUsage [ID: " << su.usage_ID << ", Reservation ID: " << su.reservation_ID
           << ", Service ID: " << su.service_ID << ", Quantity: " << su.quantity
           << ", Usage Month: " << su.usage_month << "]\n";
        return os;
    }
};

#endif
