#ifndef ROOM_H
#define ROOM_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "RoomType.h"
#include "Tenant.h"
#include "LinkedList.h"

using namespace std;

class Room {
private:
    string room_ID;       
    RoomType* roomType;   
    int status;          
    string tenant_ID;    

    static string generateID(int number);
    double getRoomRate() const;

public:
    // Static members
    static int total;          
    static int currentNumber; 
    static LinkedList<Room> roomList; 
    static bool is_header_printed; 

    Room();
    Room(RoomType* type, int s = 0, const string& tenantId = "N/A");
    ~Room();

    // Getters
    string getID() const;
    RoomType* getRoomType() const;
    string getRoomTypeID() const;
    int getStatus() const;
    double getPrice() const;
    string getTenantID() const;

    // Setters
    void setStatus(int status);
    void setTenantID(string tenantid);
    void setRoomType(RoomType* type);

    // Convert functions
    void fromString(const string& line);
    string toString() const;
    void resetRoom();

    // IO functions
    static void load(const string& filename);
    static void updateFile(const string& filename);

    // Title control
    static void resetHeader();
    
    // Basic functions
    static void addRoom();
    static void deleteRoom();
    static void updateRoom();
    
    // Search Operations
    static void searchByID();
    static void searchByStatus();
    static void searchByName();
    static void searchRoomByTenantID(const string& id);
    static void searchAll();
    static void showAllRooms();

    friend ostream& operator<<(ostream& os, const Room& r);
};

#include "Room.cpp"

#endif
