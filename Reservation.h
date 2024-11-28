#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include "Room.h"
#include "Account.h"
#include "ServiceUsage.h"

class Reservation {
protected:
    string reservation_ID;
    string room_ID;
    string tenant_ID;
    DATE startDate;
    DATE endDate;
    int staytime;
    int status;
public:
    static int total;
    static int currentNumber;
    static LinkedList<Reservation> reservationList;
    static bool is_header_printed;
    static void resetHeader();

    // Constructors
    Reservation();
    Reservation(const string& roomId, const string& tenantId, DATE& start, int monthStay, int stat = 0);

    // Destructor
    ~Reservation();

    // Method to generate a reservation ID
    static string generateID(int number);

    // Getter methods
    int getPrice() const;
    string getID() const;
    string getRoomID() const;
    string getTenantID() const;
    DATE getStartDate() const;
    DATE getEndDate() const;
    int getStatus() const;

    // Setter methods
    void setRoomID(const string& id);
    void setTenantID(const string& id);
    void setStartDay(const string& day);
    void setStatus(int stat);
    void setStaytime(int staytime);

    // Convert reservation to and from string
    void fromString(const string& line);
    string toString() const;

    // Load reservations from file
    static void load(const string& filename);
    static void updateFile(const string& filename);

    // Friend function to output reservation
    friend ostream& operator<<(ostream& os, const Reservation& r);

    // Static functions for reservation management
    static void addReservation();
    static void updateReservation();
    static void deleteReservation();
    static void showAllReservations();

    // Search and confirm reservation
    static void searchByID();
    static void searchByStatus();
    static void searchAll();

    static void checkNewReservations();
};

#include "Reservation.cpp"

#endif
