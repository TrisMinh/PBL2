#include "Service.h"
#include "admin.h"


int Service::total = 0;
int Service::currentNumber = 0;
LinkedList<Service> Service::serviceList;

Service::Service() {}
Service::Service(const string& n, int price, const string& desc)
    : name(n), unit_price(price), description(desc) {
    currentNumber++;
    service_ID = generateID(currentNumber);
}
Service::~Service() {}

string Service::getID() const { return service_ID; }
string Service::getName() const { return name; }
double Service::getUnitPrice() const { return unit_price; }

string Service::generateID(int number) {
    stringstream ss;
    ss << "S." << setw(3) << setfill('0') << number;
    return ss.str();
}

void Service::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, service_ID, ',');
    getline(ss, name, ',');
    ss >> unit_price;
    ss.ignore(1);
    getline(ss, description);
    total++;
}

string Service::toString() const {
    stringstream ss;
    ss << service_ID << "," << name << "," << unit_price << "," << description;
    return ss.str();
}

void Service::load(const string& filename) { serviceList.load(filename); }
void Service::updateFile(const string& filename) { serviceList.updateFile(filename); }

void Service::display(Admin* adminWindow) const {
    adminWindow->displayServices(*this);
}

void Service::showAllServices(Admin* adminWindow) {
    serviceList.show(adminWindow);
}

void Service::addService(const string& name, int price, const string& des) {
    Service service(name, price, des);
    serviceList.add(service);
    total++;
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

void Service::sortID(bool sx){
    serviceList.sortByID(sx);
}
