#include "Account.h"
#include "Tenant.h"

int Account::total = 0;
int Account::currentNumber = 0;
string Account::currentTenantID = "None";
int Account::currentRole = 0;
string Account::AdminCode = "000";
LinkedList<Account> Account::accountList;

Account::Account() {}
Account::Account(const string& u, const string& p, const string& id, int role) : username(u), password(p), tenant_ID(id), role(role) {
    account_ID = generateID(++currentNumber);
}
Account::~Account() {}

string Account::generateID(int number) {
    stringstream ss;
    ss << "Account." << setw(3) << setfill('0') << number;
    return ss.str();
}

string Account::getusername() const { return username; }
string Account::getpassword() const { return password; }
string Account::gettenantID() const { return tenant_ID; }
int Account::getrole() const { return role; };

void Account::setusername(string u) { this->username = u; }
void Account::setpassword(string p) { this->password = p; }

void Account::fromString(const string& line) {
    string rollstr;
    stringstream ss(line);
    getline(ss, account_ID, ',');
    getline(ss, username, ',');
    getline(ss, password, ',');
    getline(ss, tenant_ID, ',');
    getline(ss, rollstr);
    role = stoi(rollstr);
    total++;
}

string Account::toString() const {
    return account_ID + ',' + username + "," + password + "," + tenant_ID+ "," + (role == 0 ? "0" : "1") ;
}

bool Account::signin(const string& u, const string& p) {
    LinkedList<Account>::Node* account;
        account = searchByUsername(u, 0);
        if (account != NULL && account->data.password == p) {
            currentTenantID = account->data.gettenantID();
            currentRole = account->data.getrole();
            return true;
        }
        return false;
}

void Account::updateFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return;
    }
    file << "accountID,username,password,tenantID,role,AdminCode:" << AdminCode << endl;
    file.close();
    accountList.updateFile(filename);
}

LinkedList<Account>::Node* Account::searchByUsername(string u, int check) {
    if (check == 1) { cout << "Nhap username can tim kiem: "; cin >> u; }
    LinkedList<Account>::Node* current = accountList.begin();
    while (current != nullptr) {
        if (current->data.getusername() == u) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void Account::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return;
    }
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string AdCode;
        getline(ss, AdCode, ':');  // Lấy "AdminCode"
        ss >> AdminCode;
    }
    file.close();
    accountList.load(filename);
}

void Account::showAllAccount(Admin* adminWindow){
    accountList.show(adminWindow);
}

void Account::display(Admin* adminWindow) const {
    adminWindow->displayAccounts(*this);
}

bool Account::setAdminCode(const string& oldcode, const string& newcode) {
    if (oldcode == AdminCode) {
        AdminCode = newcode;
        Account::updateFile("Account.txt");
        return true;
    }
    else {
        return false;
    }
}

bool Account::changePassword(const string& oldpass, const string& newpass) {
    LinkedList<Account>::Node* current = accountList.begin();
    while (current != nullptr) {
        if (current->data.gettenantID() == currentTenantID && current->data.getpassword() == oldpass) {
            current->data.setpassword(newpass);
            return true;
        }
        current = current->next;
    }
    return false;
}

LinkedList<Account>::Node* Account::verifyTenantInfo(const string& phone, const string& cccd) {
    LinkedList<Tenant>::Node* currentTenant = Tenant::tenantList.begin();
    while (currentTenant != nullptr) {
        if (currentTenant->data.getPhone() == phone &&
            currentTenant->data.getCCCD() == cccd) {
            string tenantID = currentTenant->data.getID();
            LinkedList<Account>::Node* currentAccount = accountList.begin();

            while (currentAccount != nullptr) {
                if (currentAccount->data.gettenantID() == tenantID) {
                    return currentAccount;
                }
                currentAccount = currentAccount->next;
            }
        }
        currentTenant = currentTenant->next;
    }
    return nullptr;
}
