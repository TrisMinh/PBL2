#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Payment {
    string payment_ID;
    string reservation_ID;
    int payment_month;
    string payment_day;
    int rent_amount;
    int service_amount;
    int total_amount;
    int status;
public:
    Payment() {}
    Payment(const string& id, const string& resId, int month, const string& day, int rentAmt, int servAmt, int totalAmt, int stat)
        : payment_ID(id), reservation_ID(resId), payment_month(month), payment_day(day), 
          rent_amount(rentAmt), service_amount(servAmt), total_amount(totalAmt), status(stat) {}
    ~Payment() {}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, payment_ID, ',');
        getline(ss, reservation_ID, ',');
        ss >> payment_month;
        ss.ignore(1);  // Bỏ qua dấu phẩy
        getline(ss, payment_day, ',');
        ss >> rent_amount;
        ss.ignore(1);  // Bỏ qua dấu phẩy
        ss >> service_amount;
        ss.ignore(1);  // Bỏ qua dấu phẩy
        ss >> total_amount;
        ss.ignore(1);  // Bỏ qua dấu phẩy
        ss >> status;
    }

    friend ostream& operator<<(ostream& os, const Payment& p) {
        os << "Payment [ID: " << p.payment_ID << ", Reservation ID: " << p.reservation_ID
           << ", Payment Month: " << p.payment_month << ", Payment Day: " << p.payment_day
           << ", Rent Amount: " << p.rent_amount << ", Service Amount: " << p.service_amount
           << ", Total Amount: " << p.total_amount << ", Status: " << p.status << "]\n";
        return os;
    }
};

#endif
