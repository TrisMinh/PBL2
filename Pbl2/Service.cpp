#include "Service.h"
#include "ServiceUsage.h"
#include "Room.h"
#include "admin.h"


int Service::total = 0;
int Service::currentNumber = 0;
LinkedList<Service> Service::serviceList;
LinkedList<string> Service::newServiceList;

Service::Service() {}
Service::Service(const string& n, int price, const string& desc, bool mandatory)
    : name(n), unit_price(price), description(desc), is_mandatory(mandatory) {
    service_ID = generateID(++currentNumber);
}
Service::~Service() {}

string Service::getID() const { return service_ID; }
string Service::getName() const { return name; }
double Service::getUnitPrice() const { return unit_price; }
string Service::getdes() const { return description; }
bool Service::getis_mandatory() const{ return is_mandatory; }

string Service::generateID(int number) {
    stringstream ss;
    ss << "S." << setw(3) << setfill('0') << number;
    return ss.str();
}

bool Service::isActive(string& id) {
    LinkedList<ServiceUsage>::Node* uNode = ServiceUsage::usageList.begin();
    while (uNode) {
        if (uNode->data.getServiceID() == id && uNode->data.getStatus() == true ) {
            return true;
        }
        uNode = uNode->next;
    }
    return false;
}

void Service::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, service_ID, ',');
    getline(ss, name, ',');
    ss >> unit_price;
    ss.ignore(1);
    getline(ss, description, ',');
    ss >> is_mandatory;
    total++;
}

string Service::toString() const {
    stringstream ss;
    ss << service_ID << "," << name << "," << unit_price << "," << description << "," << is_mandatory;
    return ss.str();
}

void Service::load(const string& filename) { serviceList.load(filename); }
void Service::updateFile(const string& filename) { serviceList.updateFile(filename); }

void Service::display(Admin* adminWindow) const {
    adminWindow->displayServices(*this);
}

void Service::displayuser(User* adminWindow) const {
    adminWindow->displayServices(*this);
}

void Service::showAllServices(Admin* adminWindow) {
    serviceList.show(adminWindow);
}

void Service::showAllServices(User* adminWindow) {
    serviceList.show(adminWindow);
}

void Service::addNewService(const string& name) {
    newServiceList.add(name);
}

void Service::addService(const string& name, int price, const string& des, bool mandatory) {
    Service service(name, price, des, mandatory);
    serviceList.add(service);
    total++;
    if (mandatory) {
        LinkedList<Room>::Node* currentRoom = Room::roomList.begin();
        while (currentRoom != nullptr) {
            if (currentRoom->data.getStatus() == 1) { // Kiểm tra xem phòng có đang được thuê không
                ServiceUsage newUsage(currentRoom->data.getID(), service.getID(), currentRoom->data.getTenantID(), true);
                ServiceUsage::usageList.add(newUsage);
                cout << "Dich vu bat buoc da duoc them vao phong ID: " << currentRoom->data.getID() << endl;

                Service::addNewService(service.getName());
            }
            currentRoom = currentRoom->next;
        }
    }
    Service::updateFile("Service.txt");
}

void Service::updateService(const string& id, const string& name, int price, const string& des) {
    Service* service = serviceList.searchID(id);
    if (service) {
        service->name = name;
        service->unit_price = price;
        service->description = des;
        Service::updateFile("Service.txt");
    }
}

void Service::deleteService(const string& id) {
    serviceList.deleteNode(id);
    total--;
    Service::updateFile("Service.txt");
}

// void Service::searchByID(const string& id, Admin* adminWindow) {
//     Service* service = serviceList.searchID(id);
//     if (service)
//         adminWindow->displayService(*service);
//     else return;
// }

bool Service::searchByID(const string& id, Admin* adminWindow) {
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    return found;
}

bool Service::searchByID(const string& id, User* adminWindow) {
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.displayuser(adminWindow);
            found = true;
        }
        current = current->next;
    }
    return found;
}

void Service::searchByName(const string& name, Admin* adminWindow) {
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.begin();
    while (current != nullptr) {
        if (current->data.getName().find(name) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void Service::searchByName(const string& name, User* adminWindow) {
    bool found = false;
    LinkedList<Service>::Node* current = serviceList.begin();
    while (current != nullptr) {
        if (current->data.getName().find(name) != string::npos) {
            current->data.displayuser(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void Service::sortID(bool sx){
    serviceList.sortByID(sx);
}