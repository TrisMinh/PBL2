#include "Tenant.h"
Tenant::Tenant() = default;
Tenant::Tenant(const string& id, const string& cccd, const string& n, const string& ph, int a)
    : tenant_ID(id), CCCD(cccd), name(n), phone(ph), age(a) {}
string Tenant::getID() const { return tenant_ID; }
string Tenant::getname() const { return name; }
void Tenant::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, tenant_ID, ',');
    getline(ss, CCCD, ',');
    getline(ss, name, ',');
    getline(ss, phone, ',');
    ss >> age;
}
ostream& operator<<(ostream& os, const Tenant& t) {
    os << "Tenant [ID: " << t.tenant_ID << ", CCCD: " << t.CCCD
       << ", Name: " << t.name << ", Phone: " << t.phone << ", Age: " << t.age << "]\n";
    return os;
}
void Tenant::addTenant(LinkedList<Tenant>& tenantList) {
    string tenant_ID, CCCD, name, phone;
    int age;
    cout << "Nhap thong tin nguoi thue:\nTenant ID: ";
    cin >> tenant_ID;
    cout << "CCCD: ";
    cin >> CCCD;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Age: ";
    cin >> age;
    tenantList.add(Tenant(tenant_ID, CCCD, name, phone, age));
    cout << "Tenant Added!!" << endl;
}
void Tenant::updateTenant(LinkedList<Tenant>& tenantList) {
    string tenantID;
    cout << "Nhap Tenant ID de cap nhat: ";
    cin >> tenantID;
    Tenant* tenant = tenantList.search(tenantID);
    if (tenant) {
        string newCCCD;
        string newName;
        string newPhone;
        int newAge;
        cout << "Cap nhat Tenant ID: " << tenant->getID() << endl;
        cout << "CCCD (nhap moi neu muon thay doi): ";
        cin >> newCCCD;
        cout << "Name (nhap moi neu muon thay doi): ";
        cin.ignore();
        getline(cin, newName);
        cout << "Phone (nhap moi neu muon thay doi): ";
        getline(cin, newPhone);
        cout << "Age (nhap moi neu muon thay doi): ";
        cin >> newAge;
        tenant->CCCD = newCCCD;
        tenant->name = newName;
        tenant->phone = newPhone;
        tenant->age = newAge;
        cout << "Tenant updated successfully!" << endl;
    } else {
        cout << "Khong tim thay nguoi thue voi ID: " << tenantID << endl;
    }
}
void Tenant::deleteTenant(LinkedList<Tenant>& tenantList) {
    string tenant_ID;
    cout << "Nhap Tenant ID de xoa: ";
    cin >> tenant_ID;
    if (tenantList.search(tenant_ID)) {
        tenantList.deleteNode(tenant_ID);
        cout << "Tenant deleted successfully!" << endl;
    } else {
        cout << "Khong tim thay nguoi thue voi ID: " << tenant_ID << endl;
    }
}
void Tenant::showTenantDetails(LinkedList<Tenant>& tenantList) {
    string tenantID;
    cout << "Nhap Tenant ID de xem chi tiet: ";
    cin >> tenantID;
    Tenant* tenant = tenantList.search(tenantID);
    if (tenant) {
        cout << "Chi tiet nguoi thue: " << *tenant << endl;
    } else {
        cout << "Khong tim thay nguoi thue voi ID: " << tenantID << endl;
    }
}
void Tenant::showAllTenants(LinkedList<Tenant>& tenantList) {
    cout << "Danh sach tat ca cac khach thue:" << endl;
    tenantList.show();
    cout << "1.Increase ID Sort\n2.Decrease ID Sort\n3.Increase Alphabet\n4.Decrease Alphabet\n0. Exit!\n";
    int choice;
    cout << "Please select an option: ";
    cin >> choice;
    switch (choice) {
        case 1: tenantList.sortByID(true); break;
        case 2: tenantList.sortByID(false); break;
        case 3: tenantList.sortByAlphabet(true); break;
        case 4: tenantList.sortByAlphabet(false); break;
        default: return; // Early exit if 0 or invalid input
    }
}
