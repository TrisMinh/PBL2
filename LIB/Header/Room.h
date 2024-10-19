#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
class Room {
    string room_ID;
    string type_ID;
    int status;
    static int total_room;
    static int currentRoomNumber;
    string tenant_ID;
public:
    Room();
    Room(const string& typeId, int s, const string& tenantId = "");
    ~Room();
    static int get_currentRoomNumber();
    string getID() const;
    int getStatus() const;
    void setStatus(int status);
    static string generateRoomID(int number);
    void fromString(const string& line);
    static void load(const string& filename);
    static void addRoom(LinkedList<Room>& roomList);
    static void searchRoomByID(LinkedList<Room>& roomList);
    static void updateRoom(LinkedList<Room>& roomList);
    static void deleteRoom(LinkedList<Room>& roomList);
    static void showRoomDetails(LinkedList<Room>& roomList);
    static void showAllRooms(LinkedList<Room>& roomList);
    friend ostream& operator<<(ostream& os, const Room& r);
};
#endif
