#include "RoomType.h"
#include "Room.h"
// Static members initialization
int RoomType::total = 0;
int RoomType::currentNumber = 0;
LinkedList<RoomType> RoomType::roomTypeList;

// Title control
bool RoomType::is_header_printed = false;
void RoomType::resetHeader() { is_header_printed = false; }

// Constructors & Destructor
RoomType::RoomType() {}
RoomType::RoomType(const string& desc, double price, const string& name) : description(desc), price(price), name(name) {
    type_ID = generateID(++currentNumber);
}
RoomType::~RoomType() {}

bool RoomType::isActive(string& id) {
    for (int i = 0; i < Room::roomList.size(); i++) {
        Room room = Room::roomList[i];
        if (room.getRoomTypeID() == id) {
            cout << "Khong the xoa, kieu phong nay dang duoc su dung boi phong " << room.getID() << "!" << endl;
            return true;
        }
    }
    return false;
}

string RoomType::generateID(int number) {
    stringstream ss;
    ss << "RT." << setw(2) << setfill('0') << number;
    return ss.str();
}

// Getters
string RoomType::getID() const { return type_ID; }
string RoomType::getDescription() const { return description; }
double RoomType::getPrice() const { return price; }
string RoomType::getName() const { return name; }

// Setters
void RoomType::setTypeID(const string& id) { type_ID = id; }
void RoomType::setDescription(const string& desc) { description = desc; }
void RoomType::setPrice(double p) { price = p; }
void RoomType::setName(const string& n) { name = n; }

// Convert functions
void RoomType::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, type_ID, ',');
    getline(ss, name, ',');
    getline(ss, description, ',');
    ss >> price;
    total++;
}
string RoomType::toString() const { 
    return type_ID + "," + name + "," + description + "," + to_string(price); 
}

// IO functions
void RoomType::load(const string& filename) { roomTypeList.load(filename); }
void RoomType::updateFile(const string& filename) { roomTypeList.updateFile(filename); }

// Basic functions
void RoomType::addRoomType() {
    string name, desc; double price;
    cin.ignore();
    cout << "Nhap ten loai phong (Nhap 0 de thoat): "; getline(cin, name);
    if (name == "0") { cout << "Thoat them loai phong." << endl; return; }
    cout << "Nhap mo ta loai phong (Nhap 0 de thoat): "; getline(cin, desc);
    if (desc == "0") { cout << "Thoat them loai phong." << endl; return; }
    cout << "Nhap gia phong (Nhap 0 de thoat): "; cin >> price;
    if (price == 0) { cout << "Thoat them loai phong." << endl; return; }   
    RoomType newRoom(desc, price, name);
    roomTypeList.add(newRoom); 
    total++;
    cout << "Them loai phong thanh cong!\n";
}

void RoomType::updateRoomType() {
    string id, name, desc; double price;
    cout << "Enter RoomType ID to update: "; cin >> id;
    cin.ignore();
    RoomType* roomType = roomTypeList.searchID(id);
    if (roomType) {
        cout << "Enter new name: "; getline(cin, name); roomType->setName(name);
        cout << "Enter new description: "; getline(cin, desc); roomType->setDescription(desc);
        cout << "Enter new price: "; cin >> price; roomType->setPrice(price);
        cout << "RoomType updated successfully!\n";
    } else cout << "RoomType ID not found!\n";
}

void RoomType::deleteRoomType() {
    string id;
    cout << "Enter RoomType ID to delete: "; cin >> id;
    if (isActive(id)) {
        return;
    }
    if (roomTypeList.searchID(id) != NULL) {
        roomTypeList.deleteNode(id);
        cout << "Xoa kieu phong thanh cong!" << endl;
        total--;
    }
}

void RoomType::showAllRoomTypes() {
    resetHeader();
    cout << "Room Type List:" << endl;
    roomTypeList.show();
    cout << "1. Sort by ID ascending" << endl
         << "2. Sort by ID descending" << endl
         << "3. Search" << endl
         << "0. Exit" << endl
         << "Your choice: ";
    int choice; cin >> choice;
    switch (choice) {
        case 1: roomTypeList.sortByID(true); showAllRoomTypes(); break;
        case 2: roomTypeList.sortByID(false); showAllRoomTypes(); break;
        case 3: searchAll(); break;
        default: break;
    }
}

void RoomType::searchByID() {
    resetHeader();
    string id;
    cout << "Enter RoomType ID to search: "; cin >> id;
    RoomType* found = roomTypeList.searchID(id);
    if (found) cout << "Found room: \n" << *found;
    else cout << "Room not found with ID: " << id << endl;
}

void RoomType::searchByName() {
    resetHeader();
    string name;
    cout << "Enter RoomType Name to search: "; cin >> name;
    bool found = false;
    for (auto current = roomTypeList.begin(); current != nullptr; current = current->next) {
        string roomName = current->data.getName();
        if (toLower(roomName).find(toLower(name)) != string::npos) {
            cout << current->data;
            found = true;
        }
    }
    if (!found) cout << "Room not found with Name: " << name << endl;
    return;
}

void RoomType::searchAll() {
    resetHeader();
    int choice;
    do {
        cout << "RoomType Search Menu:\n"
             << "1. Search by ID\n"
             << "2. Search by Price\n"
             << "3. Search by Name\n"
             << "0. Exit\n"
             << "Your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByPrice(); break; 
            case 3: searchByName(); break;
            case 0: cout << "Exiting search.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void RoomType::searchByPrice() {
    if (roomTypeList.begin() == nullptr) {
        cout << "Danh sach loai phong trong!\n";
        return;
    }

    string input;
    cout << "Nhap dieu kien tim kiem (Vi du: >20000, <50000, =30000): ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Dieu kien khong hop le!\n";
        return;
    }

    char operation = input[0];
    double searchPrice;
    try {
        searchPrice = stod(input.substr(1));
    } catch (...) {
        cout << "Gia tien khong hop le!\n";
        return;
    }

    bool found = false;
    resetHeader();

    for (int i = 0; i < roomTypeList.size(); i++) {
        RoomType rt = roomTypeList[i];
        bool matches = false;

        switch (operation) {
            case '>': matches = rt.getPrice() > searchPrice; break;
            case '<': matches = rt.getPrice() < searchPrice; break;
            case '=': matches = rt.getPrice() == searchPrice; break;
            default: cout << "Toan tu khong hop le! Su dung >, < hoac =\n"; return;
        }

        if (matches) {
            cout << rt;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay loai phong nao phu hop voi dieu kien!\n";
    }
}

ostream& operator<<(ostream& os, const RoomType& rt) {
    const int w_id = 15, w_name = 30, w_desc = 20, w_price = 15;
    
    if (!RoomType::is_header_printed) {
        os << left << setw(w_id) << "RoomType ID" << " | "
           << setw(w_name) << "RoomType Name" << " | "
           << setw(w_desc) << "RoomType Description" << " | "
           << setw(w_price) << "Price (VND)" << endl
           << string(w_id + w_name + w_desc + w_price + 9, '-') << endl;
        RoomType::is_header_printed = true;
    }
    
    os << left << setw(w_id) << rt.getID() << " | "
       << setw(w_name) << rt.getName() << " | "
       << setw(w_desc) << rt.getDescription() << " | "
       << setw(w_price) << fixed << setprecision(2) << rt.getPrice() << endl;
    return os;
}



