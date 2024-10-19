#include "ServiceUsage.h"
#include <sstream>
ServiceUsage::ServiceUsage() {}
ServiceUsage::ServiceUsage(const string& id, const string& resId, const string& servId, int qty, int month)
    : usage_ID(id), reservation_ID(resId), service_ID(servId), quantity(qty), usage_month(month) {}
string ServiceUsage::getID() {
    return usage_ID;
}
void ServiceUsage::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, reservation_ID, ',');
    getline(ss, service_ID, ',');
    ss >> quantity;
    ss.ignore(1);
    ss >> usage_month;
}
ostream& operator<<(ostream& os, const ServiceUsage& su) {
    os << "ServiceUsage [ID: " << su.usage_ID << ", Reservation ID: " << su.reservation_ID
       << ", Service ID: " << su.service_ID << ", Quantity: " << su.quantity
       << ", Usage Month: " << su.usage_month << "]\n";
    return os;
}
void ServiceUsage::addServiceUsage(LinkedList<ServiceUsage>& usageList) {
    string usage_ID, reservation_ID, service_ID;
    int quantity, usage_month;
    cout << "Nhap thong tin su dung dich vu:" << endl;
    cout << "Usage ID: "; cin >> usage_ID;
    cout << "Reservation ID: "; cin >> reservation_ID;
    cout << "Service ID: "; cin >> service_ID;
    cout << "Quantity: "; cin >> quantity;
    cout << "Usage Month: "; cin >> usage_month;
    ServiceUsage newUsage(usage_ID, reservation_ID, service_ID, quantity, usage_month);
    usageList.add(newUsage);
    cout << "Service usage added successfully!" << endl;
}
void ServiceUsage::searchServiceUsageByID(LinkedList<ServiceUsage>& usageList) {
    string usageID;
    cout << "Nhap Usage ID de tim kiem: ";
    cin >> usageID;
    ServiceUsage* usage = usageList.search(usageID);
    if (usage) {
        cout << "Da tim thay: " << *usage << endl;
    } else {
        cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl;
    }
}
void ServiceUsage::updateServiceUsage(LinkedList<ServiceUsage>& usageList) {
    string usageID;
    cout << "Nhap Usage ID de cap nhat: ";
    cin >> usageID;
    ServiceUsage* usage = usageList.search(usageID);
    if (usage) {
        string newReservationID, newServiceID;
        int newQuantity, newUsageMonth;
        cout << "Cap nhat Usage ID: " << usage->usage_ID << endl;
        cout << "Reservation ID (nhap moi neu muon thay doi): ";
        cin >> newReservationID;
        cout << "Service ID (nhap moi neu muon thay doi): ";
        cin >> newServiceID;
        cout << "Quantity: ";
        cin >> newQuantity;
        cout << "Usage Month: ";
        cin >> newUsageMonth;
        usage->reservation_ID = newReservationID;
        usage->service_ID = newServiceID;
        usage->quantity = newQuantity;
        usage->usage_month = newUsageMonth;
        cout << "Service usage updated successfully!" << endl;
    } else {
        cout << "Khong tim thay su dung dich vu voi ID: " << usageID << endl;
    }
}
void ServiceUsage::deleteServiceUsage(LinkedList<ServiceUsage>& usageList) {
    string usageID;
    cout << "Nhap Usage ID de xoa: ";
    cin >> usageID;
    usageList.deleteNode(usageID);
    cout << "Service usage deleted successfully!" << endl;
}
void ServiceUsage::showAllServiceUsages(LinkedList<ServiceUsage>& usageList) {
    cout << "Danh sach tat ca cac su dung dich vu:" << endl;
    usageList.show();
}
