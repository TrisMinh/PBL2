#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Room.h"
#include "Service.h"
#include "LinkedList.h"
#include "Account.h"
#include "Date.h"
using namespace std;
class ServiceUsage {
    string usage_ID, room_ID, service_ID, tenantID;
    int quantity;
    DATE usageDate;
    bool status;
public:
    static int total;
    static int currentNumber;
    static LinkedList<ServiceUsage> usageList;

    ServiceUsage();
    ServiceUsage(const string& roomId, const string& servId, const string& tenantId, int qty, DATE date,bool status = true);
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
    int getQuantity() const;
    int getUsageMonth() const;
    int getUsageYear() const;
    bool getStatus() const;
    void setStatus(bool newStatus);

    void fromString(const string& line);
    string toString() const;
    static void load(const string& filename);
    static void updateFile(const string& filename);
    friend ostream& operator<<(ostream& os, const ServiceUsage& su);
    static void addServiceUsage();
    static void updateServiceUsage();
    static void deleteServiceUsage();
    static void showAllServiceUsages();
    static void stopService();

    static void searchByID();
    static void searchByRoomID();
    static void searchAll();
    static void searchByTenantID(string tenantID);
};
#include "ServiceUsage.cpp"
#endif
