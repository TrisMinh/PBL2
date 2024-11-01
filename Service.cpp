#include "Service.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int Service::total = 0;
int Service::currentNumber = 0;
LinkedList<Service> Service::serviceList;

// Constructor mặc định và có tham số
Service::Service() {}
Service::Service(const string& n, int price, const string& desc)
    : name(n), unit_price(price), description(desc) {
    total++;
    currentNumber++;
    service_ID = generateID(currentNumber);
}

// Hàm tạo ID tự động cho Service
string Service::generateID(int number) {
    stringstream ss;
    ss << "S." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Các hàm getter
string Service::getID() const { return service_ID; }
string Service::getName() const { return name; }

// Phương thức chuyển đổi `Service` thành chuỗi CSV
string Service::toString() const {
    stringstream ss;
    ss << service_ID << "," << name << "," << unit_price << "," << description;
    return ss.str();
}

// Phương thức đọc thông tin `Service` từ chuỗi CSV
void Service::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, service_ID, ',');
    getline(ss, name, ',');
    ss >> unit_price;
    ss.ignore(1);
    getline(ss, description);
    total++;
}

// Thêm dịch vụ mới
void Service::addService() {
    string name, description;
    int unit_price;

    cout << "Nhap ten dich vu: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gia dich vu: ";
    cin >> unit_price;
    cout << "Nhap mo ta dich vu: ";
    cin.ignore();
    getline(cin, description);

    Service service(name, unit_price, description);
    serviceList.add(service);
    cout << "Dich vu da duoc them voi ID: " << service.getID() << endl;
}

// Cập nhật dịch vụ
void Service::updateService() {
    string serviceID;
    cout << "Nhap Service ID de cap nhat: ";
    cin >> serviceID;

    Service* service = serviceList.searchID(serviceID);
    if (service) {
        string newName, newDescription;
        int newUnitPrice;

        cout << "Cap nhat Service ID: " << service->getID() << endl;
        cout << "Ten (nhap moi neu muon thay doi): ";
        cin.ignore();
        getline(cin, newName);
        cout << "Gia (nhap moi neu muon thay doi): ";
        cin >> newUnitPrice;
        cout << "Mo ta (nhap moi neu muon thay doi): ";
        cin.ignore();
        getline(cin, newDescription);

        service->name = newName;
        service->unit_price = newUnitPrice;
        service->description = newDescription;
        cout << "Cap nhat thong tin dich vu thanh cong!" << endl;
    } else {
        cout << "Khong tim thay dich vu voi ID: " << serviceID << endl;
    }
}

// Xóa dịch vụ
void Service::deleteService() {
    string serviceID;
    cout << "Nhap Service ID de xoa: ";
    cin >> serviceID;
    serviceList.deleteNode(serviceID);
    total--;
}

// Hiển thị danh sách tất cả dịch vụ
void Service::showAllServices() {
    cout << "Danh sach tat ca cac dich vu:" << endl;
    serviceList.show();
    
    int choice;
    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "0. Thoat!" << endl;
    cout << "Vui long chon mot lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1: serviceList.sortByID(true); showAllServices(); break;
        case 2: serviceList.sortByID(false); showAllServices(); break;
        default: break;
    }
}

// Tìm kiếm dịch vụ theo ID
void Service::searchByID() {
    string serviceId;
    cout << "Nhap service ID de tim kiem: ";
    cin >> serviceId;

    Service* service = serviceList.searchID(serviceId);
    if (service) {
        cout << "Da tim thay: " << *service;
    } else {
        cout << "Khong tim thay dich vu voi ID: " << serviceId << endl;
    }
}

// Tìm kiếm dịch vụ theo tên
void Service::searchByName() {
    string name;
    cout << "Nhap ten dich vu can tim kiem: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    typename LinkedList<Service>::Node* current = serviceList.getHead();

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

// Tìm kiếm tổng hợp
void Service::searchAll() {
    int choice;
    do {
        cout << "   1. Tim kiem theo ID" << endl
             << "   2. Tim kiem theo ten" << endl
             << "   0. Thoat" << endl;
        cout << "Vui long chon mot lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByName(); break;
            case 0: cout << "Thoat menu tim kiem." << endl; break;
            default: cout << "Lua chon khong hop le. Thu lai." << endl; break;
        }
    } while (choice != 0);
}

// Hàm xuất dịch vụ
ostream& operator<<(ostream& os, const Service& s) {
    os << left
       << setw(15) << ("Service ID: " + s.service_ID) << " | "
       << setw(15) << ("Ten dich vu: " + s.name) << " | "
       << setw(10) << ("Gia: " + to_string(s.unit_price)) << " | "
       << setw(30) << ("Mo ta: " + s.description) << "\n";
    return os;
}

void Service::load(const string& filename) {
    serviceList.load(filename);
}
void Service::updateFile(const string& filename) {
    serviceList.updateFile(filename);
}

