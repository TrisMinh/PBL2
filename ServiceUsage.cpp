#include "ServiceUsage.h"

// Static Element
int ServiceUsage::total = 0;
int ServiceUsage::currentNumber = 0;
LinkedList<ServiceUsage> ServiceUsage::usageList;

// Constructor
ServiceUsage::ServiceUsage() {}
ServiceUsage::ServiceUsage(const string& roomId, const string& servId, const string& tenantId, int qty, DATE date)
    : room_ID(roomId), service_ID(servId), quantity(qty), tenantID(tenantId), usageDate(date) {
    currentNumber++;
    usage_ID = generateID(currentNumber);
}
ServiceUsage::~ServiceUsage() {}

// ID Generate
string ServiceUsage::generateID(int number) {
    stringstream ss;
    ss << "SU." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Load function
void ServiceUsage::load(const string& filename) { usageList.load(filename); }
void ServiceUsage::updateFile(const string& filename) { usageList.updateFile(filename); }

// Get function
string ServiceUsage::getID() const { return usage_ID; }
string ServiceUsage::getRoomID() const { return room_ID; }
string ServiceUsage::getTenantID() const { return tenantID; }
string ServiceUsage::getServiceID() const { return service_ID; }
int ServiceUsage::getUsageMonth() const { return usageDate.get_month(); }
int ServiceUsage::getUsageYear() const { return usageDate.get_year(); }
int ServiceUsage::getQuantity() const { return quantity; }


// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void ServiceUsage::fromString(const string& line) {
    string usageDatestr;
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, service_ID, ',');
    getline(ss, tenantID, ',');
    ss >> quantity;
    ss.ignore(1);
    getline(ss, usageDatestr);
    usageDate.fromString(usageDatestr);
    total++;
}

string ServiceUsage::toString() const {
    stringstream ss;
    ss << usage_ID << ',' << room_ID << ',' << service_ID << ',' 
       << tenantID << ',' << quantity << ',' << usageDate.toString();
    return ss.str();
}

// Chuc nang co ban (Basic Function)
void ServiceUsage::addServiceUsage() {
    string room_ID, service_ID;
    int quantity;
    DATE usageDate;
    if (Service::serviceList.getHead() == NULL) { 
        cout << "None of Service! " << endl;
        return;
    }
    bool found1 = false;
    bool found2 = false;
    do{
        cout << "Room ID: "; cin >> room_ID;
        Room* room = Room::roomList.searchID(room_ID);
        if (room != NULL && room->getStatus() == 1) { found1 = true; } 
        else { cout << "Room ID not found or no owner. Please enter again! "<< endl; }
    } while(!found1);
    do{
        cout << "Service ID: "; cin >> service_ID;
        Service* service = Service::serviceList.searchID(service_ID);
        if (service != NULL) { found2 = true;} 
        else { cout << "Service ID not found. Please enter again! "<< endl; }
    } while(!found2);
    cout << "Quantity: "; cin >> quantity;
    cout << "Usage Date: "; cin >> usageDate;
    ServiceUsage newUsage(room_ID, service_ID, Account::currentTenantID ,quantity, usageDate);
    usageList.add(newUsage);
    cout << "Service usage added successfully!" << endl;
    total++;
}

void ServiceUsage::updateServiceUsage() {
    string usageID;
    cout << "Nhap Usage ID de cap nhat: "; cin >> usageID;
    ServiceUsage* usage = usageList.searchID(usageID);
    if (usage) {
        cout << "Cap nhat Usage ID: " << usage->usage_ID << endl;
        cout << "Room ID (nhap moi neu muon thay doi): "; cin >> usage->room_ID;
        cout << "Service ID (nhap moi neu muon thay doi): "; cin >> usage->service_ID;
        cout << "Quantity: "; cin >> usage->quantity;
        cout << "Usage Date: "; cin >> usage->usageDate;
        cout << "Service usage updated successfully!" << endl;
    } else {
        cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl;
    }
}

void ServiceUsage::deleteServiceUsage() {
    string usageID;
    cout << "Nhap Usage ID de xoa: "; cin >> usageID;
    usageList.deleteNode(usageID);
    total--;
}

// Search Function
void ServiceUsage::searchByID() {
    string usageID;
    cout << "Nhap Usage ID de tim kiem: "; cin >> usageID;
    ServiceUsage* usage = usageList.searchID(usageID);
    if (usage) { cout << "Da tim thay: " << *usage; } 
    else { cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl; }
}

void ServiceUsage::searchByRoomID() {
    string roomID;
    cout << "Nhap RoomID de tim kiem dich vu da su dung: "; cin >> roomID;
    LinkedList<ServiceUsage>::Node* current = usageList.head;
    bool found = false;
    while (current) {
        if (current->data.room_ID == roomID) {
            cout << current->data;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay su dung dich vu voi Room ID: " << roomID << endl;
    }
}

void ServiceUsage::searchAll() {
    int choice;
    do {
        cout << "   1. Search by RoomID" << endl
             << "   2. Search by ServiceUsageID" << endl
             << "   0. Exit" << endl;
        cout << "Please enter your option: "; cin >> choice;
        switch (choice) {
            case 1: searchByRoomID(); break;
            case 2: searchByID(); break;
            case 0: cout << "Exiting search menu." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void ServiceUsage::showAllServiceUsages() {
    cout << "Danh sach tat ca cac su dung dich vu:" << endl;
    usageList.show();
    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "0. Thoat!" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: usageList.sortByID(true); showAllServiceUsages(); break;
        case 2: usageList.sortByID(false); showAllServiceUsages();  break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const ServiceUsage& su) {
    // Định nghĩa độ rộng cho từng cột
    const int width_usage_id = 15;
    const int width_room_id = 15;
    const int width_service_id = 15;
    const int width_tenant_id = 15;
    const int width_quantity = 10;
    const int width_usage_month = 10;

    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_usage_id) << "Usage ID" << " | "
           << setw(width_room_id) << "Room ID" << " | "
           << setw(width_service_id) << "Service ID" << " | "
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_quantity) << "Quantity" << " | "
           << setw(width_usage_month) << "Usage Month"
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_usage_id + 2) << ""
           << setw(width_room_id + 2) << ""
           << setw(width_service_id + 2) << ""
           << setw(width_tenant_id + 2) << ""
           << setw(width_quantity + 2) << ""
           << setw(width_usage_month + 2) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In dữ liệu ServiceUsage
    os << left
       << setw(width_usage_id) << su.usage_ID << " | "
       << setw(width_room_id) << su.room_ID << " | "
       << setw(width_service_id) << su.service_ID << " | "
       << setw(width_tenant_id) << su.tenantID << " | "
       << setw(width_quantity) << su.quantity << " | "
       << setw(width_usage_month) << su.usageDate.toString() << endl;
    return os;
}
