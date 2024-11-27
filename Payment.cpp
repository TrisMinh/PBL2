#include "Payment.h"
#include "PaymentStatistics.h"


// Static Element Initialization
int Payment::total = 0;
int Payment::currentNumber = 0;
LinkedList<Payment> Payment::paymentList;
bool Payment::is_header_printed = false;
void Payment::resetHeader() { Payment::is_header_printed = false; }

Payment::Payment() : depositAmount(0) {}
Payment::Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount,
             double totalAmount, int payMonth, int payYear, bool status) :  roomID(roomID), tenantID(tenantID), rentAmount(rentAmount), serviceAmount(serviceAmount),
                totalAmount(totalAmount) ,payMonth(payMonth), payYear(payYear), status(status), depositAmount(0) {
                paymentID = generateID(++currentNumber);
                totalAmount = rentAmount + serviceAmount;    
}
Payment::~Payment() {}

string Payment::generateID(int number) {
    stringstream ss;
    ss << "P." << setw(3) << setfill('0') << number;
    return ss.str();
}

void Payment::load(const string& filename) { paymentList.load(filename); }
void Payment::updateFile(const string& filename) { paymentList.updateFile(filename); }

string Payment::getID() const { return paymentID; }
string Payment::getRoomID() const { return roomID; }
string Payment::getTenantID() const { return tenantID; }
int Payment::getPayMonth() const { return payMonth; }
int Payment::getPayYear() const { return payYear; }
double Payment::getDepositAmount() const { return depositAmount; }
double Payment::getTotalAmount() const { return totalAmount; }
double Payment::getRemainingAmount() const { return totalAmount - depositAmount; }

void Payment::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, paymentID, ','); getline(ss, roomID, ','); getline(ss, tenantID, ',');
    ss >> rentAmount;
    ss.ignore(1);
    ss >> serviceAmount;
    ss.ignore(1);
    ss >> totalAmount;
    ss.ignore(1);
    ss >> payMonth;
    ss.ignore(1);
    ss >> payYear;
    ss.ignore(1);
    string payDatestr; getline(ss, payDatestr, ',');
    payDate.fromString(payDatestr);
    ss >> status >> depositAmount;
    total++;
}

string Payment::toString() const {
    return paymentID + "," + roomID + "," + tenantID + "," + to_string(rentAmount) + "," + to_string(serviceAmount) + "," + 
           to_string(totalAmount) + "," + to_string(payMonth) + "," + 
           to_string(payYear) + "," + payDate.toString() + "," + 
           to_string(status) + "," + to_string(depositAmount);
}

void Payment::showAllPayments() {
    resetHeader();
    cout << "\nDanh sach tat ca cac bills:" << endl;
    paymentList.show();
    
    char choice;
    while (true) {
        cout << "\nBan co muon tim kiem bills theo thang/nam khong?\n";
        cout << "1. Tim kiem theo thang/nam\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        
        if (choice == '0') {
            cout << "Thoat xem bills.\n";
            break;
        } else if (choice == '1') {
            searchByMonth();
        } else {
            cout << "Lua chon khong hop le!\n";
        }
    }
}

