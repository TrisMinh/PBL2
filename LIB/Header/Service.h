#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h" 
using namespace std;
class Service {
    string service_ID;
    string name;
    int unit_price;
    string description;
public:
    Service();
    Service(const string& id, const string& n, int price, const string& desc);
    string getID();
    void fromString(const string& line);
    friend ostream& operator<<(ostream& os, const Service& s);
    static void addService(LinkedList<Service>& serviceList);
    static void updateService(LinkedList<Service>& serviceList);
    static void deleteService(LinkedList<Service>& serviceList);
    static void showServiceDetails(LinkedList<Service>& serviceList);
    static void showAllServices(LinkedList<Service>& serviceList);
};
#endif
