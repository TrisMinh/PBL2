#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H
#include <iostream>
#include <string>
#include "LinkedList.h"  
using namespace std;
class ServiceUsage {
    string usage_ID;
    string reservation_ID;
    string service_ID;
    int quantity;
    int usage_month;
public:
    ServiceUsage();
    ServiceUsage(const string& id, const string& resId, const string& servId, int qty, int month);
    string getID();
    void fromString(const string& line);
    friend ostream& operator<<(ostream& os, const ServiceUsage& su);
    static void addServiceUsage(LinkedList<ServiceUsage>& usageList);
    static void searchServiceUsageByID(LinkedList<ServiceUsage>& usageList);
    static void updateServiceUsage(LinkedList<ServiceUsage>& usageList);
    static void deleteServiceUsage(LinkedList<ServiceUsage>& usageList);
    static void showAllServiceUsages(LinkedList<ServiceUsage>& usageList);
};
#endif
