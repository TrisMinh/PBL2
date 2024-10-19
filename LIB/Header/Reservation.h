#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Room.h"
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
    Reservation();
    Reservation(const string& id, const string& roomId, const string& tenantId, const string& day, int price, int deposit, int stat = 0);
    ~Reservation();
    string getID();
    void fromString(const string& line);
    friend ostream& operator<<(ostream& os, const Reservation& r);
    static void addReservation(LinkedList<Room>& roomList, LinkedList<Reservation>& reservationList);
    static void searchReservationByID(LinkedList<Reservation>& reservationList);
    static void updateReservation(LinkedList<Reservation>& reservationList);
    static void deleteReservation(LinkedList<Reservation>& reservationList);
    static void showAllReservations(LinkedList<Reservation>& reservationList);
    string getRoomID() const;
    void setStatus(int s);
};
#endif
