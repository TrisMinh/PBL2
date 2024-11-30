#include "Account.h"

int Account::total = 0;
int Account::currentNumber = 0;
string Account::currentTenantID = "None";
int Account::currentRole = 0;
string Account::AdminCode = "000";
LinkedList<Account> Account::accountList;

Account::Account() {}
Account::~Account() {}

string Account::getusername() const { return username; }
string Account::getpassword() const { return password; }
string Account::gettenantID() const { return tenant_ID; }
int Account::getrole() const { return role; };

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
