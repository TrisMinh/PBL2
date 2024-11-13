#include "Account.h"

// Static Element
int Account::total = 0;
int Account::currentNumber = 0;
string Account::currentTenantID = "None";
string Account::AdminCode = "000";
LinkedList<Account> Account::accountList;

// Constructor
Account::Account() {}
Account::Account(const string& u, const string& p, const string& id, int roll = 0) : username(u), password(p), tenant_ID(id) {
    currentNumber++;
    account_ID = generateID(currentNumber);
}
Account::~Account() {}

string Account::generateID(int number) {
    stringstream ss;
    ss << "Account." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Load function
void Account::load(const string& filename) {
    ifstream file(filename);    
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return;
    }   
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string label;
        getline(ss, label, ':');  // Lấy "AdminCode"
        ss >> AdminCode;        
    }   
    file.close();
    accountList.load(filename); 
}
void Account::updateFile(const string& filename) { 
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return;
    } 
    file << "username,password,tenantID,roll,AdminCode:" << AdminCode << endl;
    file.close();
    accountList.updateFile(filename); 
}

// Get function
string Account::getusername() { return username; }
string Account::getpassword() { return password; }
string Account::gettenantID() { return tenant_ID; }

// Set function
void Account::setusername(string u) { this->username = u; }
void Account::setpassword(string p) { this->password = p; }
void Account::setAdminCode() {
    string temp;
    cout << AdminCode << endl;
    cout << "Nhap AdminCode cu: "; cin >> temp;
    if (temp == AdminCode) {
        cout << "Nhap AdminCode moi: "; cin >> AdminCode;
        Account::updateFile("Data/Account.txt");
    }
    else {
        cout << "Khong dung AdminCode" << endl;
    }
}

// // Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void Account::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, username, ',');
    getline(ss, password, ',');
    getline(ss, tenant_ID);
    total++;
}

string Account::toString() const {
    return username + "," + password + "," + tenant_ID;
}

// Basic function
bool Account::signup() {
    string u, p;
    int repeat = 0;
    do { 
        if (repeat) { 
            cout << "Username nay da duoc su dung, vui long nhap lai hoac nhap 0 de thoat." << endl;
            string choice;
            cout << "Lua chon: ";
            cin.ignore();
            getline(cin,choice);
            if (choice == "0") {
                cout << "Dang ky da bi huy." << endl;
                return 0;
            }
        }
        cout << "Nhap username: "; cin >> u; 
        repeat = 1;
    } while (searchByUsername(u, 0) != NULL);
    cout << "Nhap password: "; cin >> p;
    cout << "Nhap thong tin ca nhan: " << endl;
    string name, phone, cccd;
    int age;
    cout << "Nhap ten: "; cin >> name;
    cout << "Nhap so dien thoai: "; cin >> phone;
    cout << "Nhap CCCD: "; cin >> cccd;
    cout << "Nhap nam sinh: "; cin >> age;   
    Tenant tenant(name, phone, cccd, age);
    Tenant::tenantList.add(tenant);
    Account acc(u, p, tenant.getID());
    accountList.add(acc);
    cout << "Sign up successful!" << endl;
    total++;
    accountList.updateFile("Data/Account.txt");
    return 1;
}

bool Account::signin() {
    string u, p;
    LinkedList<Account>::Node* account;
    int attempts = 0;  
    do {
        if (attempts) { 
            cout << "Username hoac password khong dung. Nhap 0 de thoat hoac Enter de thu lai." << endl;
            string choice;
            cout << "Lua chon: ";
            cin.ignore();
            getline(cin,choice);
            if (choice == "0") {
                cout << "Dang nhap da bi huy." << endl;
                return 0;
            }
        }
        cout << "Nhap username: "; cin >> u;
        cout << "Nhap password: "; cin >> p;
        account = searchByUsername(u, 0);       
        // Kiểm tra nếu tên đăng nhập và mật khẩu khớp
        if (account != NULL && account->data.password == p) {
            currentTenantID = account->data.gettenantID();
            cout << "Dang nhap thanh cong!" << endl;
            return 1;
        }      
        account = NULL; 
        attempts++;

    } while (account == NULL);
}

// Search function
LinkedList<Account>::Node* Account::searchByUsername(string u, int check) {
    if (check == 1) {
        cout << "Nhap username can tim kiem: "; cin >> u;
    }
    LinkedList<Account>::Node* current = accountList.getHead(); 
    while (current != nullptr) {
        if (current->data.getusername() == u) {
            return current; 
        }
        current = current->next; 
    }
    return nullptr; 
}
LinkedList<Account>::Node* Account::searchByPassword(string p) {
    LinkedList<Account>::Node* current = accountList.getHead(); 
    while (current != nullptr) {
        if (current->data.getpassword() == p) {
            return current; 
        }
        current = current->next; 
    }
    return nullptr; 
}

void Account::showAllAccount() {
    cout << "Danh sach Account:" << endl;
    accountList.show();
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Account& a) {
    os << left
       << setw(15) << ("AccountID: " + a.account_ID) << " | "
       << setw(15) << ("Username: " + a.username) << " | "
       << setw(15) << ("Password: " + a.password) << " | "
       << setw(20) << ("TenantID " + a.tenant_ID) << endl;
    return os;
}
