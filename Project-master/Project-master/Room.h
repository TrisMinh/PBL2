#ifndef ROOM_H
#define ROOM_H
#include "LinkedList.h"
#include <QFile>
#include <sstream>
#include "RoomType.h"
#include "admin.h"

class Admin;

class Room: public RoomType
{
protected:
    RoomType* roomType;
    string room_ID;
    int status;
    string tenant_ID;
public:
    friend class Admin;
    Room();
    Room(RoomType* type, int s = 0, const string& tenantId = "N/A");
    ~Room();

    void setStatus(int status);
    void setRT(RoomType* type);
    void setTenantID(string tenantid);

    string getID() const;
    RoomType* getRoomType() const;
    string getRoomTypeID() const;
    int getStatus() const;
    double getPrice() const;
    string getTenantID() const;

    void display(Admin* adminWindow) const;
    void displayuser(Createpayment* adminWindow) const;
    void fromString(const string& line);
    string toString() const;
    static int total;
    static int currentNumber;
    static LinkedList<Room> roomList;
    static string generateID(int number);

    static void updateRoom(const string& rid, int sta, const string& rt);
    static void updateFile(const string& filename);
    static void searchByID(const string& id, Admin* adminWindow);
    static void searchByID(const string& id, Createpayment* adminWindow);
    static void searchByStatus(int st, Admin* adminWindow);
    static void searchByRoomType(const string& RT, Admin* adminWindow);
    static void searchByName(const string& name, Admin* adminWindow);
    static void load();
    static void deleteRoom(const string& rid);
    static void addRoom(const string& rt_id);
    static void showAllRooms(Admin* adminWindow);
    static void Ascending();
    static void Descending();
    friend ostream& operator<<(ostream& os, const Room& r);
};

#endif // ROOM_H
