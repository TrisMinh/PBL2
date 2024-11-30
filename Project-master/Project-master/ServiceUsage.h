#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H

#include "LinkedList.h"
#include "admin.h"
#include "Service.h"
#include <string>

using namespace std;

class ServiceUsage {
    string usage_ID, room_ID, service_ID, tenantID;
    bool status;
    int quantity;
public:
    friend class Admin;
    static int total;
    static int currentNumber;
    static LinkedList<ServiceUsage> usageList;

    ServiceUsage();
    ServiceUsage(const string& roomId, const string& servId, const string& tenantId, bool status);
    ~ServiceUsage();

    static string generateID(int number);
    void setUsageID(const string& id);
    void setRoomID(const string& id);
    void setServiceID(const string& id);
    void setQuantity(int qty);
    void setUsageMonth(int month);
    // Getters
    string getID() const;
    string getRoomID() const;
    string getTenantID() const;
    string getServiceID() const;
    bool getStatus() const;
    int getQuantity() const;
    void setStatus(bool newStatus);
    void display(Admin* adminWindow) const;

    void fromString(const string& line);
    string toString() const;
    static void load(const string& filename);
    static void updateFile(const string& filename);
    friend ostream& operator<<(ostream& os, const ServiceUsage& su);
    static void addServiceUsage(const string& room_ID, const string& serID, int quantity, const QDate& qdate);
    static void updateServiceUsage();
    static void deleteServiceUsage();
    static void showAllServiceUsages(Admin* adminWindow);
    static double calculateServiceAmountForRoom(const string& roomID, const string& tenantID);
    static void  enterquantity(const string& roomID, int e, int w);

    static void searchByID(const string& id, Admin* adminWindow);
    static void searchByRoomID(const string& rid, Admin* adminWindow);
    static void searchAll();
    static void sortID(bool sx);
};

#endif // SERVICEUSAGE_H
