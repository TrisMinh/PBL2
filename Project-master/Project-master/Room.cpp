#include "Room.h"
#include "LinkedList.h"
#include "Tenant.h"
#include <iostream>
#include <ostream>
// #include <admin.h>

using namespace std;

LinkedList<Room> Room::roomList;
int Room::total = 0;
int Room::currentNumber = 0;
Room::Room() {}
Room::Room(RoomType* type, int s, const string& tenantId)
    : roomType(type), status(s), tenant_ID(tenantId) {
    room_ID = generateID(++currentNumber);
}
Room::~Room() {}

// string Room::generateID(int number) {
//     string str;
//     QTextStream ss(&str);
//     ss << "R." << string("%1").arg(number, 3, 10, QChar('0'));
//     return str;
// }

string Room::generateID(int number) {
    stringstream ss;
    ss << "R." << setw(3) << setfill('0') << number;
    return (ss.str());
}

void Room::updateFile(const string& filename) { roomList.updateFile(filename); }
void Room::load(){
    roomList.load("Room.txt");
}

string Room::getID() const { return room_ID; }
int Room::getStatus() const { return status; }
double Room::getPrice() const { return roomType ? roomType->getPrice() : 0.0; }
string Room::getTenantID() const { return tenant_ID; }
string Room::getRoomTypeID() const { return roomType ? roomType->getID() : "N/A"; }
RoomType* Room::getRoomType() const { return roomType; }

void Room::setStatus(int status) { this->status = status; }
void Room::setRT(RoomType* type){ roomType = type; }
void Room::setTenantID(string tenantid) { this->tenant_ID = tenantid; }
// void Room::fromString(const string& line) {
//     stringList fields = line.split(',');
//     room_ID = fields[0];
//     string type_id = fields[1];
//     status = fields[2].trimmed().toInt();
//     tenant_ID = fields[3].trimmed();
//     roomType = RoomType::roomTypeList.searchID(type_id)? *(RoomType::roomTypeList.searchID(type_id)): RoomType();
//     total++;
// }

void Room::fromString(const string& line) {
    stringstream ss(line);
    string type_id;
    getline(ss, room_ID, ',');
    getline(ss, type_id, ',');
    ss >> status;
    ss.ignore(1);
    getline(ss, tenant_ID);
    roomType = RoomType::roomTypeList.searchID(type_id);
    total++;
}

string Room::toString() const {
    return room_ID + "," + getRoomTypeID() + "," + to_string(status) + "," + (tenant_ID.empty() ? "N/A" : tenant_ID);
}

void Room::addRoom(const string& rt_id) {
    RoomType* matchedRoomType;
    matchedRoomType = RoomType::roomTypeList.searchID(rt_id);
    Room newRoom(matchedRoomType);
    roomList.add(newRoom);
    Room::updateFile("Room.txt");
    total++;
}
void Room::showAllRooms(Admin* adminWindow) {
    roomList.show(adminWindow);
}

void Room::display(Admin* adminWindow) const {
    adminWindow->displayRooms(*this);  // Gọi hàm displayRoom của Admin với Room hiện tại
}

void Room::displayuser(Createpayment* adminWindow) const {
    adminWindow->displayRooms(*this);  // Gọi hàm displayRoom của Admin với Room hiện tại
}

void Room::updateRoom(const string& rid, int sta, const string& rt){
    Room* room = roomList.searchID(rid);
    room->setStatus(sta);
    RoomType* find = roomTypeList.searchID(rt);
    room->setRT(find);
    Room::updateFile("Room.txt");
}

void Room::deleteRoom(const string& rid) {
    roomList.deleteNode(rid);
    total--;
    Room::updateFile("Room.txt");
}

void Room::searchByID(const string& id, Admin* adminWindow) {
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void Room::searchByID(const string& id, Createpayment* adminWindow) {
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.displayuser(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}
// void Room::searchByID(const string& id, Admin* adminWindow) {
//     Room* room = roomList.searchID(id);
//     if (room)
//         adminWindow->displayRoom(*room);
//     else return;
// }

void Room::searchByStatus(int st, Admin* adminWindow){
    roomList.searchStatus(st, adminWindow);
}

// void Room::searchByRoomType(const string& RT, Admin* adminWindow){
//     roomList.searchRoomType(RT, adminWindow);
// }
void Room::searchByRoomType(const string& RT, Admin* adminWindow){
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();
    while (current != nullptr) {
        string ID = current->data.getRoomTypeID();
        if ( ID.find(RT) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        return;
    }
}

void Room::searchByName(const string& name, Admin* adminWindow) {
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();

    while (current != nullptr) {
        if (current->data.getTenantID() != "N/A") {
            Tenant* tenant = Tenant::tenantList.searchID(current->data.getTenantID());
            if (tenant != nullptr) {
                if (tenant->getFirstName().find(name) != string::npos || tenant->getLastName().find(name) != string::npos || tenant->getFullName().find(name) != string::npos) {
                    current->data.display(adminWindow);
                    found = true;
                }
            }
        }
        current = current->next;
    }

    if (!found) {
        return;
    }
}

void Room::Ascending(){
    roomList.sortByID(true);
}

void Room::Descending(){
    roomList.sortByID(false);
}
