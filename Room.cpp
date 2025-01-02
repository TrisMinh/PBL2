#include "Room.h"

// Static Element
int Room::total = 0;
int Room::currentNumber = 0;
LinkedList<Room> Room::roomList;
bool Room::is_header_printed = false;
void Room::resetHeader() { is_header_printed = false; }

Room::Room() {}
Room::Room(RoomType* type, int s, const string& tenantId)
    : roomType(type), status(s), tenant_ID(tenantId) {
    room_ID = generateID(++currentNumber);
}
Room::~Room() {}

// ID Generate
string Room::generateID(int number) {
    stringstream ss;
    ss << "R." << setw(3) << setfill('0') << number;
    return ss.str();
}

// IO functions
void Room::load(const string& filename) { roomList.load(filename); }
void Room::updateFile(const string& filename) { roomList.updateFile(filename); }

// Core Getters
string Room::getID() const { return room_ID; }
int Room::getStatus() const { return status; }
double Room::getPrice() const { return roomType ? roomType->getPrice() : 0.0; }
string Room::getTenantID() const { return tenant_ID; }
string Room::getRoomTypeID() const { return roomType ? roomType->getID() : "N/A"; }
RoomType* Room::getRoomType() const { return roomType; }

// Core Setters
void Room::setStatus(int status) { this->status = status; }
void Room::setTenantID(string tenantid) { this->tenant_ID = tenantid; }
void Room::setRoomType(RoomType* type) { roomType = type; }
void Room::resetRoom() {
    status = 0;
    tenant_ID = "N/A";
}

// Convert functions
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

// Basic functions
void Room::addRoom() {
    Room::resetHeader();
    string type_id;
    RoomType* matchedRoomType;
    cout << "Nhap thong tin phong:" << endl;
    do {
        RoomType::roomTypeList.show();
        cout << "Loai phong (Type ID: co dang RT.) (Nhap 0 de thoat): "; cin >> type_id;
        if (type_id == "0") {
            cout << "Thoat them phong." << endl;
            return;
        }
        matchedRoomType = RoomType::roomTypeList.searchID(type_id);
        if (matchedRoomType == nullptr) {
            cout << "Loai phong khong hop le!" << endl;
        }
    } while (matchedRoomType == nullptr);            
    Room newRoom(matchedRoomType);
    roomList.add(newRoom);
    cout << "Da them phong voi ID: " << newRoom.getID() << " voi trang thai mac dinh Trong va khong co khach thue." << endl;
    total++;
}

