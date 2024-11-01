#include "RoomType.h"
using namespace std;

int RoomType::total = 0;
int RoomType::currentNumber = 0;
LinkedList<RoomType> RoomType::roomTypeList;

// Constructors
RoomType::RoomType() {}
RoomType::RoomType(const string& desc, double price)
    : description(desc), price(price) {
    type_ID = generateID(++currentNumber);
}

// Destructor
RoomType::~RoomType() {}

string RoomType::generateID(int number) {
    stringstream ss;
    ss << "RT." << setw(2) << setfill('0') << number;
    return ss.str();
}

void RoomType::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, type_ID, ',');
    getline(ss, description, ',');
    ss >> price;
    total++;
}
// Convert Room object to string
string RoomType::toString() const {
    return type_ID + "," + description + "," + to_string(price);
}

// Getters
string RoomType::getID() const { return type_ID; }
string RoomType::getDescription() const { return description; }
double RoomType::getPrice() const { return price; }

// Setters
void RoomType::setDescription(const string& desc) { description = desc; }
void RoomType::setPrice(double price) { this->price = price; }

// Adding a new RoomType
void RoomType::load(const string& filename) {
    roomTypeList.load(filename);
}
void RoomType::addRoomType() {
    string desc;
    double price;
    cin.ignore();
    cout << "Enter description: ";
    getline(cin, desc);
    cout << "Enter price: ";
    cin >> price;
    roomTypeList.add(RoomType(desc, price));total++;
    cout << "RoomType added successfully!\n";
}

// Updating a RoomType
void RoomType::updateRoomType() {
    string id;
    cout << "Enter RoomType ID to update: ";
    cin >> id;
    RoomType* roomType = roomTypeList.searchID(id);
    if (roomType) {
        cin.ignore();
        cout << "Enter new description: ";
        getline(cin, roomType->description);
        cout << "Enter new price: ";
        cin >> roomType->price;
        cout << "RoomType updated successfully!\n";
    } else {
        cout << "RoomType ID not found!\n";
    }
}

// Deleting a RoomType
void RoomType::deleteRoomType() {
    string id;
    cout << "Enter RoomType ID to delete: ";
    cin >> id;

    RoomType* roomType = roomTypeList.searchID(id); // Tìm kiếm trước khi xóa
    if (roomType) {
        roomTypeList.deleteNode(id);
        roomType = roomTypeList.searchID(id); // Kiểm tra lại sau khi xóa
        if (!roomType) {
            total--;
            cout << "RoomType deleted successfully!\n";
        } else {
            cout << "Failed to delete RoomType. ID still exists!\n";
        }
    } else {
        cout << "RoomType ID not found!\n";
    }
}

// Display all RoomTypes
void RoomType::showAllRoomTypes() {
    cout << "List of all RoomTypes:\n";
    roomTypeList.show();
}

// Search by room ID
void RoomType::searchByID() {
    string roomID;
    cout << "Nhap RoomType ID de tim kiem: ";
    cin >> roomID;

    RoomType* find = roomTypeList.searchID(roomID);
    if (find) {
        cout << "Da tim thay phong: " << *find;
    } else {
        cout << "Khong tim thay phong voi ma ID: " << roomID << endl;
    }
}

// Overloaded output operator
ostream& operator<<(ostream& os, const RoomType& rt) {
    os << "Type ID: " << rt.getID() << ", "
       << "Description: " << rt.getDescription() << ", "
       << "Price: " << rt.getPrice() << "\n";
    return os;
}

void RoomType::updateFile(const string& filename) {
    roomTypeList.updateFile(filename);
}