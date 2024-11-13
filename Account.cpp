#include "Account.h"

// Static Element
int Account::total = 0;
int Account::currentNumber = 0;
string Account::currentTenantID = "None";
string Account::AdminCode = "000";
LinkedList<Account> Account::accountList;

// Constructor
Account::Account() {}
Account::Account(const string& u, const string& p, const string& id, int roll) : username(u), password(p), tenant_ID(id) {
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
        string AdCode;
        getline(ss, AdCode, ':');  // Lấy "AdminCode"
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
    file << "accountID,username,password,tenantID,roll,AdminCode:" << AdminCode << endl;
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
    string rollstr;
    stringstream ss(line);
    getline(ss, account_ID, ',');
    getline(ss, username, ',');
    getline(ss, password, ',');
    getline(ss, tenant_ID, ',');
    getline(ss, rollstr);
    roll = stoi(rollstr); 
    total++;
}

string Account::toString() const {
    return account_ID + ',' + username + "," + password + "," + tenant_ID+ "," + (roll == 0 ? "0" : "1") ;
}

// Basic function
bool Account::signup() {
    string u, p;
    int repeat = 0;
    int role;
    
    // Chọn loại tài khoản
    cout << "Lua chon loai tai khoan (1 = Tenant, 2 = Admin): ";
    cin >> role;

    // Nếu chọn tài khoản admin, yêu cầu nhập AdminCode
    if (role == 2) {
        string adminCodeInput;
        int attempts = 0;
        
        do {
            if (attempts > 0) {
                cout << "AdminCode khong dung, vui long bam enter de nhap lai hoac nhap 0 de thoat." << endl;
                cout << "Lua chon: ";
                cin.ignore();
                getline(cin, adminCodeInput);
                
                // Kiểm tra nếu người dùng muốn thoát
                if (adminCodeInput == "0") {
                    cout << "Dang ky da bi huy." << endl;
                    return 0;
                }
            }
            cout << "Nhap AdminCode: ";
            cin >> adminCodeInput;
            attempts++;
        } while (adminCodeInput != Account::AdminCode);  // Yêu cầu nhập lại nếu mã không đúng

        cout << "AdminCode hop le. Dang ky tai khoan admin." << endl;
    }

    // Thực hiện phần đăng ký tài khoản thông thường
    do { 
        if (repeat) { 
            cout << "Username nay da duoc su dung, vui long nhap lai hoac nhap 0 de thoat." << endl;
            string choice;
            cout << "Lua chon: ";
            cin.ignore();
            getline(cin, choice);
            if (choice == "0") {
                cout << "Dang ky da bi huy." << endl;
                return 0;
            }
        }
        cout << "Nhap username: ";
        cin >> u;
        repeat = 1;
    } while (searchByUsername(u, 0) != NULL);
    
    cout << "Nhap password: ";
    cin >> p;

    // Đăng ký tài khoản tenant bình thường
    if (role == 1) {
        cout << "Nhap thong tin ca nhan: " << endl;
        string name, phone, cccd;
        int age;
        cout << "Nhap ten: ";
        cin >> name;
        cout << "Nhap so dien thoai: ";
        cin >> phone;
        cout << "Nhap CCCD: ";
        cin >> cccd;
        cout << "Nhap nam sinh: ";
        cin >> age;
        time_t t = time(0); 
        tm* now = localtime(&t); 
        int yearNow = now->tm_year + 1900; 

        // Tạo tenant và thêm vào danh sách
        Tenant tenant(name, phone, cccd, yearNow -  age);
        Tenant::tenantList.add(tenant);

        // Tạo tài khoản tenant với tenant ID
        Account acc(u, p, tenant.getID(),0);
        accountList.add(acc);
        Tenant::updateFile("Data/Tenant.txt");
    } else {
        // Tạo tài khoản admin (không có tenant ID)
        Account acc(u, p, "Admin",1);
        accountList.add(acc);
    }

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

ostream& operator<<(ostream& os, const Account& a) {
    // Định nghĩa độ rộng cho từng cột
    const int width_id = 15;
    const int width_username = 15;
    const int width_password = 15;
    const int width_tenant_id = 15;
    const int width_role = 10;

    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_id) << "AccountID" << " | "
           << setw(width_username) << "Username" << " | "
           << setw(width_password) << "Password" << " | "
           << setw(width_tenant_id) << "TenantID" << " | "
           << setw(width_role) << "Role" 
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_id + 2) << ""
           << setw(width_username + 3) << ""
           << setw(width_password + 3) << ""
           << setw(width_tenant_id + 3) << ""
           << setw(width_role + 1) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In dữ liệu tài khoản
    os << left 
       << setw(width_id) << a.account_ID << " | "
       << setw(width_username) << a.username << " | "
       << setw(width_password) << a.password << " | "
       << setw(width_tenant_id) << a.tenant_ID << " | "
       << setw(width_role) << (a.roll == 0 ? "Tenant" : "Admin")
       << endl;

    return os;
}
