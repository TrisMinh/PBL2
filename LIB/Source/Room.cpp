#include "Room.h"
#include <sstream>
#include <iostream>
using namespace std;
int Room::total_room = 0;
int Room::currentRoomNumber = 0;
Room::Room() {}
Room::Room(const string& typeId, int s, const string& tenantId)
    : type_ID(typeId), status(s), tenant_ID(tenantId) {
    currentRoomNumber++;
    room_ID = generateRoomID(currentRoomNumber);
}
Room::~Room() {}
int Room::get_currentRoomNumber() {
    return currentRoomNumber;
}
string Room::getID() const {
    return room_ID;
}
int Room::getStatus() const {
    return status;
}
void Room::setStatus(int status) {
    this->status = status;
}
string Room::generateRoomID(int number) {
    stringstream ss;
    ss << "R.";
    ss.width(3);
    ss.fill('0');
    ss << number;
    return ss.str();
}
void Room::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, room_ID, ',');
    getline(ss, type_ID, ',');
    ss >> status;
    ss.ignore(1);
    if (ss.peek() != EOF) {
        getline(ss, tenant_ID, ',');
    } else {
        tenant_ID = "";
    }
    currentRoomNumber++;
}
void Room::load(const string& filename) {
    // Implement file loading if needed
}
void Room::addRoom(LinkedList<Room>& roomList) {
    string type_ID, tenant_ID;
    int status;
    cout << "Nhap thong tin phong:" << endl;
    cout << "Type ID: ";
    cin >> type_ID;
    cout << "Status (0: Trong, 1: Dang su dung): ";
    cin >> status;
    cout << "Tenant ID (de trong neu khong co): ";
    cin.ignore();
    getline(cin, tenant_ID);
    Room newRoom(type_ID, status, tenant_ID);
    roomList.add(newRoom);
    cout << "Room Added with ID: " << newRoom.getID() << endl;
}
void Room::searchRoomByID(LinkedList<Room>& roomList) {
    string roomID;
    cout << "Nhap Room ID de tim kiem: ";
    cin >> roomID;
    Room* room = roomList.search(roomID);
    if (room) {
        cout << "Da tim thay: " << *room << endl;
    } else {
        cout << "Khong tim thay phong voi ID: " << roomID << endl;
    }
}
void Room::updateRoom(LinkedList<Room>& roomList) {
    string roomID;
    cout << "Nhap Room ID de cap nhat: ";
    cin >> roomID;
    Room* room = roomList.search(roomID);
    if (room) {
        string newTypeID;
        int newStatus;
        string newTenantID;
        cout << "Cap nhat Room ID: " << room->getID() << endl;
        cout << "Type ID (nhap moi neu muon thay doi): ";
        cin >> newTypeID;
        cout << "Status (0: Trong, 1: Dang su dung): ";
        cin >> newStatus;
        cout << "Tenant ID (nhap moi neu muon thay doi): ";
        cin.ignore();
        getline(cin, newTenantID);
        room->type_ID = newTypeID;
        room->status = newStatus;
        room->tenant_ID = newTenantID;
        cout << "Room updated successfully!" << endl;
    } else {
        cout << "Khong tim thay phong voi ID: " << roomID << endl;
    }
}
void Room::deleteRoom(LinkedList<Room>& roomList) {
    string roomID;
    cout << "Nhap Room ID de xoa: ";
    cin >> roomID;
    roomList.deleteNode(roomID);
    cout << "Room deleted successfully!" << endl;
}
void Room::showRoomDetails(LinkedList<Room>& roomList) {
    string roomID;
    cout << "Nhap Room ID de xem chi tiet: ";
    cin >> roomID;
    Room* room = roomList.search(roomID);
    if (room) {
        cout << "Chi tiet phong: " << *room << endl;
    } else {
        cout << "Khong tim thay phong voi ID: " << roomID << endl;
    }
}
void Room::showAllRooms(LinkedList<Room>& roomList) {
    cout << "Danh sach tat ca cac phong:" << endl;
    roomList.show();
    cout << "1. Increase ID Sort" << endl
         << "2. Decrease ID Sort" << endl
         << "0. Exit! " << endl;
    int choice;
    cout << "Please select an option: " << endl;
    cin >> choice;
    switch (choice) {
        case 1: roomList.sortByID(true); Room::showAllRooms(roomList); break;
        case 2: roomList.sortByID(false); Room::showAllRooms(roomList); break;
        default: break;
    }
}
ostream& operator<<(ostream& os, const Room& r) {
    os << "Room [ID: " << r.room_ID << ", Type ID: " << r.type_ID
       << ", Status: " << r.status << ", Tenant ID: " << (r.tenant_ID.empty() ? "N/A" : r.tenant_ID) << "]\n";
    return os;
}
