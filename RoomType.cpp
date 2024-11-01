#include "RoomType.h"
using namespace std;

// Static Element
int RoomType::total = 0;
int RoomType::currentNumber = 0;
LinkedList<RoomType> RoomType::roomTypeList;

// Constructors
RoomType::RoomType() {}
RoomType::RoomType(const string& desc, double price)
    : description(desc), price(price) {
    type_ID = generateID(++currentNumber);
}
RoomType::~RoomType() {}

// ID Generate
string RoomType::generateID(int number) {
    stringstream ss;
    ss << "RT." << setw(2) << setfill('0') << number;
    return ss.str();
}

// Load function
void RoomType::load(const string& filename) { roomTypeList.load(filename); }
void RoomType::updateFile(const string& filename) { roomTypeList.updateFile(filename); }

// Get function
string RoomType::getID() const { return type_ID; }
string RoomType::getDescription() const { return description; }
double RoomType::getPrice() const { return price; }

// Set function
void RoomType::setDescription(const string& desc) { description = desc; }
void RoomType::setPrice(double price) { this->price = price; }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void RoomType::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, type_ID, ',');
    getline(ss, description, ',');
    ss >> price;
    total++;
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string RoomType::toString() const {
    return type_ID + "," + description + "," + to_string(price);
}

// Chuc nang co ban (Basic Function)
void RoomType::addRoomType() {
    string desc;
    double price;
    cout << "Enter description: "; cin >> desc;
    cout << "Enter price: "; cin >> price;
    roomTypeList.add(RoomType(desc, price));total++;
    cout << "RoomType added successfully!\n";
}

void RoomType::updateRoomType() {
    string id;
    cout << "Enter RoomType ID to update: "; cin >> id;
    RoomType* roomType = roomTypeList.searchID(id);
    if (roomType) {
        cout << "Enter new description: "; cin >> roomType->description;
        cout << "Enter new price: "; cin >> roomType->price;
        cout << "RoomType updated successfully!\n";
    } else {
        cout << "RoomType ID not found!\n";
    }
}

void RoomType::deleteRoomType() {
    string id;
    cout << "Enter RoomType ID to delete: "; cin >> id;
    roomTypeList.deleteNode(id);
    total--;
}

// Search Function
void RoomType::searchByID() {
    string roomID;
    cout << "Nhap RoomType ID de tim kiem: "; cin >> roomID;
    RoomType* find = roomTypeList.searchID(roomID);
    if (find) { cout << "Da tim thay phong: " << *find; } 
    else { cout << "Khong tim thay phong voi ma ID: " << roomID << endl; }
}

void RoomType::searchAll() {
    int choice;
    do {
        cout << "RoomType Searching Function: " << endl;
        cout << "   1. Search by RoomTypeID" << endl;
        cout << "   0. Exit" << endl;
        cout << "Please enter your option: "; cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 0: cout << "Exit Search Function." << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void RoomType::showAllRoomTypes() {
    cout << "Danh sach tat ca cac phong:" << endl;
    roomTypeList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: roomTypeList.sortByID(true); showAllRoomTypes(); break;
        case 2: roomTypeList.sortByID(false); showAllRoomTypes(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const RoomType& rt) {
    os << "Type ID: " << rt.getID() << ", "
       << "Description: " << rt.getDescription() << ", "
       << "Price: " << rt.getPrice() << "\n";
    return os;
}

