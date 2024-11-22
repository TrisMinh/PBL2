#include "ServiceUsage.h"

// Static Element
int ServiceUsage::total = 0;
int ServiceUsage::currentNumber = 0;
LinkedList<ServiceUsage> ServiceUsage::usageList;
bool ServiceUsage::is_header_printed = false;
void ServiceUsage::resetHeader() { is_header_printed = false; }

// Constructor
ServiceUsage::ServiceUsage() {}
ServiceUsage::ServiceUsage(const string& roomId, const string& servId, const string& tenantId, DATE date, bool status)
    : room_ID(roomId), service_ID(servId), tenantID(tenantId), usageDate(date), status(status) {
    usage_ID = generateID(++currentNumber);
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
bool ServiceUsage::getStatus() const { return status; }
void ServiceUsage::setStatus(bool newStatus) { status = newStatus; }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void ServiceUsage::fromString(const string& line) {
    string usageDatestr;
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, service_ID, ',');
    getline(ss, tenantID, ',');
    getline(ss, usageDatestr, ',');
    ss >> status;
    usageDate.fromString(usageDatestr);
    total++;
}

string ServiceUsage::toString() const {
    stringstream ss;
    ss << usage_ID << ',' << room_ID << ',' << service_ID << ',' 
       << tenantID << ',' << usageDate.toString() << ',' << status;
    return ss.str();
}

// Chuc nang co ban (Basic Function)
void ServiceUsage::addServiceUsage() {
    Room::searchRoomByTenantID(Account::currentTenantID);
    string room_ID, service_ID;
    DATE usageDate;
    if (Service::serviceList.begin() == NULL) { 
        cout << "None of Service! " << endl;
        return;
    }

    bool found1 = false;
    bool found2 = false;
    do{
        resetHeader();
        cout << "Room ID: "; cin >> room_ID;
        Room* room = Room::roomList.searchID(room_ID);
        if (room != NULL && room->getStatus() == 1) { found1 = true; } 
        else { cout << "Room ID not found or no owner. Please enter again! "<< endl; }
    } while(!found1);
    
    do{
        resetHeader();
        Service::serviceList.show();
        cout << "Service ID: "; cin >> service_ID;
        
        // Kiểm tra xem dịch vụ này đã được đăng ký chưa
        LinkedList<ServiceUsage>::Node* current = usageList.begin();
        bool serviceAlreadyActive = false;
        while (current) {
            if (current->data.getTenantID() == Account::currentTenantID && 
                current->data.getServiceID() == service_ID &&
                current->data.getStatus() == true) {
                cout << "This service is already active for your account!" << endl;
                serviceAlreadyActive = true;
                break;
            }
            current = current->next;
        }
        if (serviceAlreadyActive) continue;

        Service* service = Service::serviceList.searchID(service_ID);
        if (service != NULL) { found2 = true;} 
        else { cout << "Service ID not found. Please enter again! "<< endl; }
    } while(!found2);

    cout << "Usage Date: "; cin >> usageDate;
    ServiceUsage newUsage(room_ID, service_ID, Account::currentTenantID, usageDate, true);
    usageList.add(newUsage);
    cout << "Service usage added successfully!" << endl;
    total++;
}

void ServiceUsage::deleteServiceUsage() {
    string usageID;
    cout << "Nhap Usage ID de xoa: "; cin >> usageID;
    usageList.deleteNode(usageID);
    total--;
}

// Search Function
void ServiceUsage::searchByID() {
    resetHeader();
    string usageID;
    cout << "Nhap Usage ID de tim kiem: "; cin >> usageID;
    ServiceUsage* usage = usageList.searchID(usageID);
    if (usage) { cout << "Da tim thay: " << *usage; } 
    else { cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl; }
}

void ServiceUsage::searchByRoomID() {
    resetHeader();
    string roomID;
    cout << "Nhap RoomID de tim kiem dich vu da su dung: "; cin >> roomID;
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
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
    resetHeader();
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
    resetHeader();
    cout << "Danh sach tat ca cac su dung dich vu:" << endl;
    usageList.show();
    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "3. Tim kiem lich su su dung dich vu" << endl
         << "0. Thoat!" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: usageList.sortByID(true); showAllServiceUsages(); break;
        case 2: usageList.sortByID(false); showAllServiceUsages();  break;
        case 3: searchAll(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const ServiceUsage& su) {
    const int width_usage_id = 15;
    const int width_room_id = 15;
    const int width_service_id = 15;
    const int width_tenant_id = 15;
    const int width_usage_month = 15;
    const int width_status = 10;

    if (!ServiceUsage::is_header_printed) {
        os << left
           << setw(width_usage_id) << "Usage ID" << " | "
           << setw(width_room_id) << "Room ID" << " | "
           << setw(width_service_id) << "Service ID" << " | "
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_usage_month) << "Usage Month" << " | "
           << setw(width_status) << "Status"
           << endl;

        os << setfill('-')
           << setw(width_usage_id + 2) << ""
           << setw(width_room_id + 2) << ""
           << setw(width_service_id + 2) << ""
           << setw(width_tenant_id + 2) << ""
           << setw(width_usage_month + 2) << ""
           << setw(width_status + 2) << ""
           << setfill(' ') << endl;

        ServiceUsage::is_header_printed = true;
    }

    os << left
       << setw(width_usage_id) << su.usage_ID << " | "
       << setw(width_room_id) << su.room_ID << " | "
       << setw(width_service_id) << su.service_ID << " | "
       << setw(width_tenant_id) << su.tenantID << " | "
       << setw(width_usage_month) << su.usageDate.toString() << " | "
       << setw(width_status) << (su.status ? "Active" : "Inactive") << endl;
    return os;
}

void ServiceUsage::stopService() {
    string serviceID;
    cout << "Nhap Service ID muon dung su dung: "; cin >> serviceID;
    
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current) {
        if (current->data.getServiceID() == serviceID && 
            current->data.getTenantID() == Account::currentTenantID &&
            current->data.getStatus() == true) {
            current->data.setStatus(false);
            cout << "Da dung su dung dich vu thanh cong!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Khong tim thay dich vu dang su dung!" << endl;
}

void ServiceUsage::searchByTenantID(string tenantID) {
    resetHeader();
    bool found = false;
    cout << "\n\t\t\t\t\t==========SEARCH RESULT==========\n";
    for (int i = 0; i < usageList.size(); i++) {
        if (usageList[i].getTenantID() == tenantID && usageList[i].getStatus()) {
            cout << usageList[i];
            found = true;
        }
    }
    if (!found) {
        cout << "\t\t\t\t\tNo service usage found!\n";
    }
    cout << "\t\t\t\t\t==============================\n";
}
