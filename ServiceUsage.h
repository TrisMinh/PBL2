#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;
class ServiceUsage {
    string usage_ID;
    string room_ID;
    string service_ID;
    int quantity;
    int usage_month;
public:
    static int total;
    static int currentNumber;
    static LinkedList<ServiceUsage> usageList;

    ServiceUsage();
    ServiceUsage(const string& resId, const string& servId, int qty, int month);

    static string generateID(int number);
    void setUsageID(const string& id);
    void setRoomID(const string& id);
    void setServiceID(const string& id);
    void setQuantity(int qty);
    void setUsageMonth(int month);
    // Getters
    string getID() const;
    string getRoomID() const;
    string getServiceID() const;
    int getQuantity() const;
    int getUsageMonth() const;

    void fromString(const string& line);
    string toString() const;
    static void load(const string& filename);
    static void updateFile(const string& filename);
    friend ostream& operator<<(ostream& os, const ServiceUsage& su);
    static void addServiceUsage();
    static void updateServiceUsage();
    static void deleteServiceUsage();
    static void showAllServiceUsages();

    static void searchByID();
    static void searchByRoomID();
    static void searchAll();
};
#include "ServiceUsage.cpp"
#endif
