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
    string room_ID;       // ID của phòng
    RoomType roomType;    // Loại phòng
    int status;           // Trạng thái phòng (ví dụ: trống, đã thuê)
    string tenant_ID;     // ID của người thuê phòng
public:
    static int total;          // Tổng số phòng
    static int currentNumber;  // Số lượng phòng hiện tại
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
    RoomType getroomtype();

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
    static void searchAll();
    static void updateRoom();
    static void updateFile(const string& filename);
    static void deleteRoom();
    static void showAllRooms();

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const Room& r);
};

#include "Room.cpp"

#endif
