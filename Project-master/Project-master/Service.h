#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "LinkedList.h"
#include "admin.h"

class Admin;

class Service
{
    string service_ID;
    string name;
    int unit_price;
    string description;

public:
    friend class Admin;
    static int total;
    static int currentNumber;
    static LinkedList<Service> serviceList;

    Service();
    Service(const string& n, int price, const string& desc);
    ~Service();

    void fromString(const string& line);
    string getID() const;
    string getName() const;
    double getUnitPrice() const;

    static string generateID(int number);
    string toString() const;
    void display(Admin* adminWindow) const;

    static void load(const string& filename);
    static void updateFile(const string& filename);
    static void addService(const string& name, int price, const string& des);
    static void updateService(const string& id, const string& name, int price, const string& des);
    static void deleteService(const string& id);
    static void showAllServices(Admin* adminWindow);
    static bool searchByID(const string& id, Admin* adminWindow);
    static void searchByName(const string& name, Admin* adminWindow);
    static void sortID(bool sx);
};

#endif // SERVICE_H
