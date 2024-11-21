#include "Tenant.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Static Element
int Tenant::total = 0;
int Tenant::currentNumber = 0;
LinkedList<Tenant> Tenant::tenantList;

// Constructor
Tenant::Tenant() {}
Tenant::Tenant(const string& name, const string& phone, const string& cccd, int birthyear, bool gender)
    : name(name), phone(phone), birthyear(birthyear), cccd(cccd), gender(gender) {
    total++;
    tenant_ID = generateID(++currentNumber);
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
int Tenant::getBirthyear() const { return birthyear; }
string Tenant::getCCCD() const { return cccd; }
int Tenant::getAge() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return (1900 + ltm->tm_year) - birthyear;
}
bool Tenant::getGender() const { return gender; }

// Set functions
void Tenant::setName(const string& name) { this->name = name; }
void Tenant::setPhone(const string& phone) { this->phone = phone; }
void Tenant::setBirthyear(int birthyear) { this->birthyear = birthyear; }
void Tenant::setCCCD(const string& cccd) { this->cccd = cccd; }
void Tenant::setGender(bool gender) { this->gender = gender; }

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
    ss >> birthyear;
    ss.ignore();
    ss >> gender;
    total++;
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Tenant::toString() const {
    stringstream ss;
    ss << tenant_ID << "," << cccd << "," << name << "," << phone << "," << birthyear << "," << gender;
    return ss.str();
}

// Basic Function
void Tenant::addTenant() {
    string name, phone, cccd;
    int birthyear;
    int genderInput;
    cout << "Nhap ten: "; cin >> name;
    cout << "Nhap so dien thoai: "; cin >> phone;
    cout << "Nhap CCCD: "; cin >> cccd;
    cout << "Nhap nam sinh: "; cin >> birthyear;
    cout << "Nhap gioi tinh (0: Nam, 1: Nu): "; cin >> genderInput;
    Tenant tenant(name, phone, cccd, birthyear, genderInput);
    tenant.setGender(genderInput == 1);
    tenantList.add(tenant);
    cout << "Them nguoi thue thanh cong voi ID: " << tenant.getID() << endl;
}

void Tenant::updateTenant() {
    string tenantId;
    cout << "Nhap Tenant ID de cap nhat: "; cin >> tenantId;
    Tenant* tenant = tenantList.searchID(tenantId);
    if (tenant) {
        string name, phone, cccd;
        int birthyear;
        int genderInput;
        cout << "Cap nhat Tenant ID: " << tenant->getID() << endl;
        cout << "Ten: "; cin >> name;
        cout << "So dien thoai: "; cin >> phone;
        cout << "CCCD: "; cin >> cccd;
        cout << "Nam sinh: "; cin >> birthyear;
        cout << "Nhap gioi tinh (0: Nam, 1: Nu): "; cin >> genderInput;
        tenant->setName(name);
        tenant->setPhone(phone);
        tenant->setCCCD(cccd);
        tenant->setBirthyear(birthyear);
        tenant->setGender(genderInput);
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
    LinkedList<Tenant>::Node* current = tenantList.begin();
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
    // Định nghĩa độ rộng cho từng cột
    const int width_tenant_id = 15;
    const int width_name = 20;
    const int width_phone = 20;
    const int width_age = 10;
    const int width_cccd = 15;
    const int width_gender = 10;

    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_name) << "Name" << " | "
           << setw(width_phone) << "Phone" << " | "
           << setw(width_age) << "Age" << " | "
           << setw(width_cccd) << "CCCD" << " | "
           << setw(width_gender) << "Gender"
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_tenant_id + 2) << ""
           << setw(width_name + 3) << ""
           << setw(width_phone + 3) << ""
           << setw(width_age + 3) << ""
           << setw(width_cccd + 1) << ""
           << setw(width_gender + 1) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In dữ liệu Tenant
    os << left
       << setw(width_tenant_id) << t.tenant_ID << " | "
       << setw(width_name) << t.name << " | "
       << setw(width_phone) << t.phone << " | "
       << setw(width_age) << to_string(t.getAge()) << " | "
       << setw(width_cccd) << t.cccd << " | "
       << setw(width_gender) << (t.gender ? "Nu" : "Nam")
       << endl;

    return os;
}


