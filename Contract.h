#ifndef CONTRACT_H
#define CONTRACT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Account.h"
#include "Date.h"
#include "Tenant.h"
#include "Reservation.h"
#include "LinkedList.h"

using namespace std;

class Contract : public Reservation {
private:
    string contractID;       // ID hợp đồng 
    double rentprice;   
    bool status;
public:
    static int currentNumber; // Số lượng hợp đồng hiện tại
    static int total;         // Tổng số hợp đồng
    static LinkedList<Contract> contractList; // Danh sách hợp đồng
    static bool is_header_printed;

    Contract();
    Contract(const string& roomID,const string& tenantID,
            const DATE& start,const DATE& end, int status);

    // Destructor
    ~Contract();

    // Generate contract ID
    static string generateID(int number);

    // Getters
    string getID() const;
    bool getStatus() const;
    DATE getStartDate() const ;
    DATE getEndDate() const ;
    double getPrice() const; // Getter cho giá tiền

    // Setters
    void setStartDate(const DATE& startDate);
    void setEndDate(const DATE& endDate);
    void setPrice(double price);
    void setStatus(bool status);

    // Convert contract to string
    string toString() const;

    // Convert string to contract
    void fromString(const string& line);

    // Load contracts from file
    static void load(const string& filename);
    static void updateFile(const string& filename);

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const Contract& c);

    // Manage contracts
    static void autoadd();
    static void addContract(const string& roomID, const string& tenantID,
                            const DATE& start, const DATE& end, int status);
    static void editContract();
    static void deleteContract();
    static void extensionContract();
    static void showAllContracts();

    // Search
    static Contract* searchByRidAndTid(const string& rid, const string& tid);
    static void searchByTenantID(const string& id);
    static void confirmReservationandcreatContract();

    static void resetHeader() { is_header_printed = false; }
};

#include "Contract.cpp"
#endif
