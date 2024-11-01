#include "ServiceUsage.h"
using namespace std;

int ServiceUsage::total = 0;
int ServiceUsage::currentNumber = 0;
LinkedList<ServiceUsage> ServiceUsage::usageList;

// Khởi tạo
ServiceUsage::ServiceUsage() {}

ServiceUsage::ServiceUsage(const string& roomId, const string& servId, int qty, int month)
    : room_ID(roomId), service_ID(servId), quantity(qty), usage_month(month) {
    total++;
    currentNumber++;
    usage_ID = generateID(currentNumber);
}

// Lấy ID sử dụng
string ServiceUsage::getID() const {
    return usage_ID;
}

// Generate
string ServiceUsage::generateID(int number) {
    stringstream ss;
    ss << "SU." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Chuyển từ chuỗi
void ServiceUsage::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, service_ID, ',');
    ss >> quantity;
    ss.ignore(1);
    ss >> usage_month;
    total++;
}
string ServiceUsage::toString() const {
    stringstream ss;
    ss << usage_ID << ',' << room_ID << ',' << service_ID << ',' 
       << quantity << ',' << usage_month;
    return ss.str();
}

// Định nghĩa toán tử <<
ostream& operator<<(ostream& os, const ServiceUsage& su) {
    os << left
       << setw(15) << ("Usage ID: " + su.usage_ID) << " | "
       << setw(15) << ("Room ID: " + su.room_ID) << " | "
       << setw(15) << ("Service ID: " + su.service_ID) << " | "
       << setw(10) << ("Quantity: " + to_string(su.quantity)) << " | "
       << setw(10) << ("Usage Month: " + to_string(su.usage_month)) << "\n";
    return os;
}

// Thêm dịch vụ sử dụng
void ServiceUsage::addServiceUsage() {
    string room_ID, service_ID;
    int quantity, usage_month;
    cout << "Room ID: "; cin >> room_ID;
    cout << "Service ID: "; cin >> service_ID;
    cout << "Quantity: "; cin >> quantity;
    cout << "Usage Month: "; cin >> usage_month;

    ServiceUsage newUsage(room_ID, service_ID, quantity, usage_month);
    usageList.add(newUsage);
    cout << "Service usage added successfully!" << endl;
}

// Cập nhật dịch vụ sử dụng
void ServiceUsage::updateServiceUsage() {
    string usageID;
    cout << "Nhap Usage ID de cap nhat: ";
    cin >> usageID;

    ServiceUsage* usage = usageList.searchID(usageID);
    if (usage) {
        cout << "Cap nhat Usage ID: " << usage->usage_ID << endl;
        cout << "Room ID (nhap moi neu muon thay doi): "; cin >> usage->room_ID;
        cout << "Service ID (nhap moi neu muon thay doi): "; cin >> usage->service_ID;
        cout << "Quantity: "; cin >> usage->quantity;
        cout << "Usage Month: "; cin >> usage->usage_month;

        cout << "Service usage updated successfully!" << endl;
    } else {
        cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl;
    }
}

// Xoá dịch vụ sử dụng
void ServiceUsage::deleteServiceUsage() {
    string usageID;
    cout << "Nhap Usage ID de xoa: ";
    cin >> usageID;
    usageList.deleteNode(usageID);
    cout << "Service usage deleted successfully!" << endl;
    total--;
}

// Hiển thị toàn bộ dịch vụ sử dụng
void ServiceUsage::showAllServiceUsages() {
    cout << "Danh sach tat ca cac su dung dich vu:" << endl;
    usageList.show();

    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "0. Thoat!" << endl;

    int choice;
    cout << "Vui long chon mot lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1: usageList.sortByID(true); break;
        case 2: usageList.sortByID(false); break;
        default: return;
    }
    showAllServiceUsages(); // Gọi lại để hiển thị sau khi sắp xếp
}

// Tìm kiếm dịch vụ sử dụng theo ID
void ServiceUsage::searchByID() {
    string usageID;
    cout << "Nhap Usage ID de tim kiem: ";
    cin >> usageID;

    ServiceUsage* usage = usageList.searchID(usageID);
    if (usage) {
        cout << "Da tim thay: " << *usage;
    } else {
        cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl;
    }
}

// Tìm kiếm dịch vụ sử dụng theo RoomID
void ServiceUsage::searchByRoomID() {
    string roomID;
    cout << "Nhap RoomID de tim kiem dich vu da su dung: ";
    cin >> roomID;

    typename LinkedList<ServiceUsage>::Node* current = usageList.head;
    bool found = false;

    while (current) {
        if (current->data.room_ID == roomID) {
            cout << "Da tim thay: " << current->data;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay su dung dich vu voi Room ID: " << roomID << endl;
    }
}

// Tìm kiếm dịch vụ sử dụng
void ServiceUsage::searchAll() {
    int choice;
    do {
        cout << "   1. Search by RoomID" << endl
             << "   2. Search by ServiceUsageID" << endl
             << "   0. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchByRoomID(); break;
            case 2: searchByID(); break;
            case 0: cout << "Exiting search menu." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 0);
}

void ServiceUsage::load(const string& filename) {
    usageList.load(filename);
}
void ServiceUsage::updateFile(const string& filename) {
    usageList.updateFile(filename);
}