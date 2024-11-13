#include "Service.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// Static Element
int Service::total = 0;
int Service::currentNumber = 0;
LinkedList<Service> Service::serviceList;

// Constructor
Service::Service() {}
Service::Service(const string& n, int price, const string& desc)
    : name(n), unit_price(price), description(desc) {
    currentNumber++;
    service_ID = generateID(currentNumber);
}
Service::~Service() {}

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
    cout << "Nhap ten dich vu: "; cin >> name;
    cout << "Nhap gia dich vu: "; cin >> unit_price;
    cout << "Nhap mo ta dich vu: "; cin >> description;
    Service service(name, unit_price, description);
    serviceList.add(service);
    cout << "Dich vu da duoc them voi ID: " << service.getID() << endl;
    total++;
}

void Service::updateService() {
    string serviceID;
    cout << "Nhap Service ID de cap nhat: "; cin >> serviceID;
    Service* service = serviceList.searchID(serviceID);
    if (service) {
        string newName, newDescription;
        int newUnitPrice;

        cout << "Cap nhat Service ID: " << service->getID() << endl;
        cout << "Ten (nhap moi neu muon thay doi): "; cin >> newName;
        cout << "Gia (nhap moi neu muon thay doi): "; cin >> newUnitPrice;
        cout << "Mo ta (nhap moi neu muon thay doi): "; cin >> newDescription;
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
    serviceList.deleteNode(serviceID);
    total--;
}

// Search Function
void Service::searchByID() {
    string serviceId;
    cout << "Nhap service ID de tim kiem: "; cin >> serviceId;
    Service* service = serviceList.searchID(serviceId);
    if (service) { cout << "Da tim thay: " << *service; } 
    else { cout << "Khong tim thay dich vu voi ID: " << serviceId << endl; }
}

void Service::searchByName() {
    string name;
    cout << "Nhap ten dich vu can tim kiem: "; cin >> name;
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.getHead();
    while (current != nullptr) {
        if (current->data.getName() == name) {
            cout << current->data;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong tim thay dich vu voi ten: " << name << endl;
    }
}

void Service::searchAll() {
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
    cout << "Danh sach tat ca cac dich vu:" << endl;
    serviceList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: serviceList.sortByID(true); showAllServices(); break;
        case 2: serviceList.sortByID(false); showAllServices(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Service& s) {
    // Định nghĩa độ rộng cho từng cột
    const int width_service_id = 15;
    const int width_name = 20;
    const int width_price = 10;
    const int width_description = 30;

    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_service_id) << "Service ID" << " | "
           << setw(width_name) << "Service Name" << " | "
           << setw(width_price) << "Price" << " | "
           << setw(width_description) << "Description"
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_service_id + 2) << ""
           << setw(width_name + 3) << ""
           << setw(width_price + 3) << ""
           << setw(width_description + 3) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In dữ liệu Service
    os << left
       << setw(width_service_id) << s.service_ID << " | "
       << setw(width_name) << s.name << " | "
       << setw(width_price) << fixed << setprecision(2) << s.unit_price << " | "
       << setw(width_description) << s.description
       << endl;

    return os;
}

