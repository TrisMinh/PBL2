#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Reservation {
    string reservation_ID;
    string room_ID;
    string tenant_ID;
    string start_day;
    int rent_price;
    int deposit_amount;
    int status;
public:
    Reservation() {}
    Reservation(const string& id, const string& roomId, const string& tenantId, const string& day, int price, int deposit, int stat = 0)
        : reservation_ID(id), room_ID(roomId), tenant_ID(tenantId), start_day(day), rent_price(price), deposit_amount(deposit), status(stat) {}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, reservation_ID, ',');
        getline(ss, room_ID, ',');
        getline(ss, tenant_ID, ',');
        getline(ss, start_day, ',');
        ss >> rent_price;
        ss.ignore(1);
        ss >> deposit_amount;
        ss.ignore(1);
        ss >> status;
    }
    friend ostream& operator<<(ostream& os, const Reservation& r) {
        os << "Reservation [ID: " << r.reservation_ID << ", Room ID: " << r.room_ID
           << ", Tenant ID: " << r.tenant_ID << ", Start Day: " << r.start_day
           << ", Rent Price: " << r.rent_price << ", Deposit Amount: " << r.deposit_amount
           << ", Status: " << r.status << "]\n";
        return os;
    }
    friend void createReservation(LinkedList<Room>& roomList, LinkedList<Reservation>& reservationList, const string& tenantID);
}; 

#endif
