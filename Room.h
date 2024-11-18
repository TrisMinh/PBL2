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

class Room : public RoomType {
protected:
    string room_ID;       
    RoomType roomType;   
    int status;          
    string tenant_ID;    
public:
    static int total;          
    static int currentNumber; 
    static LinkedList<Room> roomList; 

    // Constructors
    Room();
    Room(const RoomType& type, int s, const string& tenantId = "");
    // Destructor
    ~Room();

    // Getters
    double getPrice() const;
    string getID() const;
    int getStatus() const;
    string getTenantID() const;
    RoomType getroomtype() const;

    // Setters
    void setStatus(int status);
    void setTenantID(string tenantid);

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
};

#include "Room.cpp"

#endif
