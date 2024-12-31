#include "ServiceUsage.h"

// Static Element
int ServiceUsage::total = 0;
int ServiceUsage::currentNumber = 0;
LinkedList<ServiceUsage> ServiceUsage::usageList;
bool ServiceUsage::is_header_printed = false;
void ServiceUsage::resetHeader() { is_header_printed = false; }

// Constructor
ServiceUsage::ServiceUsage() {}
ServiceUsage::ServiceUsage(const string& roomId, const string& servId, const string& tenantId, bool status)
    : room_ID(roomId), service_ID(servId), tenantID(tenantId), status(status), quantity(1) {
    if (servId == "S.005" || servId == "S.006") quantity = 0;
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
bool ServiceUsage::getStatus() const { return status; }
void ServiceUsage::setStatus(bool newStatus) { status = newStatus; }
void ServiceUsage::setQuantity(int qty) { quantity = qty; }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void ServiceUsage::fromString(const string& line) {
    string usageDatestr;
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, tenantID, ',');
    getline(ss, service_ID, ',');
    ss >> quantity;
    ss.ignore(1);
    ss >> status;
    total++;
}

string ServiceUsage::toString() const {
    stringstream ss;
    ss << usage_ID << ',' << room_ID << ',' << tenantID << ',' 
       << service_ID << ',' << quantity << ',' << status;
    return ss.str();
}

// Chuc nang co ban (Basic Function)
void ServiceUsage::addServiceUsage() {
    resetHeader();
    Room::searchRoomByTenantID(Account::currentTenantID);
    string room_ID, service_ID;
    if (Service::serviceList.begin() == NULL) { 
        cout << "None of Service! " << endl;
        return;
    }

    bool found1 = false;
    do {
        resetHeader();
        cout << "Room ID (0 to exit): "; cin >> room_ID;
        if (room_ID == "0") return;
        
        Room* room = Room::roomList.searchID(room_ID);
        if (room != NULL && room->getStatus() == 1) { found1 = true; } 
        else { cout << "Room ID not found or no owner. Please enter again! "<< endl; }
    } while(!found1);
    
    bool found2 = false;
    do {
        resetHeader();
        Service::serviceList.show();
        cout << "Service ID (0 to exit): "; cin >> service_ID;
        if (service_ID == "0") return;

        // Kiểm tra xem dịch vụ này đã được đăng ký chưa
        LinkedList<ServiceUsage>::Node* current = usageList.begin();
        bool serviceAlreadyActive = false;
        while (current) {
            if (current->data.getTenantID() == Account::currentTenantID &&  
                current->data.getRoomID() == room_ID &&
                current->data.getServiceID() == service_ID) {
                if (current->data.getStatus() == true) {
                    cout << "This service is already active for your account!" << endl;
                    serviceAlreadyActive = true;
                    break;
                } else {
                    // Nếu dịch vụ đã bị hủy, cập nhật trạng thái thành active
                    current->data.setStatus(true);
                    cout << "Service usage reactivated successfully!" << endl;
                    return; // Kết thúc hàm sau khi cập nhật
                }
            }
            current = current->next;
        }
        if (serviceAlreadyActive) continue;

        Service* service = Service::serviceList.searchID(service_ID);
        if (service != NULL) {
            if (service->isMandatory()) {
                cout << "This is a mandatory service. You cannot register/unregister it manually." << endl;
                return;
            }
            found2 = true;
        } else {
            cout << "Service ID not found. Please enter again! "<< endl;
        }
    } while(!found2);

    // Nếu không tìm thấy dịch vụ đã tồn tại, tạo mới
    ServiceUsage newUsage(room_ID, service_ID, Account::currentTenantID, true);
    usageList.add(newUsage);
    cout << "Service usage added successfully!" << endl;
    total++;
}

void ServiceUsage::deleteServiceUsage(string& usageID) {
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
    const int w_id = 15, w_room = 15, w_service = 15, w_tenant = 15, w_status = 10, w_qty = 10;
    
    if (!ServiceUsage::is_header_printed) {
        os << left << setw(w_id) << "Usage ID" << " | "
           << setw(w_room) << "Room ID" << " | "
           << setw(w_tenant) << "Tenant ID" << " | "
           << setw(w_service) << "Service ID" << " | "
           << setw(w_qty) << "Quantity" << " | "
           << setw(w_status) << "Status" << endl
           << string(w_id + w_room + w_service + w_tenant + w_qty + w_status + 16, '-') << endl;
        ServiceUsage::is_header_printed = true;
    }
    
    os << left << setw(w_id) << su.usage_ID << " | "
       << setw(w_room) << su.room_ID << " | "
       << setw(w_tenant) << su.tenantID << " | "
       << setw(w_service) << su.service_ID << " | "
       << setw(w_qty) << su.quantity << " | "
       << setw(w_status) << (su.status ? "Active" : "Inactive") << endl;
    return os;
}

void ServiceUsage::stopService() {
    string serviceID, roomID;
    searchByTenantID(Account::currentTenantID);
    cout << "Nhap phong muon tuong tac: "; cin >> roomID;
    cout << "Nhap Service ID muon dung su dung: "; cin >> serviceID;
    
    // Kiểm tra xem dịch vụ có phải là dịch vụ bắt buộc không
    Service* service = Service::serviceList.searchID(serviceID);
    if (service && service->isMandatory()) {
        cout << "Khong the dung dich vu bat buoc!" << endl;
        return;
    }
    
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current) {
        if (current->data.getServiceID() == serviceID && 
            current->data.getTenantID() == Account::currentTenantID &&
            current->data.getRoomID() == roomID &&
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
    searchAll();
}

// Thêm hàm mới
void ServiceUsage::registerServices(const string& roomID, const string& tenantID) {
    LinkedList<Service>::Node* current = Service::serviceList.begin();
    while (current) {
        ServiceUsage newUsage(roomID, current->data.getID(), tenantID, current->data.isMandatory());
        usageList.add(newUsage);
        total++;
        current = current->next;
    }
}

// Thêm các hàm mới vào ServiceUsage class
double ServiceUsage::calculateServiceAmountForRoom(const string& roomID, const string& tenantID, char usageChoice) {
    double serviceAmount = 0;
    for (LinkedList<ServiceUsage>::Node* current = usageList.begin(); current != nullptr; current = current->next) {
        ServiceUsage& usage = current->data;
        if (usage.getStatus() && 
            roomID == usage.getRoomID() && 
            tenantID == usage.getTenantID()) {
            Service* service = Service::serviceList.searchID(usage.getServiceID());
            if (service != nullptr) {
                if (service->getID() == "S.005" || service->getID() == "S.006") {
                    double quantity = (usageChoice == '0') ? 100 : 
                        promptServiceQuantity(service->getName(), roomID);
                    usage.setQuantity(quantity);
                    serviceAmount += service->getUnitPrice() * quantity;
                } else {
                    serviceAmount += service->getUnitPrice();
                }
            }
        }
    }
    return serviceAmount;
}

double ServiceUsage::promptServiceQuantity(const string& serviceName, const string& roomID) {
    double quantity;
    cout << "Nhap so luong " << serviceName << " cho phong " << roomID << ": ";
    cin >> quantity;
    return quantity;
}
