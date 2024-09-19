#ifndef ROOMLIST_H
#define ROOMLIST_H

#include "LIB/LIST.h"
#include "LIB/ROOM.h"
#include <fstream>
#include <sstream>

class RoomList : public LinkedList<Room> {
public:
    void addRoom(const Room& room) {
        add(room);
    }

    void displayAllRooms() const {
        show();
    }

    void inputRoom() {
        string roomID, managerID, tenantID, roomDescription;
        int roomType, status;

        cout << "Enter Room ID: ";
        cin >> roomID;
        cout << "Enter Manager ID: ";
        cin >> managerID;
        cout << "Enter Description: ";
        cin >> roomDescription;
        cout << "Enter Status (0 for available, 1 for occupied): ";
        cin >> status;
        cout << "Enter Tenant ID: ";
        cin >> tenantID;
        cout << "Enter Room Type: ";
        cin >> roomType;

        // Add the room to the list
        addRoom(Room(roomID, managerID, roomType, status, tenantID, roomDescription));
    }

void inputfromfile(RoomList& roomList, const string filename) {
    ifstream file(filename); // mo file co ten filename
    if (!file.is_open()) {
        cout << "Erro, could not open file !" << filename << endl;
        return;
    } 

    string line;
    getline(file,line);
    while(getline(file, line)) {
        stringstream ss(line);
        string roomID, managerID, tenantID, roomDescription;
        int roomType, status;

        getline(ss, roomID, ',');
        getline(ss, managerID, ',');
        getline(ss, tenantID, ',');
        ss >> roomType; ss.ignore(1); // bo qua dau phay
        ss >> status; ss.ignore(1);
        getline(ss, roomDescription, ',');

        roomList.addRoom(Room(roomID, managerID, roomType, status, tenantID, roomDescription));
    }

    file.close(); //xong thi dong file
}


};

#endif // ROOMLIST_H
