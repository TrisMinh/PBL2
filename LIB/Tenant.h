#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h"  // Đảm bảo có kết nối với lớp LinkedList
using namespace std;

class Tenant {
    string tenant_ID;
    string CCCD;
    string name;
    string phone;
    int age;
public:
    Tenant() {}
    Tenant(const string& id, const string& cccd, const string& n, const string& ph, int a)
        : tenant_ID(id), CCCD(cccd), name(n), phone(ph), age(a) {}

    string getID() const { return tenant_ID; }

    void fromString(const string& line) { // Nhập thông tin từ file
        stringstream ss(line);
        getline(ss, tenant_ID, ',');
        getline(ss, CCCD, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        ss >> age;
    }

    friend ostream& operator<<(ostream& os, const Tenant& t) {
        os << "Tenant [ID: " << t.tenant_ID << ", CCCD: " << t.CCCD
           << ", Name: " << t.name << ", Phone: " << t.phone << ", Age: " << t.age << "]\n";
        return os;
    }

    static void addTenant(LinkedList<Tenant>& tenantList) {
        string tenant_ID, CCCD, name, phone;
        int age;

        // Nhập thông tin cho người thuê mới
        cout << "Nhap thong tin nguoi thue:" << endl;
        cout << "Tenant ID: ";
        cin >> tenant_ID;
        cout << "CCCD: ";
        cin >> CCCD;
        cout << "Name: ";
        cin.ignore(); // Xóa bộ đệm
        getline(cin, name);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Age: ";
        cin >> age;

        Tenant newTenant(tenant_ID, CCCD, name, phone, age); // Tạo đối tượng Tenant mới và thêm vào danh sách
        tenantList.add(newTenant);
        cout << "Tenant Added!!" << endl;
    }

    static void updateTenant(LinkedList<Tenant>& tenantList) {
        string tenantID;
        cout << "Nhap Tenant ID de cap nhat: ";
        cin >> tenantID;

        Tenant* tenant = tenantList.search(tenantID);
        if (tenant) {
            // Nếu tìm thấy người thuê, nhập thông tin mới
            string newCCCD, newName, newPhone;
            int newAge;

            cout << "Cap nhat Tenant ID: " << tenant->getID() << endl;
            cout << "CCCD (nhap moi neu muon thay doi): ";
            cin >> newCCCD;
            cout << "Name (nhap moi neu muon thay doi): ";
            cin.ignore(); // Xóa bộ đệm
            getline(cin, newName);
            cout << "Phone (nhap moi neu muon thay doi): ";
            getline(cin, newPhone);
            cout << "Age (nhap moi neu muon thay doi): ";
            cin >> newAge;

            // Cập nhật thông tin người thuê
            tenant->CCCD = newCCCD;
            tenant->name = newName;
            tenant->phone = newPhone;
            tenant->age = newAge;

            cout << "Tenant updated successfully!" << endl;
        } else {
            cout << "Khong tim thay nguoi thue voi ID: " << tenantID << endl;
        }
    }

    static void showTenantDetails(LinkedList<Tenant>& tenantList) {
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
};

#endif
