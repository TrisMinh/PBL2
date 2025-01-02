#ifndef SERVICEUSAGE_H
#define SERVICEUSAGE_H
#include "Room.h"
#include "Service.h"
#include "Account.h"
#include "Date.h"
#include "Base.h"

using namespace std;
class ServiceUsage {
    string usage_ID, room_ID, service_ID, tenantID;
    bool status;
    int quantity;
public:
    static int total;
    static int currentNumber;
    static LinkedList<ServiceUsage> usageList;
    static bool is_header_printed; 

    ServiceUsage();
    ServiceUsage(const string& roomId, const string& servId, const string& tenantId, bool status = true);
    ~ServiceUsage();

    static string generateID(int number);
    void setUsageID(const string& id);
    void setRoomID(const string& id);
    void setServiceID(const string& id);
    void setQuantity(int qty);
    // Getters
    string getID() const;
    string getRoomID() const;
    string getTenantID() const;
    string getServiceID() const;
    bool getStatus() const;
    void setStatus(bool newStatus);
    int getQuantity() const;

    void fromString(const string& line);
    string toString() const;
    static void load(const string& filename);
    static void updateFile(const string& filename);
    friend ostream& operator<<(ostream& os, const ServiceUsage& su);
    static void addServiceUsage();
    static void updateServiceUsage();
    static void deleteServiceUsage(string& usageID);
    static void showAllServiceUsages();
    static void stopService();

    static void searchByID();
    static void searchByRoomID();
    static void searchAll();
    static void searchByTenantID(string tenantID);

    // Title control
    static void resetHeader();
    // Trí đã sửa hàm này 3/12/2024 -> chỉnh xong qua contract chỉnh lại tên hàm này trong confirm là được
    static void registerServices(const string& roomID, const string& tenantID);

    static double calculateServiceAmountForRoom(const string& roomID, const string& tenantID, char usageChoice);

    static double promptServiceQuantity(const string& serviceName, const string& roomID);

    static void deleteServiceUsageByRoomAndTenant(const string& roomID, const string& tenantID);
};
#include "ServiceUsage.cpp"
#endif
