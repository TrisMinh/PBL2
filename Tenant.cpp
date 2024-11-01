#include "Tenant.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Static Element
int Tenant::total = 0;
int Tenant::currentNumber = 0;
LinkedList<Tenant> Tenant::tenantList;

// Constructor
Tenant::Tenant() {}
Tenant::Tenant(const string& name, const string& phone, const string& cccd, int age)
    : name(name), phone(phone), age(age), cccd(cccd) {
    currentNumber++;
    total++;
    tenant_ID = generateID(currentNumber);
}
Tenant::~Tenant() {}

// ID Generate
string Tenant::generateID(int number) {
    stringstream ss;
    ss << "T." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Get functions
string Tenant::getID() const { return tenant_ID; }
string Tenant::getName() const { return name; }
string Tenant::getPhone() const { return phone; }
int Tenant::getAge() const { return age; }
string Tenant::getCCCD() const { return cccd; }

// Set functions
void Tenant::setName(const string& name) { this->name = name; }
void Tenant::setPhone(const string& phone) { this->phone = phone; }
void Tenant::setAge(int age) { this->age = age; }
void Tenant::setCCCD(const string& cccd) { this->cccd = cccd; }

// Load function
void Tenant::load(const string& filename) { tenantList.load(filename); }
void Tenant::updateFile(const string& filename) { tenantList.updateFile(filename); }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void Tenant::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, tenant_ID, ',');
    getline(ss, cccd, ',');
    getline(ss, name, ',');
    getline(ss, phone, ',');
    ss >> age;
    total++;
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Tenant::toString() const {
    stringstream ss;
    ss << tenant_ID << "," << cccd << "," << name << "," << phone << "," << age;
    return ss.str();
}

// Basic Function
void Tenant::addTenant() {
    string name, phone, cccd;
    int age;
    cout << "Nhap ten: "; cin >> name;
    cout << "Nhap so dien thoai: "; cin >> phone;
    cout << "Nhap CCCD: "; cin >> cccd;
    cout << "Nhap tuoi: "; cin >> age;
    Tenant tenant(name, phone, cccd, age);
    tenantList.add(tenant);
    cout << "Them nguoi thue thanh cong voi ID: " << tenant.getID() << endl;
}

void Tenant::updateTenant() {
    string tenantId;
    cout << "Nhap Tenant ID de cap nhat: "; cin >> tenantId;
    Tenant* tenant = tenantList.searchID(tenantId);
    if (tenant) {
        string name, phone, cccd;
        int age;
        cout << "Cap nhat Tenant ID: " << tenant->getID() << endl;
        cout << "Ten: "; cin >> name;
        cout << "So dien thoai: "; cin >> phone;
        cout << "CCCD: "; cin >> cccd;
        cout << "Tuoi: "; cin >> age;
        tenant->setName(name);
        tenant->setPhone(phone);
        tenant->setCCCD(cccd);
        tenant->setAge(age);
        cout << "Cap nhat thong tin nguoi thue thanh cong!" << endl;
    } else {
        cout << "Khong tim thay nguoi thue voi ID: " << tenantId << endl;
    }
}

void Tenant::deleteTenant() {
    string tenantId;
    cout << "Nhap Tenant ID de xoa: "; cin >> tenantId;
    tenantList.deleteNode(tenantId);
    total--;
}

// Search Function
void Tenant::searchByID() {
    string tenantId;
    cout << "Nhap Tenant ID de tim kiem: "; cin >> tenantId;
    Tenant* tenant = tenantList.searchID(tenantId);
    if (tenant) {
        cout << "Da tim thay: " << *tenant << endl;
    } else {
        cout << "Khong tim thay nguoi thue voi ID: " << tenantId << endl;
    }
}

void Tenant::searchByName() {
    string name;
    cout << "Nhap ten can tim kiem: "; cin >> name;
    bool found = false;
    LinkedList<Tenant>::Node* current = tenantList.getHead();
    while (current != nullptr) {
        if (current->data.getName() == name) {
            cout << current->data;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Khong tim thay nguoi thue voi ten: " << name << endl;
    }
}

void Tenant::searchAll() {
    int choice;
    do {
        cout << "Tenant Searching Function: " << endl;
        cout << "1. Search by TenantID" << endl;
        cout << "2. Search by Tenant Name" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your option: "; cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByName(); break;
            case 0: cout << "Exit Search Function." << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (choice != 0);
}

void Tenant::showAllTenants() {
    cout << "Danh sach tat ca nguoi thue:" << endl;
    tenantList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "3. Sap xep theo ten" << endl
         << "0. Thoat!" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: tenantList.sortByID(true); showAllTenants(); break;
        case 2: tenantList.sortByID(false); showAllTenants(); break;
        case 3: tenantList.sortByAlphabet(true); showAllTenants(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Tenant& t) {
    os << left
       << setw(15) << ("Tenant ID: " + t.tenant_ID) << " | "
       << setw(15) << ("Ten: " + t.name) << " | "
       << setw(20) << ("So dien thoai: " + t.phone) << " | "
       << setw(10) << ("Tuoi: " + to_string(t.age)) << " | "
       << setw(15) << ("CCCD: " + t.cccd) << "\n";
    return os;
}

