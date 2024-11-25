#include "Service.h"
#include "ServiceUsage.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Static Element
int Service::total = 0;
int Service::currentNumber = 0;
LinkedList<Service> Service::serviceList;
bool Service::is_header_printed = false;
void Service::resetHeader() { is_header_printed = false; }

// Constructor
Service::Service() {}
Service::Service(const string& n, int price, const string& desc)
    : name(n), unit_price(price), description(desc) {
    service_ID = generateID(++currentNumber);
}
Service::~Service() {}

bool Service::isActive(string& id) {
    LinkedList<ServiceUsage>::Node* uNode = ServiceUsage::usageList.begin();
    while (uNode) {
        if (uNode->data.getServiceID() == id && uNode->data.getStatus() == true ) {
            cout << "Khong the xoa, dich vu nay dang duoc su dung!" << endl;
            return true;
        }
        uNode = uNode->next;
    }
    return false;
}

// ID Generate
string Service::generateID(int number) {
    stringstream ss;
    ss << "S." << setw(3) << setfill('0') << number;
    return ss.str();
}
// Load function
void Service::load(const string& filename) { serviceList.load(filename); }
void Service::updateFile(const string& filename) { serviceList.updateFile(filename); }


// Get Function
string Service::getID() const { return service_ID; }
string Service::getName() const { return name; }
double Service::getUnitPrice() const { return unit_price; }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void Service::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, service_ID, ',');
    getline(ss, name, ',');
    ss >> unit_price;
    ss.ignore(1);
    getline(ss, description);
    total++;
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Service::toString() const {
    stringstream ss;
    ss << service_ID << "," << name << "," << unit_price << "," << description;
    return ss.str();
}

// Chuc nang co ban (Basic Function)
void Service::addService() {
    string name, description;
    int unit_price;
    cin.ignore();
    cout << "Nhap ten dich vu: "; getline(cin, name);
    cout << "Nhap gia dich vu: "; cin >> unit_price;
    cin.ignore();
    cout << "Nhap mo ta dich vu: "; getline(cin, description);
    Service service(name, unit_price, description);
    serviceList.add(service);
    cout << "Dich vu da duoc them voi ID: " << service.getID() << endl;
    total++;
}

void Service::updateService() {
    string serviceID;
    
    cout << "Danh sach dich vu hien tai:" << endl;
    resetHeader();
    serviceList.show();
    
    cout << "Nhap Service ID de cap nhat: "; cin >> serviceID;
    Service* service = serviceList.searchID(serviceID);
    if (service) {
        string newName, newDescription;
        int newUnitPrice;

        cout << "Cap nhat Service ID: " << service->getID() << endl;
        cin.ignore();
        cout << "Ten dich vu: "; getline(cin, newName);
        cout << "Gia dich vu: "; cin >> newUnitPrice;
        cin.ignore();
        cout << "Mo ta dich vu: "; getline(cin, newDescription);
        service->name = newName;
        service->unit_price = newUnitPrice;
        service->description = newDescription;
        cout << "Cap nhat thong tin dich vu thanh cong!" << endl;
    } else {
        cout << "Khong tim thay dich vu voi ID: " << serviceID << endl;
    }
}

void Service::deleteService() {
    string serviceID;
    cout << "Nhap Service ID de xoa: "; cin >> serviceID;
    if (isActive(serviceID)) { return; }
    else {
        serviceList.deleteNode(serviceID);
        cout << "Xoa dich vu thanh cong!" << endl;
    }
    total--;
}

// Search Function
void Service::searchByID() {
    resetHeader();
    string serviceId;
    cout << "Nhap service ID de tim kiem: "; cin >> serviceId;
    Service* service = serviceList.searchID(serviceId);
    if (service) { cout << "Da tim thay: " << *service; } 
    else { cout << "Khong tim thay dich vu voi ID: " << serviceId << endl; }
}

void Service::searchByName() {
    resetHeader();
    string searchName;
    cout << "Nhap ten dich vu can tim kiem: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.begin();
    while (current != nullptr) {
        if (current->data.getName().find(searchName) != string::npos) {
            cout << current->data;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay dich vu voi ten: " << searchName << endl;
    }
}

void Service::searchAll() {
    resetHeader();
    int choice;
    do {
        cout << "Service Searching Function: " << endl;
        cout << "   1. Search By ServiceID" << endl
             << "   2. Search By Service Name" << endl
             << "   0. Thoat" << endl;
        cout << "Please enter your option: "; cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByName(); break;
            case 0: cout << "Exit Search Function." << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (choice != 0);
}
// Show Function
void Service::showAllServices() {
    resetHeader();
    cout << "Danh sach tat ca cac dich vu:" << endl;
    serviceList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "3. Tim kiem " << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: serviceList.sortByID(true); showAllServices(); break;
        case 2: serviceList.sortByID(false); showAllServices(); break;
        case 3: searchAll(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Service& s) {
    const int width_service_id = 15;
    const int width_name = 20;
    const int width_price = 10;
    const int width_description = 30;

    if (!Service::is_header_printed) {
        os << left
           << setw(width_service_id) << "Service ID" << " | "
           << setw(width_name) << "Service Name" << " | "
           << setw(width_price) << "Price" << " | "
           << setw(width_description) << "Description" << endl;
        os << setfill('-')
           << setw(width_service_id + 2) << ""
           << setw(width_name + 3) << ""
           << setw(width_price + 3) << ""
           << setw(width_description + 3) << ""
           << setfill(' ') << endl;

        Service::is_header_printed = true;
    }

    os << left
       << setw(width_service_id) << s.service_ID << " | "
       << setw(width_name) << s.name << " | "
       << setw(width_price) << fixed << setprecision(2) << s.unit_price << " | "
       << setw(width_description) << s.description
       << endl;

    return os;
}

