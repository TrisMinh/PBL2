#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h" // Đảm bảo bạn đã bao gồm LinkedList
using namespace std;

class Service {
    string service_ID;
    string name;
    int unit_price;
    string description;
public:
    Service() {}
    Service(const string& id, const string& n, int price, const string& desc)
        : service_ID(id), name(n), unit_price(price), description(desc) {}
    string getID() {return service_ID;}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, service_ID, ',');
        getline(ss, name, ',');
        ss >> unit_price;
        ss.ignore(1);
        getline(ss, description, ',');
    }

    friend ostream& operator<<(ostream& os, const Service& s) {
        os << "Service [ID: " << s.service_ID << ", Name: " << s.name
           << ", Unit Price: " << s.unit_price << ", Description: " << s.description << "]\n";
        return os;
    }

    static void addService(LinkedList<Service>& serviceList) {
        string service_ID, name, description;
        int unit_price;

        cout << "Nhap thong tin dich vu:" << endl;
        cout << "Service ID: ";
        cin >> service_ID;
        cout << "Name: ";
        cin.ignore(); // Xóa bộ đệm
        getline(cin, name);
        cout << "Unit Price: ";
        cin >> unit_price;
        cout << "Description: ";
        cin.ignore(); // Xóa bộ đệm
        getline(cin, description);

        Service newService(service_ID, name, unit_price, description);
        serviceList.add(newService);
        cout << "Service Added!!" << endl;
    }

    static void updateService(LinkedList<Service>& serviceList) {
        string serviceID;
        cout << "Nhap Service ID de cap nhat: ";
        cin >> serviceID;

        Service* service = serviceList.search(serviceID);
        if (service) {
            string newName, newDescription;
            int newUnitPrice;

            cout << "Cap nhat Service ID: " << service->service_ID << endl;
            cout << "Name (nhap moi neu muon thay doi): ";
            cin.ignore(); // Xóa bộ đệm
            getline(cin, newName);
            cout << "Unit Price (nhap moi neu muon thay doi): ";
            cin >> newUnitPrice;
            cout << "Description (nhap moi neu muon thay doi): ";
            cin.ignore(); // Xóa bộ đệm
            getline(cin, newDescription);

            // Cập nhật thông tin dịch vụ
            service->name = newName;
            service->unit_price = newUnitPrice;
            service->description = newDescription;

            cout << "Service updated successfully!" << endl;
        } else {
            cout << "Khong tim thay dich vu voi ID: " << serviceID << endl;
        }
    }

    static void deleteService(LinkedList<Service>& serviceList) {
        string serviceID;
        cout << "Nhap Service ID de xoa: ";
        cin >> serviceID;

        serviceList.deleteNode(serviceID); // Gọi hàm deleteNode từ LinkedList
        cout << "Service deleted successfully!" << endl;
    }

    static void showServiceDetails(LinkedList<Service>& serviceList) {
        string serviceID;
        cout << "Nhap Service ID de xem chi tiet: ";
        cin >> serviceID;

        Service* service = serviceList.search(serviceID);
        if (service) {
            cout << "Chi tiet dich vu: " << *service << endl;
        } else {
            cout << "Khong tim thay dich vu voi ID: " << serviceID << endl;
        }
    }

    static void showAllServices(LinkedList<Service>& serviceList) {
        cout << "Danh sach tat ca cac dich vu:" << endl;
        serviceList.show(); 
    }
};

#endif
