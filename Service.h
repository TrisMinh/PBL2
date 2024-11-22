#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

class Service {
    string service_ID;
    string name;
    int unit_price;
    string description;
public:
    static int total;
    static int currentNumber;
    static LinkedList<Service> serviceList;
    static bool is_header_printed; 


    Service();
    Service(const string& n, int price, const string& desc);
    ~Service();

    static string generateID(int number);

    string getID() const;
    string getName() const;
    double getUnitPrice() const;
    string getDescription() const;

     // Title control
    static void resetHeader();

    void setName(const string& n);
    void setUnitPrice(int price);
    void setDescription(const string& desc);

    void fromString(const string& line);
    string toString() const;
    
    friend ostream& operator<<(ostream& os, const Service& s);

    static void load(const string& filename);
    static void updateFile(const string& filename);

    static void addService();
    static void updateService();
    static void deleteService();
    static void showAllServices();

    static void searchByID();
    static void searchByName();
    static void searchAll();
};
#include "Service.cpp"
#endif
