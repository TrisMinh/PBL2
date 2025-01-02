#include "ServiceUsage.h"
#include "Account.h"

int ServiceUsage::total = 0;
int ServiceUsage::currentNumber = 0;
LinkedList<ServiceUsage> ServiceUsage::usageList;

// Constructor
ServiceUsage::ServiceUsage() {}
ServiceUsage::ServiceUsage(const string& roomId, const string& servId, const string& tenantId, bool status)
    : room_ID(roomId), service_ID(servId), tenantID(tenantId), status(status), quantity(1) {
    if (servId == "S.005" || servId == "S.006") quantity = 0;
    usage_ID = generateID(++currentNumber);
}
ServiceUsage::~ServiceUsage() {}

// ID Generate
string ServiceUsage::generateID(int number) {
    stringstream ss;
    ss << "SU." << setw(3) << setfill('0') << number;
    return ss.str();
}

string ServiceUsage::getID() const { return usage_ID; }
string ServiceUsage::getRoomID() const { return room_ID; }
string ServiceUsage::getTenantID() const { return tenantID; }
string ServiceUsage::getServiceID() const { return service_ID; }
bool ServiceUsage::getStatus() const { return status; }
void ServiceUsage::setStatus(bool newStatus) { status = newStatus; }
void ServiceUsage::setQuantity(int qty) { quantity = qty; }
int ServiceUsage::getQuantity() const {return quantity;}


void ServiceUsage::load(const string& filename) { usageList.load(filename); }
void ServiceUsage::updateFile(const string& filename) { usageList.updateFile(filename); }

void ServiceUsage::fromString(const string& line) {
    string usageDatestr;
    stringstream ss(line);
    getline(ss, usage_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, tenantID, ',');
    getline(ss, service_ID, ',');
    ss >> quantity;
    ss.ignore(1);
    ss >> status;
    total++;
}


string ServiceUsage::toString() const {
    stringstream ss;
    ss << usage_ID << ',' << room_ID << ',' << tenantID << ','
       << service_ID << ',' << quantity << ',' << status;
    return ss.str();
}

void ServiceUsage::showAllServiceUsages(Admin* adminWindow){
    usageList.show(adminWindow);
}

void ServiceUsage::display(Admin* adminWindow) const {
    adminWindow->displayServiceUsages(*this);
}

// void ServiceUsage::addServiceUsage(const string& room_ID, const string& serID, int quantity, const QDate& qdate){
//     DATE usageDate;
//     usageDate.fromQDate(qdate);
//     ServiceUsage newUsage(room_ID, serID, Account::currentTenantID ,quantity, usageDate);
//     usageList.add(newUsage);
//     total++;
// }

void ServiceUsage::searchByID(const string& id, Admin* adminWindow) {
    bool found = false;
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void ServiceUsage::searchByRoomID(const string& rid, Admin* adminWindow) {
    string roomID;
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    bool found = false;
    while (current) {
        string ID = current->data.room_ID;
        if ( ID.find(rid) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void ServiceUsage::sortID(bool sx){
    usageList.sortByID(sx);
}

double ServiceUsage::calculateServiceAmountForRoom(const string& roomID, const string& tenantID) {
    double serviceAmount = 0;
    for (LinkedList<ServiceUsage>::Node* current = usageList.begin(); current != nullptr; current = current->next) {        
        ServiceUsage& usage = current->data;
        if (roomID == usage.getRoomID() && tenantID == usage.getTenantID()) {
            Service* service = Service::serviceList.searchID(usage.getServiceID());
            if (service != nullptr) {
                if (service->getID() == "S.005" || service->getID() == "S.006") {
                    int quantity = usage.getQuantity();
                    serviceAmount += service->getUnitPrice() * quantity;
                } else {
                    serviceAmount += service->getUnitPrice();
                }
            }
        }
    }
    return serviceAmount;
}

void ServiceUsage::enterquantity(const string& roomID, int e, int w){
    for (LinkedList<ServiceUsage>::Node* current = usageList.begin(); current != nullptr; current = current->next){
        ServiceUsage& usage = current->data;
        if (usage.getRoomID() == roomID){
            if (usage.getServiceID() == "S.005"){
                usage.quantity = e;
            }
            if (usage.getServiceID() == "S.006"){
                usage.quantity = w;
            }
        }
    }
}

void ServiceUsage::addServiceUsage(const string& room_ID, const string& serID) {
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current) {
        if (current->data.getTenantID() == Account::currentTenantID &&
            current->data.getRoomID() == room_ID &&
            current->data.getServiceID() == serID) {
            if (current->data.getStatus() == true) {
                cout << "This service is already active for your account!" << endl;
                break;
            } else {
                current->data.setStatus(true);
                return; // Kết thúc hàm sau khi cập nhật
            }
        }
        current = current->next;
    }
    ServiceUsage newUsage(room_ID, serID, Account::currentTenantID, true);
    usageList.add(newUsage);
    total++;
}

void ServiceUsage::stopService(const string& room_ID, const string& serID) {
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current) {
        if (current->data.getServiceID() == serID &&
            current->data.getTenantID() == Account::currentTenantID &&
            current->data.getRoomID() == room_ID &&
            current->data.getStatus() == true) {
            current->data.setStatus(false);
            return;
        }
        current = current->next;
    }
}

void ServiceUsage::registerServices(const string& roomID, const string& tenantID) {
    LinkedList<Service>::Node* current = Service::serviceList.begin();
    while (current) {
        ServiceUsage newUsage(roomID, current->data.getID(), tenantID, current->data.getis_mandatory());
        usageList.add(newUsage);
        total++;
        current = current->next;
    }
}

void ServiceUsage::deleteServiceUsageByRoomAndTenant(const string& roomID, const string& tenantID) {
    LinkedList<ServiceUsage>::Node* current = usageList.begin();
    while (current != nullptr) {
        if (current->data.getRoomID() == roomID && current->data.getTenantID() == tenantID) {
            LinkedList<ServiceUsage>::Node* toDelete = current;
            current = current->next;
            usageList.deleteNode(toDelete->data.getID());
        } else {
            current = current->next;
        }
    }
}
