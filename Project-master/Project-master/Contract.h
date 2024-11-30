#ifndef CONTRACT_H
#define CONTRACT_H

#include "Reservation.h"

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
    double getrentprice() const;

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

    // Manage contracts
    static void autoadd();
    static void addContract(const string& roomID, const string& tenantID,
                            const DATE& start, const DATE& end, int status);
    static void editContract();
    static void deleteContract();
    static void extensionContract();
    static void showAllContracts(Admin* adminWindow);

    // Search
    static Contract* searchByRidAndTid(const string& rid, const string& tid);
    static void searchByTenantID(const string& id);
    static void confirmReservationandcreatContract(int choice, const string& tempRE);
    static void sortID(bool sx);
    void display(Admin* adminWindow) const;
};

#endif // CONTRACT_H
