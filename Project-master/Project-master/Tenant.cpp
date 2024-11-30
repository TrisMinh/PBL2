#include "Tenant.h"
#include "Account.h"
#include "admin.h"

int Tenant::total = 0;
int Tenant::currentNumber = 0;
LinkedList<Tenant> Tenant::tenantList;

Tenant::Tenant() {}
Tenant::Tenant(const string& lastName, const string& firstName, const string& phone, const string& cccd, int birthyear, bool gender)
    : lastName(lastName), firstName(firstName), phone(phone), birthyear(birthyear), cccd(cccd), gender(gender) {
    total++;
    tenant_ID = generateID(++currentNumber);
}
Tenant::~Tenant() {}

string Tenant::getID() const { return tenant_ID; }
string Tenant::getLastName() const { return lastName; }
string Tenant::getFirstName() const { return firstName; }
string Tenant::getFullName() const { return lastName + " " + firstName; }
int Tenant::getAge() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return (1900 + ltm->tm_year) - birthyear;
}
string Tenant::getPhone() const { return phone; }
string Tenant::getCCCD() const { return cccd; }
bool Tenant::getGender() const { return gender; }


void Tenant::setLastName(const string& lastName) { this->lastName = lastName; }
void Tenant::setFirstName(const string& firstName) { this->firstName = firstName; }
void Tenant::setPhone(const string& phone) { this->phone = phone; }
void Tenant::setBirthyear(int birthyear) { this->birthyear = birthyear; }
void Tenant::setCCCD(const string& cccd) { this->cccd = cccd; }
void Tenant::setGender(bool gender) { this->gender = gender; }

string Tenant::generateID(int number) {
    stringstream ss;
    ss << "T." << setw(3) << setfill('0') << number;
    return ss.str();
}

void Tenant::updateFile(const string& filename) { tenantList.updateFile(filename); }

void Tenant::showAllTenants(Admin* adminWindow) {
    tenantList.show(adminWindow);
}

void Tenant::load(const string& filename) { tenantList.load(filename); }

void Tenant::display(Admin* adminWindow) const {
    adminWindow->displayTenants(*this);  // Gọi hàm displayRoom của Admin với Room hiện tại
}

// void Tenant::fromString(const string& line) {
//     stringList fields = line.split(',');

//     tenant_ID = fields[0].trimmed();
//     cccd = fields[1].trimmed();
//     name = fields[2].trimmed();
//     phone = fields[3].trimmed();
//     age = fields[4].trimmed().toInt();

//     total++;
// }

void Tenant::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, tenant_ID, ',');
    getline(ss, cccd, ',');
    getline(ss, lastName, ',');
    getline(ss, firstName, ',');
    getline(ss, phone, ',');
    ss >> birthyear;
    ss.ignore();
    ss >> gender;
    total++;
}

string Tenant::toString() const {
    stringstream ss;
    ss << tenant_ID << "," << cccd << "," << lastName << "," << firstName << "," << phone << "," << birthyear << "," << gender;
    return ss.str();
}
void Tenant::updateTenant(const string& tenantId, const string& lastname, const string& firstname, const string& phone, const string& cccd, int birthyear, bool genderInput) {
    string id;
    if (Account::currentTenantID == "Admin") {
        id = tenantId;
    } else {
        id = Account::currentTenantID;
    }
    Tenant* tenant = tenantList.searchID(id);
    tenant->setLastName(lastname);
    tenant->setFirstName(firstname);
    tenant->setPhone(phone);
    tenant->setCCCD(cccd);
    tenant->setBirthyear(birthyear);
    tenant->setGender(genderInput);
    Tenant::updateFile("Tenant.txt");
}

// void Tenant::searchByID(const string& id, Admin* adminWindow) {
//     Tenant* tenant = tenantList.searchID(id);
//     if (tenant)
//         adminWindow->displayTenant(*tenant);
//     else return;
// }
void Tenant::searchByID(const string& id, Admin* adminWindow) {
    bool found = false;
    LinkedList<Tenant>::Node* current = tenantList.begin();
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

// void Tenant::searchByName(const string& name, Admin* adminWindow){
//     tenantList.searchStatus(name, adminWindow);
// }

void Tenant::searchByName(const string& name, Admin* adminWindow) {
    bool found = false;
    LinkedList<Tenant>::Node* current = tenantList.begin();
    while (current != nullptr) {
        string fullName = current->data.getFullName();
        if ( fullName.find(name) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        return;
    }
}

void Tenant::searchByGender(int gender, Admin* adminWindow) {
    LinkedList<Tenant>::Node* current = tenantList.begin();
    while (current != nullptr) {
        if (current->data.getGender() == gender) { current->data.display(adminWindow); }
        current = current->next;
    }
}

void Tenant::sortID(bool sx){
    tenantList.sortByID(sx);
}

void Tenant::sortName(bool sx){
    tenantList.sortByAlphabet(sx);
}
