#ifndef ROOM_H
#define ROOM_H

#include "RoomType.h"
#include "Tenant.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>


using namespace std;

class Room {
private:
    string room_ID;       
    RoomType* roomType;   
    int status;          
    string tenant_ID;    
public:
    static int total;          
    static int currentNumber; 
    static LinkedList<Room> roomList; 
    static bool is_header_printed; 

    // Constructors
    Room();
    Room(RoomType* type, int s = 0, const string& tenantId = "N/A");
    // Destructor
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

    // Room management methods
    static string generateID(int number);
    void fromString(const string& line);
    string toString() const;
    double getRoomRate() const;  // Phương thức mới để lấy giá phòng từ RoomType

    // Static methods for Room management
    static void load(const string& filename);
    static void addRoom();
    static void searchByID();
    static void searchByStatus();
    static void searchByName();
    static void searchRoomByTenantID(const string& id);
    static void searchAll();
    static void updateRoom();
    static void updateFile(const string& filename);
    static void deleteRoom();
    static void showAllRooms();
    void resetRoom();

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const Room& r);

    // Static method to reset header
    static void resetHeader();
};

#include "Room.cpp"

#endif