void Payment::autocreatePayment() {
    int payMonth, payYear;
    do {
        cout << "Nhap thang va nam ban muon tao bills: \n";
        cout << "Nhap thang: "; cin >> payMonth;
        cout << "Nhap nam: "; cin >> payYear;

        // Validate month and year
        if (payMonth < 1 || payMonth > 12) {
            cout << "Thang khong hop le! Thang phai tu 1-12" << endl;
            continue;
        }
        if (payYear < 2000) {
            cout << "Nam khong hop le! Nam phai tu 2000 tro len" << endl;
            continue;
        }
        break;
    } while (true);

    char usageChoice;
    cout << "Ban muon nhap so luong dien/nuoc?\n";
    cout << "0. Tu dong gan 100 cho moi phong\n";
    cout << "1. Tu nhap so luong\n";
    cout << "Nhap lua chon: ";
    cin >> usageChoice;

    bool hasCreated = false;

    for (LinkedList<Contract>::Node* current = Contract::contractList.begin(); current != nullptr; current = current->next) {
        Contract& contract = current->data;
        string roomID, tenantID;
        double rentAmount = 0, serviceAmount = 0;

        if (contract.getStatus() == 0) continue;

        // Kiểm tra ngày thanh toán có nằm trong thời hạn hợp đồng
        DATE paymentDate(1, payMonth, payYear);
        if (paymentDate > contract.getEndDate() || 
            (paymentDate.get_year() < contract.getStartDate().get_year()) ||
            (paymentDate.get_year() == contract.getStartDate().get_year() && 
             paymentDate.get_month() < contract.getStartDate().get_month())) {
            continue;
        }

        roomID = contract.getRoomID();
        tenantID = contract.getTenantID();
        rentAmount = contract.getPrice();

        // Tính toán tiền nhà cho tháng đầu tiên nếu ngày bắt đầu hợp đồng không phải ngày 1
        if (payMonth == contract.getStartDate().get_month() && 
            payYear == contract.getStartDate().get_year()) {
            int daysInMonth = 31; // Mặc định là 31 ngày
            // Xác định chính xác số ngày trong tháng
            if (payMonth == 4 || payMonth == 6 || payMonth == 9 || payMonth == 11) {
                daysInMonth = 30;
            } else if (payMonth == 2) {
                // Kiểm tra năm nhuận cho tháng 2
                daysInMonth = (payYear % 4 == 0 && (payYear % 100 != 0 || payYear % 400 == 0)) ? 29 : 28;
            }
            
            // Tính số ngày ở thực tế trong tháng đầu
            int startDay = contract.getStartDate().get_day();
            int remainingDays = daysInMonth - startDay + 1;
            // Tính tiền nhà theo số ngày thực ở
            rentAmount = (rentAmount / daysInMonth) * remainingDays;
        }

        // Check if payment already exists
        bool isPaymentExist = false;
        for (LinkedList<Payment>::Node* paymentCurrent = paymentList.begin(); paymentCurrent != nullptr; paymentCurrent = paymentCurrent->next) {
            Payment& payment = paymentCurrent->data;
            if (payment.getRoomID() == roomID && payment.getTenantID() == tenantID && 
                payment.getPayMonth() == payMonth && payment.getPayYear() == payYear) {
                isPaymentExist = true;
                break;  
            }
        }
        if (isPaymentExist) continue;

        // Calculate service amount
        for (LinkedList<ServiceUsage>::Node* current = ServiceUsage::usageList.begin(); current != nullptr; current = current->next) {
            ServiceUsage& usage = current->data;
            if (usage.getStatus() && 
                roomID == usage.getRoomID() && 
                tenantID == usage.getTenantID()) {
                Service* service = Service::serviceList.searchID(usage.getServiceID());
                if (service != nullptr) {
                    if (service->getID() == "S.005" || 
                        service->getID() == "S.006") {
                        double quantity;
                        if (usageChoice == '0') {
                            quantity = 100;
                        } else {
                            cout << "Nhap so luong " << service->getName() 
                                 << " cho phong " << roomID << ": ";
                            cin >> quantity;
                        }
                        serviceAmount += service->getUnitPrice() * quantity;
                    } else {
                        serviceAmount += service->getUnitPrice();
                    }
                }
            }
        }

        Payment p(roomID, tenantID, rentAmount, serviceAmount, rentAmount + serviceAmount, payMonth, payYear);
        paymentList.add(p);
        hasCreated = true;
    }

    if (!hasCreated) {
        cout << "Khong co bills nao duoc tao! Khong tim thay hop dong phu hop voi thoi gian nay hoac da tao roi." << endl;
    } else {
        cout << "Tao bills thanh cong!" << endl;
    }
}
ostream& operator<<(ostream& os, const Payment& p) {
    const int w_id=15,w_room=10,w_tenant=10,w_rent=15,w_service=15,w_total=15,w_status=10,w_date=12,w_mo=10,w_ye=10,w_deposit=15,w_remain=15;
    
    if (!Payment::is_header_printed) {
        os << left << setw(w_id) << "Payment ID" << " | "
           << setw(w_room) << "Room ID" << " | "
           << setw(w_tenant) << "Tenant ID" << " | "
           << setw(w_rent) << "Rent Amount" << " | "
           << setw(w_service) << "Service Amount" << " | "
           << setw(w_total) << "Total Amount" << " | "
           << setw(w_mo) << "Month" << " | "
           << setw(w_ye) << "Year" << " | "
           << setw(w_date) << "Pay Date" << " | "
           << setw(w_status) << "Status" << " | "
           << setw(w_deposit) << "Deposit" << " | "
           << setw(w_remain) << "Remaining" << endl
           << string(w_id + w_room + w_tenant + w_rent + w_service + w_total + w_mo + w_ye + w_date + w_status + w_deposit + w_remain + 36, '-') << endl;
        Payment::is_header_printed = true;
    }
    
    os << left << setw(w_id) << p.paymentID << " | "
       << setw(w_room) << p.roomID << " | "
       << setw(w_tenant) << p.tenantID << " | "
       << setw(w_rent) << fixed << setprecision(2) << p.rentAmount << " | "
       << setw(w_service) << p.serviceAmount << " | "
       << setw(w_total) << p.totalAmount << " | "
       << setw(w_mo) << p.payMonth << " | "
       << setw(w_ye) << p.payYear << " | "
       << setw(w_date) << p.payDate.toString() << " | "
       << setw(w_status) << (p.status ? "Paid" : "Pending") << " | "
       << setw(w_deposit) << p.depositAmount << " | "
       << setw(w_remain) << p.getRemainingAmount() << endl;
    return os;
}

