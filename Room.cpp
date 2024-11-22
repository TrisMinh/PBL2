#include "Room.h"

// Static Element
int Room::total = 0;
int Room::currentNumber = 0;
LinkedList<Room> Room::roomList;
bool Room::is_header_printed = false;

// Constructor
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

// Load function
void Room::load(const string& filename) { roomList.load(filename); }
void Room::updateFile(const string& filename) { roomList.updateFile(filename); }


// Get function
string Room::getID() const { return room_ID; }
int Room::getStatus() const { return status; }
double Room::getPrice() const {
    return roomType ? roomType->getPrice() : 0.0;
}
string Room::getTenantID() const { return tenant_ID; }
string Room::getRoomTypeID() const {
    return roomType ? roomType->getID() : "N/A";
}

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
    roomType = RoomType::roomTypeList.searchID(type_id);
    total++;
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Room::toString() const { 
    return room_ID + "," + getRoomTypeID() + "," + to_string(status) + "," + (tenant_ID.empty() ? "N/A" : tenant_ID); 
}

// Chuc nang co ban (Basic Function)
void Room::addRoom() {
    Room::resetHeader();
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
            cout << "Khong the cap nhat trang thai phong vi phong dang co nguoi thue!" << endl;
            return;
        }
        int newStatus;               
        cout << "Cap nhat phong voi ma ID: " << room->getID() << endl;
        cout << "Trang thai moi (0: Trong, 3: Dang bao tri): "; cin >> newStatus;
        if (newStatus != 0 && newStatus != 3) {
            cout << "Trang thai khong hop le! Chi co the cap nhat sang trang thai Trong (0) hoac Dang bao tri (2)" << endl;
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
    cout << "Nhap trang thai phong can tim kiem (0: Trong, 1: Co nguoi): "; cin >> status;
    roomList.searchStatus(status); 
}

// Hàm chuyển đổi chuỗi thành chữ thường
string toLower(string str) {
    for(char& c : str) { // duyệt chuỗi 
        if(c >= 'A' && c <= 'Z') c += 32;  
    }
    return str;
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
        // Chỉ kiểm tra các phòng có người thuê
        if (current->data.getTenantID() != "N/A") {
            // Tìm thông tin người thuê từ tenant_ID
            Tenant* tenant = Tenant::tenantList.searchID(current->data.getTenantID());
            if (tenant != nullptr) {
                // So sánh tên (không phân biệt hoa thường)
                if (toLower(tenant->getName()).find(toLower(searchName)) != string::npos) {
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
    resetHeader();
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

void Room::resetRoom() {
    status = 0;
    tenant_ID = "N/A";
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Room& r) {
    const int width_room_id = 15;
    const int width_room_type = 15;
    const int width_status = 15;
    const int width_tenant_id = 20;
    const int width_tenant_name = 25;
    const int width_price = 10;

    if (!Room::is_header_printed) {
        os << left
           << setw(width_room_id) << "Ma phong" << " | "
           << setw(width_room_type) << "Loai phong" << " | "
           << setw(width_status) << "Trang thai" << " | "
           << setw(width_tenant_id) << "Ma khach thue" << " | "
           << setw(width_tenant_name) << "Ten khach thue" << " | "
           << setw(width_price) << "Gia" 
           << endl;

        os << setfill('-')
           << setw(width_room_id + 2) << ""
           << setw(width_room_type + 3) << ""
           << setw(width_status + 3) << ""
           << setw(width_tenant_id + 3) << ""
           << setw(width_tenant_name + 3) << ""
           << setw(width_price + 1) << ""
           << setfill(' ') << endl;

        Room::is_header_printed = true;
    }

    // Lấy tên khách thuê từ ID
    string tenantName = "N/A";
    if (r.tenant_ID != "N/A") {
        Tenant* tenant = Tenant::tenantList.searchID(r.tenant_ID);
        if (tenant != nullptr) {
            tenantName = tenant->getName();
        }
    }

    os << left 
       << setw(width_room_id) << r.room_ID << " | "
       << setw(width_room_type) << r.getRoomTypeID() << " | "
       << setw(width_status) << (r.status == 0 ? "Trong" : 
                                (r.status == 1 ? "Dang thue" : 
                                (r.status == 3 ? "Dang bao tri" : "Da dat"))) << " | "
       << setw(width_tenant_id) << (r.tenant_ID.empty() ? "N/A" : r.tenant_ID) << " | "
       << setw(width_tenant_name) << tenantName << " | "
       << fixed << setprecision(2) << setw(width_price) << r.getPrice() << endl;

    return os;
}

RoomType* Room::getRoomType() const {
    return roomType;
}

void Room::setRoomType(RoomType* type) {
    roomType = type;
}

void Room::resetHeader() {
    is_header_printed = false;
}
