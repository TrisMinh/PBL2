#include "Tenant.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int Tenant::total = 0;
int Tenant::currentNumber = 0;
LinkedList<Tenant> Tenant::tenantList;

Tenant::Tenant() {}
Tenant::Tenant(const string& name, const string& phone, const string& cccd, int age)
    : name(name), phone(phone), age(age), cccd(cccd) {
    currentNumber++; 
    total++;
    tenant_ID = generateID(currentNumber);
}

Tenant::~Tenant() {}

string Tenant::generateID(int number) {
    stringstream ss;
    ss << "T." << setw(3) << setfill('0') << number;
    return ss.str();
}

string Tenant::getID() const { return tenant_ID; }
string Tenant::getName() const { return name; }
string Tenant::getPhone() const { return phone; }
int Tenant::getAge() const { return age; }
string Tenant::getCCCD() const { return cccd; }

void Tenant::setName(const string& name) { this->name = name; }
void Tenant::setPhone(const string& phone) { this->phone = phone; }
void Tenant::setAge(int age) { this->age = age; }
void Tenant::setCCCD(const string& cccd) { this->cccd = cccd; }

void Tenant::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, tenant_ID, ',');
    getline(ss, cccd, ',');
    getline(ss, name, ',');
    getline(ss, phone, ',');
    ss >> age;
    total++;
}

string Tenant::toString() const {
    stringstream ss;
    ss << tenant_ID << "," << cccd << "," << name << "," << phone << "," << age;
    return ss.str();
}

void Tenant::load(const string& filename) {
    tenantList.load(filename);
}

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
    cout << "Nhap ten can tim kiem: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    typename LinkedList<Tenant>::Node* current = tenantList.getHead();

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
        cout << "   1. Search by ID" << endl
             << "   2. Search by Name" << endl
             << "   0. Exit" << endl;
        cout << "Please enter your choice: "; cin >> choice;
        
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByName(); break;
            case 0: cout << "Exiting search menu." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 0);
}

void Tenant::updateTenant() {
    string tenantId;
    cout << "Nhap Tenant ID de cap nhat: "; cin >> tenantId;

    Tenant* tenant = tenantList.searchID(tenantId);
    if (tenant) {
        string name, phone, cccd;
        int age;

        cout << "Cap nhat Tenant ID: " << tenant->getID() << endl;
        cout << "Ten (nhap moi neu muon thay doi): "; cin >> name;
        cout << "So dien thoai (nhap moi neu muon thay doi): "; cin >> phone;
        cout << "CCCD (nhap moi neu muon thay doi): "; cin >> cccd;
        cout << "Tuoi (nhap moi neu muon thay doi): "; cin >> age;

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
    cout << "Xoa nguoi thue thanh cong!" << endl;
    total--;
}

void Tenant::showAllTenants() {
    cout << "Danh sach tat ca nguoi thue:" << endl;
    tenantList.show();
    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "3. Sap xep theo ten" << endl
         << "0. Thoat!" << endl;

    int choice;
    cout << "Vui long chon mot lua chon: "; cin >> choice;
    
    switch (choice) {
        case 1: tenantList.sortByID(true); showAllTenants(); break;
        case 2: tenantList.sortByID(false); showAllTenants(); break;
        case 3: tenantList.sortByAlphabet(true); showAllTenants(); break;
        default: break;
    }
}

ostream& operator<<(ostream& os, const Tenant& t) {
    os << left
       << setw(15) << ("Tenant ID: " + t.tenant_ID) << " | "
       << setw(15) << ("Ten: " + t.name) << " | "
       << setw(20) << ("So dien thoai: " + t.phone) << " | "
       << setw(10) << ("Tuoi: " + to_string(t.age)) << " | "
       << setw(15) << ("CCCD: " + t.cccd) << "\n";
    return os;
}

void Tenant::updateFile(const string& filename) {
    tenantList.updateFile(filename);
}
