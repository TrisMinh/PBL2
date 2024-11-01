#include "Room.h"
#include "RoomType.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static members
int Room::total = 0;
int Room::currentNumber = 0;
LinkedList<Room> Room::roomList;

// Default constructor
Room::Room() : roomType("", 0.0), status(0), tenant_ID("") {}

// Parameterized constructor
Room::Room(const RoomType& type, int s, const string& tenantId)
    : roomType(type), status(s), tenant_ID(tenantId) {
    total++;
    room_ID = generateID(++currentNumber);
}

// Destructor
Room::~Room() {}

// Getters
RoomType Room::getroomtype() {return roomType;}
string Room::getID() const { return room_ID; }
int Room::getStatus() const { return status; }
string Room::getTenantID() const { return tenant_ID; }

// Setters
void Room::setStatus(int status) { this->status = status; }
void Room::setTenantID(string tenantid) { this->tenant_ID = tenantid; }

// Helper function to generate room ID
string Room::generateID(int number) {
    stringstream ss;
    ss << "R." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Deserializing a Room object from a string
void Room::fromString(const string& line) {
    stringstream ss(line);
    string type_id;
    getline(ss, room_ID, ',');
    getline(ss, type_id, ',');
    ss >> status;
    ss.ignore(1);
    getline(ss, tenant_ID);

    roomType = *RoomType::roomTypeList.searchID(type_id);
    total++;
}

// Convert Room object to string
string Room::toString() const {
    return room_ID + "," + roomType.getID() + "," + to_string(status) + "," + (tenant_ID.empty() ? "N/A" : tenant_ID);
}

// Load room data from a file
void Room::load(const string& filename) {
    roomList.load(filename);
}

// Adding a room
void Room::addRoom() {
    string type_id;
    cout << "Nhap thong tin phong:" << endl;
    cout << "Loai phong (Type ID): ";
    cin >> type_id;

    RoomType* matchedRoomType = RoomType::roomTypeList.searchID(type_id);
    if (matchedRoomType == nullptr) {
        cout << "Loai phong khong hop le!" << endl;
        return;
    }

    int status = 0;            // Mặc định phòng trống
    string tenant_id = "N/A";   // Mặc định chưa có khách thuê

    Room newRoom(*matchedRoomType, status, tenant_id);
    roomList.add(newRoom);
    cout << "Da them phong voi ID: " << newRoom.getID() << " voi trang thai mac dinh Trong va khong co khach thue." << endl;
}

// Search by room ID
void Room::searchByID() {
    string roomID;
    cout << "Nhap ma phong (Room ID) de tim kiem: ";
    cin >> roomID;

    Room* room = roomList.searchID(roomID);
    if (room) {
        cout << "Da tim thay phong: " << *room;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

// Search by room status
void Room::searchByStatus() {
    int status;
    cout << "Nhap trang thai phong can tim kiem (0: Trong, 1: Co nguoi): ";
    cin >> status;
    roomList.searchStatus(status); // Assume LinkedList supports this method
}

// Display all rooms
void Room::searchAll() {
    roomList.show(); // Assume LinkedList supports show method
}

// Update a room's details
void Room::updateRoom() {
    string roomID;
    cout << "Nhap ma phong (Room ID) de cap nhat: ";
    cin >> roomID;

    Room* room = roomList.searchID(roomID);
    if (room) {
        string newTenantID;
        int newStatus;
        
        cout << "Cap nhat phong voi ma ID: " << room->getID() << endl;
        cout << "Trang thai moi (0: Trong, 1: Dang su dung): ";
        cin >> newStatus;
        cout << "Ma khach thue moi (Tenant ID): ";
        cin.ignore();
        getline(cin, newTenantID);

        room->setStatus(newStatus);
        room->tenant_ID = newTenantID;
        cout << "Phong da duoc cap nhat thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

// Delete a room
void Room::deleteRoom() {
    string roomID;
    cout << "Nhap ma phong (Room ID) de xoa: ";
    cin >> roomID;

    roomList.deleteNode(roomID);
    Room* room = roomList.searchID(roomID);
    if (room == nullptr) {
        cout << "Phong da duoc xoa thanh cong!" << endl;
        total--;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

// Show and sort all rooms
void Room::showAllRooms() {
    cout << "Danh sach tat ca cac phong:" << endl;
    roomList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;

    int choice;
    cout << "Lua chon cua ban: ";
    cin >> choice;
    switch (choice) {
        case 1:
            roomList.sortByID(true); 
            showAllRooms();
            break;
        case 2:
            roomList.sortByID(false); 
            showAllRooms();
            break;
        default:
            break;
    }
}

// Overloaded output operator
ostream& operator<<(ostream& os, const Room& r) {
    os << left
       << setw(15) << ("Ma phong: " + r.room_ID) << " | "
       << setw(15) << ("Loai phong: " + r.roomType.getID()) << " | "
       << setw(10) << ("Trang thai: " + to_string(r.status)) << " | "
       << setw(20) << ("Ma khach thue: " + (r.tenant_ID.empty() ? "N/A" : r.tenant_ID)) << " | "
       << "Gia: " << fixed << setprecision(2) << setw(10) << r.roomType.getPrice() << "\n";
    return os;
}

void Room::updateFile(const string& filename) {
    roomList.updateFile(filename);
}