void Payment::searchByMonth() {
    resetHeader();
    int month, year;
    cout << "Nhap thang (1-12): "; 
    if(!(cin >> month) || month < 1 || month > 12) { cout << "Thang khong hop le!\n"; return; }
    cout << "Nhap nam (>= 2000): ";
    if(!(cin >> year) || year < 2000) { cout << "Nam khong hop le!\n"; return; }
    bool found = false;
    cout << "\nDanh sach cac bills trong thang " << month << "/" << year << ":\n";
    
    for (auto current = paymentList.begin(); current != nullptr; current = current->next) {
        if (current->data.payMonth == month && current->data.payYear == year) {
            cout << current->data;
            found = true;
        }
    }
    if (!found) cout << "   Khong tim thay bills nao trong thang " << month << "/" << year << endl;
}

void Payment::makePayment() {
    resetHeader();
    if (status) { cout << "Bill nay da duoc thanh toan day du!\n"; return; }

    cout << "\nThong tin bill:\n"; cout << *this;  // In thông tin bill hiện tại
    double remaining = getRemainingAmount();
    cout << "\nSo tien da thanh toan: " << depositAmount << endl;
    cout << "So tien con lai can thanh toan: " << remaining << endl;
    
    double amount; cout << "\nNhap so tien muon thanh toan (nhap 0 de huy): "; cin >> amount;
    if (amount == 0) { cout << "Da huy thanh toan.\n"; return; }
    if (amount < 0) { cout << "So tien khong hop le!\n"; return; }
    if (amount > remaining) { cout << "So tien vuot qua so tien can thanh toan!\n"; return; }
    
    depositAmount += amount;
    if (depositAmount >= totalAmount) { 
        status = true; 
        time_t now = time(0);
        tm* ltm = localtime(&now);
        payDate = DATE(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
        cout << "Bill da duoc thanh toan day du!\n"; 
    }
    else {
        cout << "Da thanh toan " << amount << endl;
        cout << "So tien con lai can thanh toan: " << getRemainingAmount() << endl;
    }
}

void Payment::managePayments() {
    resetHeader();
    cout << "\nDanh sach cac bills chua thanh toan cua ban:\n";
    bool found = false;
    for (LinkedList<Payment>::Node* current = paymentList.begin(); 
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getTenantID() == Account::currentTenantID && !payment.status) {
            cout << payment;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co bills nao can thanh toan!\n";
        return;
    }
    string paymentID;
    cout << "\nNhap Payment ID can thanh toan (nhap '0' de thoat): ";
    cin >> paymentID;
    
    if (paymentID == "0") return;
    
    for (LinkedList<Payment>::Node* current = paymentList.begin(); 
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getID() == paymentID && 
            payment.getTenantID() == Account::currentTenantID) {
            payment.makePayment();
            return;
        }
    }
    cout << "Khong tim thay bill hoac bill khong thuoc ve ban!\n";
}

void Payment::searchByTenantID(string tenantID) {
    resetHeader();
    cout << "\nDanh sach bills cua ban: " << endl;
    bool found = false;
    for (LinkedList<Payment>::Node* current = paymentList.begin(); current != nullptr; current = current->next) {
        if (current->data.getTenantID() == tenantID) {
            cout << current->data;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay bills nao!" << endl;
    }
}

void Payment::checkUnpaidPayments(const string& tenantID) {
    bool hasUnpaid = false;
    double totalUnpaid = 0;
    int count = 0;
    
    for (LinkedList<Payment>::Node* current = paymentList.begin(); current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getTenantID() == tenantID && !payment.status) {
            hasUnpaid = true;
            totalUnpaid += payment.getRemainingAmount();
            count++;
        }
    }
    
    if (hasUnpaid) {
        cout << "\n=== THONG BAO THANH TOAN ===\n";
        cout << "Ban co " << count << " hoa don chua thanh toan!\n";
        cout << "Tong so tien can thanh toan: " << fixed << setprecision(2) 
             << totalUnpaid << " VND\n";
        cout << "Vui long thanh toan dung han!\n\n";
    }
}

