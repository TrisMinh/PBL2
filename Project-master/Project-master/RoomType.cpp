#include "RoomType.h"
#include "Room.h"
#include <QTextStream>
#include <string>

int RoomType::total = 0;
int RoomType::currentNumber = 0;
LinkedList<RoomType> RoomType::roomTypeList;

RoomType::RoomType() {}
RoomType::RoomType(const string& desc, double price, const string& name) : description(desc), price(price), name(name) {
    type_ID = generateID(++currentNumber);
}
RoomType::~RoomType() {}

bool RoomType::isActive(string& id) {
    for (int i = 0; i < Room::roomList.size(); i++) {
        Room room = Room::roomList[i];
        if (room.getRoomTypeID() == id) {
            return true;
        }
    }
    return false;
}

double RoomType::getPrice() const { return price; }
string RoomType::getID() const { return type_ID; }
string RoomType::getDescription() const { return description; }
string RoomType::getName() const { return name; }

void RoomType::setTypeID(const string& id) { type_ID = id; }
void RoomType::setDescription(const string& desc) { description = desc; }
void RoomType::setPrice(double p) { price = p; }
void RoomType::setName(const string& n) { name = n; }

string RoomType::generateID(int number) {
    stringstream ss;
    ss << "RT." << setw(2) << setfill('0') << number;
    return ss.str();
}

void RoomType::load(const string& filename) { roomTypeList.load(filename); }

// void RoomType::fromString(const string& line) {
//     // Sử dụng stringList để tách các phần của chuỗi
//     stringList parts = line.split(',');

//     if (parts.size() < 3) {
//         qWarning() << "Line format is invalid:" << line;
//         return;
//     }

//     // Lưu trữ các giá trị vào các biến thành viên
//     type_ID = parts[0].trimmed();       // Tách ID loại phòng
//     description = parts[1].trimmed();    // Tách mô tả
//     price = parts[2].trimmed().toDouble();  // Chuyển đổi sang số thực (double)

//     total++;
// }

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


void RoomType::showAllRoomTypes(Admin* adminWindow){
    roomTypeList.show(adminWindow);
}

void RoomType::display(Admin* adminWindow) const {
    adminWindow->displayRoomTypes(*this);
}

void RoomType::addRoomType(const string& name, const string& desc, double price) {
    RoomType newRoom(desc, price, name);
    roomTypeList.add(newRoom);
    total++;
    cout << "Them loai phong thanh cong!\n";
}

void RoomType::updateRoomType(const string& id, const string& name, const string& desc, double price) {
    RoomType* roomType = roomTypeList.searchID(id);
    if (roomType) {
        roomType->setName(name);
        roomType->setDescription(desc);
        roomType->setPrice(price);
    }
}

void RoomType::deleteRoomType(const string& id) {
    if (roomTypeList.searchID(id) != NULL) {
        roomTypeList.deleteNode(id);
        total--;
    }
}

void RoomType::searchByID(const string& id, Admin* adminWindow){
    bool found = false;
    LinkedList<RoomType>::Node* current = roomTypeList.begin();
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

void RoomType::searchByName(const string& name, Admin* adminWindow) {
    for (auto current = roomTypeList.begin(); current != nullptr; current = current->next) {
        string roomName = current->data.getName();
        if (roomName.find(name) != string::npos) {
            current->data.display(adminWindow);
        }
    }
    return;
}

// void RoomType::searchByPrice(const string& price, Admin* adminWindow){
//     if (roomTypeList.begin() == nullptr) {
//         return;
//     }

//     string input;
//     char operation = input[0];
//     double searchPrice;
//     try {
//         searchPrice = stod(input.substr(1));
//     } catch (...) {
//         cout << "Giá tiền không hợp lệ!\n";
//         return;
//     }

//     bool found = false;

//     for (int i = 0; i < roomTypeList.size(); i++) {
//         RoomType rt = roomTypeList[i];
//         bool matches = false;

//         switch (operation) {
//         case '>': matches = rt.getPrice() > searchPrice; break;
//         case '<': matches = rt.getPrice() < searchPrice; break;
//         case '=': matches = rt.getPrice() == searchPrice; break;
//         default: cout << "Toán tử không hợp lệ! Sử dụng >, < hoặc =\n"; return;
//         }

//         if (matches) {
//             rt.display(adminWindow);
//             found = true;
//         }
//     }

//     if (!found) {
//         return;
//     }
// }
