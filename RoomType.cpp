#include "RoomType.h"
using namespace std;

// Static members initialization
int RoomType::total = 0;
int RoomType::currentNumber = 0;
LinkedList<RoomType> RoomType::roomTypeList;

// Title control
bool RoomType::is_header_printed = false;
void RoomType::resetHeader() { is_header_printed = false; }

// Constructors & Destructor
RoomType::RoomType() {}
RoomType::RoomType(const string& desc, double price) : description(desc), price(price) {
    type_ID = generateID(++currentNumber);
}
RoomType::~RoomType() {}

// Private helper
string RoomType::generateID(int number) {
    stringstream ss;
    ss << "RT." << setw(2) << setfill('0') << number;
    return ss.str();
}

// Getters
string RoomType::getID() const { return type_ID; }
string RoomType::getDescription() const { return description; }
double RoomType::getPrice() const { return price; }

// Setters
void RoomType::setTypeID(const string& id) { type_ID = id; }
void RoomType::setDescription(const string& desc) { description = desc; }
void RoomType::setPrice(double p) { price = p; }

// Convert functions
void RoomType::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, type_ID, ',');
    getline(ss, description, ',');
    ss >> price;
    total++;
}
string RoomType::toString() const { return type_ID + "," + description + "," + to_string(price); }

// IO functions
void RoomType::load(const string& filename) { roomTypeList.load(filename); }
void RoomType::updateFile(const string& filename) { roomTypeList.updateFile(filename); }

// Basic functions
void RoomType::addRoomType() {
    string desc; double price;
    cin.ignore();
    cout << "Enter description: "; getline(cin, desc);
    cout << "Enter price: "; cin >> price;
    roomTypeList.add(RoomType(desc, price)); total++;
    cout << "RoomType added successfully!\n";
}

void RoomType::updateRoomType() {
    string id, desc; double price;
    cout << "Enter RoomType ID to update: "; cin >> id;
    cin.ignore();
    RoomType* roomType = roomTypeList.searchID(id);
    if (roomType) {
        cout << "Enter new description: "; getline(cin, desc); roomType->setDescription(desc);
        cout << "Enter new price: "; cin >> price; roomType->setPrice(price);
        cout << "RoomType updated successfully!\n";
    } else cout << "RoomType ID not found!\n";
}

void RoomType::deleteRoomType() {
    string id;
    cout << "Enter RoomType ID to delete: "; cin >> id;
    roomTypeList.deleteNode(id);
    total--;
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
    if (found) cout << "Found room: " << *found;
    else cout << "Room not found with ID: " << id << endl;
}

void RoomType::searchAll() {
    resetHeader();
    int choice;
    do {
        cout << "RoomType Search Menu:\n"
             << "1. Search by ID\n"
             << "2. Search by Price\n"
             << "0. Exit\n"
             << "Your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByPrice(); break; 
            case 0: cout << "Exiting search.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void RoomType::searchByPrice() {
    if (roomTypeList.begin() == nullptr) {
        cout << "Danh sách loại phòng trống!\n";
        return;
    }

    string input;
    cout << "Nhap dieu kien tim kiem (Vi du: >20000, <50000, =30000): ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Điều kiện không hợp lệ!\n";
        return;
    }

    char operation = input[0];
    double searchPrice;
    try {
        searchPrice = stod(input.substr(1));
    } catch (...) {
        cout << "Giá tiền không hợp lệ!\n";
        return;
    }

    bool found = false;
    resetHeader();

    for (int i = 0; i < roomTypeList.size(); i++) {
        RoomType rt = roomTypeList[i];
        bool matches = false;

        switch (operation) {
            case '>':
                matches = rt.getPrice() > searchPrice;
                break;
            case '<':
                matches = rt.getPrice() < searchPrice;
                break;
            case '=':
                matches = rt.getPrice() == searchPrice;
                break;
            default:
                cout << "Toán tử không hợp lệ! Sử dụng >, < hoặc =\n";
                return;
        }

        if (matches) {
            cout << rt;
            found = true;
        }
    }

    if (!found) {
        cout << "Không tìm thấy loại phòng nào phù hợp với điều kiện!\n";
    }
}

// Output operator overload
ostream& operator<<(ostream& os, const RoomType& rt) {
    const int w_id = 15, w_desc = 30, w_price = 10;
    
    if (!RoomType::is_header_printed) {
        os << left << setw(w_id) << "Type ID" << " | "
           << setw(w_desc) << "Description" << " | "
           << setw(w_price) << "Price" << endl
           << string(w_id + w_desc + w_price + 6, '-') << endl;
        RoomType::is_header_printed = true;
    }
    
    os << left << setw(w_id) << rt.getID() << " | "
       << setw(w_desc) << rt.getDescription() << " | "
       << setw(w_price) << fixed << setprecision(2) << rt.getPrice() << endl;
    return os;
}