void Room::updateRoom() {
    Room::resetHeader();
    string roomID;
    cout << "Nhap ma phong (Room ID) de cap nhat: "; cin >> roomID;
    Room* room = roomList.searchID(roomID);
    if (room != NULL) {
        if (room->getStatus() != 0) {
            cout << "Khong the cap nhat trang thai phong vi phong dang co nguoi thue hoac dang bao tri!" << endl;
            return;
        }
        int newStatus;               
        cout << "Cap nhat phong voi ma ID: " << room->getID() << endl;
        cout << "Trang thai moi (0: Trong, 3: Dang bao tri): "; cin >> newStatus;
        if (newStatus != 0 && newStatus != 3) {
            cout << "Trang thai khong hop le! Chi co the cap nhat sang trang thai Trong (0) hoac Dang bao tri (3)" << endl;
            return;
        }

        room->setStatus(newStatus);
        cout << "Phong da duoc cap nhat thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

void Room::deleteRoom() {
    Room::resetHeader();
    string roomID;
    roomList.show();
    cout << "Nhap ma phong (Room ID) de xoa (Nhap 0 de thoat): ";
    cin >> roomID;
    
    if (roomID == "0") return;
    
    Room* room = roomList.searchID(roomID);
    if (room != nullptr) {
        if (room->getStatus() == 1) {
            cout << "Khong the xoa phong dang co nguoi thue!" << endl;
            return;
        }
        roomList.deleteNode(roomID);
        cout << "Phong da duoc xoa thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}
// Search Funcion
void Room::searchByID() {
    resetHeader();
    string roomID;
    cout << "Nhap ma phong (Room ID) de tim kiem: "; cin >> roomID;
    Room* room = roomList.searchID(roomID);
    if (room) { cout << "Da tim thay phong: \n" << *room; }
    else { cout << "Khong tim thay phong voi ma ID: " << roomID << endl; }
}

void Room::searchByStatus() {
    resetHeader();
    int status;
    cout << "Nhap trang thai phong can tim kiem (0: Trong, 1: Co nguoi, 2: Da dat, 3: Dang bao tri): "; cin >> status;
    roomList.searchStatus(status);
    //
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: roomList.sortByID(true); roomList.searchStatus(status); break;
        case 2: roomList.sortByID(false); roomList.searchStatus(status); break;
        default: break;
    }
}


void Room::searchByName() {
    resetHeader();
    string searchName;
    cout << "Nhap ten chu phong can tim kiem: "; 
    cin.ignore();
    getline(cin, searchName);
    
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();
    
    while (current != nullptr) {
        if (current->data.getTenantID() != "N/A") {
            Tenant* tenant = Tenant::tenantList.searchID(current->data.getTenantID());
            if (tenant != nullptr) {
                if (toLower(tenant->getFirstName()).find(toLower(searchName)) != string::npos || toLower(tenant->getLastName()).find(toLower(searchName)) != string::npos || toLower(tenant->getFullName()).find(toLower(searchName)) != string::npos) {
                    cout << current->data;
                    found = true;
                }
            }
        }
        current = current->next;
    }

    if (!found) {
        cout << "Khong tim thay phong voi ten chu phong: " << searchName << endl;
    }
}

void Room::searchRoomByTenantID(const string& id) {
    resetHeader();
    bool found = false;
    LinkedList<Room>::Node* current = roomList.begin();
    while (current != nullptr) {
        if (current->data.getTenantID() == id) {
            cout << current->data;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay phong nao!" << endl;
    }
}


void Room::searchAll() {
    resetHeader();
    int choice;
    do {
        cout << "Chuc nang tim kiem phong:" << endl
             << "   1. Tim kiem theo ma phong" << endl 
             << "   2. Tim kiem theo trang thai phong" << endl
             << "   3. Tim kiem theo ten chu phong" << endl
             << "   0. Thoat" << endl
             << "Vui long nhap lua chon cua ban: "; cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByStatus(); break;
            case 3: searchByName(); break;
            case 0: cout << "Thoat chuc nang tim kiem." << endl; break;
            default: cout << "Lua chon khong hop le. Vui long thu lai." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void Room::showAllRooms() {
    resetHeader();
    cout << "Danh sach tat ca cac phong:" << endl;
    roomList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "3. Tim kiem phong" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: roomList.sortByID(true); showAllRooms(); break;
        case 2: roomList.sortByID(false); showAllRooms(); break;
        case 3: searchAll(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Room& r) {
    const int w_room = 15, w_type = 15, w_stat = 15, w_tid = 20, w_name = 25, w_price = 10;

    if (!Room::is_header_printed) {
        os << left
           << setw(w_room) << "Ma phong" << " | "
           << setw(w_type) << "Loai phong" << " | "
           << setw(w_stat) << "Trang thai" << " | "
           << setw(w_tid) << "Ma khach thue" << " | "
           << setw(w_name) << "Ten khach thue" << " | "
           << setw(w_price) << "Gia" 
           << endl;

        os << setfill('-') << setw(w_room + w_type + w_stat + w_tid + w_name + w_price + 13) << "" << setfill(' ') << setfill(' ') << endl;

        Room::is_header_printed = true;
    }

    string tenantName = "N/A";
    if (r.tenant_ID != "N/A") {
        Tenant* tenant = Tenant::tenantList.searchID(r.tenant_ID);
        if (tenant != nullptr) {
            tenantName = tenant->getFullName();
        }
    }

    os << left 
       << setw(w_room) << r.room_ID << " | "
       << setw(w_type) << r.getRoomTypeID() << " | "
       << setw(w_stat) << (r.status == 0 ? "Trong" : 
                                (r.status == 1 ? "Dang thue" : 
                                (r.status == 3 ? "Dang bao tri" : "Da dat"))) << " | "
       << setw(w_tid) << (r.tenant_ID.empty() ? "N/A" : r.tenant_ID) << " | "
       << setw(w_name) << tenantName << " | "
       << fixed << setprecision(2) << setw(w_price) << r.getPrice() << endl;

    return os;
}

