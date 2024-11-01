#include "Room.h"

// Static Element
int Room::total = 0;
int Room::currentNumber = 0;
LinkedList<Room> Room::roomList;

// Constructor
Room::Room() {}
Room::Room(const RoomType& type, int s, const string& tenantId)
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

// Load function
void Room::load(const string& filename) { roomList.load(filename); }
void Room::updateFile(const string& filename) { roomList.updateFile(filename); }


// Get function
RoomType Room::getroomtype() {return roomType;}
string Room::getID() const { return room_ID; }
int Room::getStatus() const { return status; }
double Room::getPrice() const { return roomType.getPrice();}
string Room::getTenantID() const { return tenant_ID; }

// Set function
void Room::setStatus(int status) { this->status = status; }
void Room::setTenantID(string tenantid) { this->tenant_ID = tenantid; }


// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
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

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Room::toString() const { 
    return room_ID + "," + roomType.getID() + "," + to_string(status) + "," + (tenant_ID.empty() ? "N/A" : tenant_ID); 
}

// Chuc nang co ban (Basic Function)
void Room::addRoom() {
    string type_id;
    RoomType* matchedRoomType;
    cout << "Nhap thong tin phong:" << endl;
    do {
        RoomType::roomTypeList.show();
        cout << "Loai phong (Type ID: co dang RT.): "; cin >> type_id;
        matchedRoomType = RoomType::roomTypeList.searchID(type_id);
        if (matchedRoomType == nullptr) {
            cout << "Loai phong khong hop le!" << endl;
        }
    } while (matchedRoomType == NULL);  
    int status = 0;            
    string tenant_id = "N/A";   
    Room newRoom(*matchedRoomType, status, tenant_id);
    roomList.add(newRoom);
    cout << "Da them phong voi ID: " << newRoom.getID() << " voi trang thai mac dinh Trong va khong co khach thue." << endl;
    total++;
}

void Room::updateRoom() { // Updating...
    string roomID;
    cout << "Nhap ma phong (Room ID) de cap nhat: "; cin >> roomID;
    Room* room = roomList.searchID(roomID);
    if (room != NULL) {
        int newStatus;               
        cout << "Cap nhat phong voi ma ID: " << room->getID() << endl;
        cout << "Trang thai moi (0: Trong, 2: Dang bao tri): "; cin >> newStatus;
        room->setStatus(newStatus);
        cout << "Phong da duoc cap nhat thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

void Room::deleteRoom() {
    string roomID;
    do {
        roomList.show();
        cout << "Nhap ma phong (Room ID) de xoa (Nhap 0 de thoat): ";
        cin >> roomID;
        if (roomID == "0") {
            cout << "Thoat khoi che do xoa." << endl;
            break;
        }
        if (roomList.deleteNode(roomID)) { 
            cout << "Da xoa phong voi ID: " << roomID << endl;
            total--;
        } else {
            cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
        }
    } while (true);
}
// Search Funcion
void Room::searchByID() {
    string roomID;
    cout << "Nhap ma phong (Room ID) de tim kiem: "; cin >> roomID;
    Room* room = roomList.searchID(roomID);
    if (room) { cout << "Da tim thay phong: " << *room; }
    else { cout << "Khong tim thay phong voi ma ID: " << roomID << endl; }
}

void Room::searchByStatus() {
    int status;
    cout << "Nhap trang thai phong can tim kiem (0: Trong, 1: Co nguoi): "; cin >> status;
    roomList.searchStatus(status); 
}

void Room::searchByName() {
    string name;
    cout << "Nhap ten chu phong can tim kiem: "; cin >> name;
    bool found = false;
    LinkedList<Tenant>::Node* current1 = Tenant::tenantList.getHead();
    while (current1 != nullptr) {
        if (current1->data.getName() == name) {
            break;
        }
        current1 = current1->next;
    }
    LinkedList<Room>::Node* current2 = Room::roomList.getHead();
    while (current2 != nullptr) {
        if (current2->data.getTenantID() == current1->data.getID()) {
            cout << current2->data;
            found = true;
        }
        current2 = current2->next;
    }

    if (!found) {
        cout << "Khong tim thay nguoi thue voi ten: " << name << endl;
    }
}

void Room::searchAll() {
    int choice;
    do {
        cout << "Room Searching Function: " << endl
             << "   1. Search by RoomID" << endl
             << "   2. Search by RoomStatus" << endl
             << "   3. Search by Owner Name" << endl
             << "   0. Exit" << endl
             << "Please enter your option: "; cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByStatus(); break;
            case 3: searchByName(); break;
            case 0: cout << "Exit Search Function." << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void Room::showAllRooms() {
    cout << "Danh sach tat ca cac phong:" << endl;
    roomList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: roomList.sortByID(true); showAllRooms(); break;
        case 2: roomList.sortByID(false); showAllRooms(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Room& r) {
    os << left
       << setw(15) << ("Ma phong: " + r.room_ID) << " | "
       << setw(15) << ("Loai phong: " + r.roomType.getID()) << " | "
       << setw(10) << ("Trang thai: " + to_string(r.status)) << " | "
       << setw(20) << ("Ma khach thue: " + (r.tenant_ID.empty() ? "N/A" : r.tenant_ID)) << " | "
       << "Gia: " << fixed << setprecision(2) << setw(10) << r.roomType.getPrice() << "\n";
    return os;
}
