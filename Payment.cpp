#include "Payment.h"

// Static Element
int Payment::total = 0;
int Payment::currentNumber = 0;
LinkedList<Payment> Payment::paymentList;

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
string Payment::getRoomID () const { return roomID; }
string Payment::getTenantID () const { return tenantID; }
int Payment::getPayMonth() { return payMonth; }
int Payment::getPayYear() { return payYear; }


void Payment::fromString(const string& line) {
    string payDatestr;
    stringstream ss(line);
    getline(ss, paymentID, ',');
    getline(ss, roomID, ',');
    getline(ss, tenantID, ',');
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
    getline(ss, payDatestr, ',');
    payDate.fromString(payDatestr);
    ss >> status;
    ss.ignore(1);
    ss >> depositAmount;
    total++;
}

string Payment::toString() const {
    stringstream ss;
    ss << paymentID << "," << roomID << "," << tenantID << ","
       << int(rentAmount) << "," << int(serviceAmount) << "," << int(totalAmount) << "," << payMonth << "," << payYear << ","
       << payDate.toString() << "," << status << "," << depositAmount; 
    return ss.str();
}

void Payment::showAllPayments() {
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
    cout << "Nhap thang va nam ban muon tao bills: \n";
    cout << "Nhap thang: "; cin >> payMonth;
    cout << "Nhap nam: "; cin >> payYear;
    for (LinkedList<Contract>::Node* current = Contract::contractList.begin(); current != nullptr; current = current->next) {
    Contract& contract = current->data;
    string roomID, tenantID;
    double rentAmount = 0, serviceAmount = 0;

    if (contract.getStatus() == 0) continue; // Bỏ qua nếu hợp đồng chưa được kích hoạt
    roomID = contract.getRoomID();
    tenantID = contract.getTenantID();
    rentAmount = contract.getPrice();
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
    for (LinkedList<ServiceUsage>::Node* current = ServiceUsage::usageList.begin(); current != nullptr; current = current->next) {
            ServiceUsage& usage = current->data;
        if (roomID == usage.getRoomID() && tenantID == usage.getTenantID() && usage.getStatus() == true) {
            serviceAmount += usage.getQuantity() * 
                            Service::serviceList.searchID(usage.getServiceID())->getUnitPrice();
        }
    }
    Payment p(roomID, tenantID, rentAmount, serviceAmount, rentAmount + serviceAmount, payMonth, payYear);
    paymentList.add(p);

    }
    if (paymentList.begin() == NULL) { cout << "Danh sach Bill trong" << endl; return;}
    cout << "Tao bills thanh cong!" << endl;
}

ostream& operator<<(ostream& os, const Payment& p) {
    // Định nghĩa độ rộng cho từng cột
    const int width_payment_id = 15;
    const int width_room_id = 10;
    const int width_tenant_id = 10;
    const int width_rent_amount = 12;
    const int width_service_amount = 15;
    const int width_total_amount = 12;
    const int width_pay_month = 10;    // Thêm độ rộng cho payMonth
    const int width_pay_year = 10;     // Thêm độ rộng cho payYear
    const int width_pay_date = 12;
    const int width_status = 8;
    const int width_deposit = 15;
    const int width_remaining = 15;

    static bool is_header_printed = false;

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_payment_id) << "Payment ID" << " | "
           << setw(width_room_id) << "Room ID" << " | "
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_rent_amount) << "Rent Amount" << " | "
           << setw(width_service_amount) << "Service Amount" << " | "
           << setw(width_total_amount) << "Total Amount" << " | "
           << setw(width_pay_month) << "Pay Month" << " | "    // Thêm cột payMonth
           << setw(width_pay_year) << "Pay Year" << " | "      // Thêm cột payYear
           << setw(width_pay_date) << "Pay Date" << " | "
           << setw(width_status) << "Status" << " | "
           << setw(width_deposit) << "Deposited" << " | "
           << setw(width_remaining) << "Remaining"
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_payment_id + 2) << ""
           << setw(width_room_id + 3) << ""
           << setw(width_tenant_id + 3) << ""
           << setw(width_rent_amount + 3) << ""
           << setw(width_service_amount + 3) << ""
           << setw(width_total_amount + 3) << ""
           << setw(width_pay_month + 3) << ""      // Thêm dòng kẻ cho payMonth
           << setw(width_pay_year + 3) << ""       // Thêm dòng kẻ cho payYear
           << setw(width_pay_date + 3) << ""
           << setw(width_status + 3) << ""
           << setw(width_deposit + 3) << ""
           << setw(width_remaining + 3) << ""
           << setfill(' ') << endl;

        is_header_printed = true;
    }

    // In dữ liệu Payment
    os << left
       << setw(width_payment_id) << p.paymentID << " | "
       << setw(width_room_id) << p.roomID << " | "
       << setw(width_tenant_id) << p.tenantID << " | "
       << setw(width_rent_amount) << fixed << setprecision(2) << p.rentAmount << " | "
       << setw(width_service_amount) << fixed << setprecision(2) << p.serviceAmount << " | "
       << setw(width_total_amount) << fixed << setprecision(2) << p.totalAmount << " | "
       << setw(width_pay_month) << p.payMonth << " | "     // In payMonth
       << setw(width_pay_year) << p.payYear << " | "       // In payYear
       << setw(width_pay_date) << p.payDate.toString() << " | "
       << setw(width_status) << (p.status ? "Paid" : "Pending") << " | "
       << setw(width_deposit) << p.depositAmount << " | "
       << setw(width_remaining) << p.getRemainingAmount() << " | "
       << endl;

    return os;
}

void Payment::searchByMonth() {
    int month, year;
    
    do {
        cout << "Nhap thang (1-12): ";
        cin >> month;
        if (month < 1 || month > 12) {
            cout << "Thang khong hop le. Vui long nhap lai!\n";
        }
    } while (month < 1 || month > 12);
    
    do {
        cout << "Nhap nam (>= 2000): ";
        cin >> year;
        if (year < 2000) {
            cout << "Nam khong hop le. Vui long nhap lai!\n";
        }
    } while (year < 2000);
    
    bool found = false;
    cout << "\nDanh sach cac bills trong thang " << month << "/" << year << ":\n";
    
    for (LinkedList<Payment>::Node* current = paymentList.begin(); current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.payMonth == month && payment.payYear == year) {
            cout << payment;
            found = true;
        }
    }
    
    if (!found) {
        cout << "   Khong tim thay bills nao trong thang " << month << "/" << year << endl;
    }
}

void Payment::makePayment() {
    if (status) {
        cout << "Bill nay da duoc thanh toan day du!\n";
        return;
    }

    cout << "\nThong tin bill:\n";
    cout << *this;  // In thông tin bill hiện tại
    
    double remaining = getRemainingAmount();
    cout << "\nSo tien da thanh toan: " << depositAmount << endl;
    cout << "So tien con lai can thanh toan: " << remaining << endl;
    
    double amount;
    cout << "\nNhap so tien muon thanh toan (nhap 0 de huy): ";
    cin >> amount;
    
    if (amount == 0) {
        cout << "Da huy thanh toan.\n";
        return;
    }
    
    if (amount < 0) {
        cout << "So tien khong hop le!\n";
        return;
    }
    
    if (amount > remaining) {
        cout << "So tien vuot qua so tien can thanh toan!\n";
        return;
    }
    
    depositAmount += amount;
    if (depositAmount >= totalAmount) {
        status = true;
        cout << "Bill da duoc thanh toan day du!\n";
    } else {
        cout << "Da thanh toan " << amount << endl;
        cout << "So tien con lai can thanh toan: " << getRemainingAmount() << endl;
    }
}

void Payment::managePayments() {
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

void Payment::showRevenueStatistics() {
    int choice;
    do {
        cout << "\n=== THONG KE DOANH THU ===\n";
        cout << "1. Xem doanh thu theo thang\n";
        cout << "2. So sanh doanh thu cac thang trong nam\n";
        cout << "3. So sanh doanh thu qua cac nam\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int month, year;
                cout << "Nhap thang (1-12): "; cin >> month;
                cout << "Nhap nam: "; cin >> year;
                double totalBilled = calculateTotalBilled(month, year);
                double totalCollected = calculateTotalCollected(month, year);
                cout << "\nThong ke thang " << month << "/" << year << ":\n";
                cout << "Tong so tien hoa don: " << fixed << setprecision(2) << totalBilled << endl;
                cout << "Tong so tien da thu: " << fixed << setprecision(2) << totalCollected << endl;
                cout << "So tien chua thu: " << fixed << setprecision(2) << (totalBilled - totalCollected) << endl;
                break;
            }
            case 2: {
                int year;
                cout << "Nhap nam can thong ke: ";
                cin >> year;
                showMonthlyComparison(year);
                break;
            }
            case 3: {
                int startYear, endYear;
                cout << "Nhap nam bat dau: "; cin >> startYear;
                cout << "Nhap nam ket thuc: "; cin >> endYear;
                showYearlyComparison(startYear, endYear);
                break;
            }
        }
    } while (choice != 0);
}

// Tính tổng số tiền của các hóa đơn trong tháng
double Payment::calculateTotalBilled(int month, int year) {
    double total = 0;
    for (LinkedList<Payment>::Node* current = paymentList.begin(); 
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.payMonth == month && payment.payYear == year) {
            total += payment.totalAmount;
        }
    }
    return total;
}

// Tính tổng số tiền đã thu được trong tháng
double Payment::calculateTotalCollected(int month, int year) {
    double total = 0;
    for (LinkedList<Payment>::Node* current = paymentList.begin(); 
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.payMonth == month && payment.payYear == year && payment.status) {
            total += payment.totalAmount;
        }
    }
    return total;
}

void Payment::showMonthlyComparison(int year) {
    cout << "\nSo sanh doanh thu cac thang trong nam " << year << ":\n";
    cout << setw(10) << "Thang" 
         << setw(20) << "Tong hoa don" 
         << setw(20) << "Da thu" 
         << setw(20) << "Chua thu" << endl;
    cout << string(70, '-') << endl;
    
    double maxBilled = 0;
    for (int month = 1; month <= 12; month++) {
        double billed = calculateTotalBilled(month, year);
        if (billed > maxBilled) maxBilled = billed;
    }

    for (int month = 1; month <= 12; month++) {
        double totalBilled = calculateTotalBilled(month, year);
        double totalCollected = calculateTotalCollected(month, year);
        
        cout << setw(10) << month 
             << setw(20) << fixed << setprecision(2) << totalBilled 
             << setw(20) << totalCollected
             << setw(20) << (totalBilled - totalCollected);
        
        // Vẽ biểu đồ đơn giản
        cout << "  ";
        int barLength = (totalBilled/maxBilled) * 30;
        cout << string(barLength, '*');
        cout << endl;
    }
}

void Payment::showYearlyComparison(int startYear, int endYear) {
    cout << "\nSo sanh doanh thu qua cac nam:\n";
    cout << setw(10) << "Nam" 
         << setw(20) << "Tong hoa don" 
         << setw(20) << "Da thu" 
         << setw(20) << "Chua thu" << endl;
    cout << string(70, '-') << endl;

    double maxYearlyBilled = 0;
    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
        }
        if (yearlyBilled > maxYearlyBilled) maxYearlyBilled = yearlyBilled;
    }

    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        double yearlyCollected = 0;
        
        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
            yearlyCollected += calculateTotalCollected(month, year);
        }
        
        cout << setw(10) << year 
             << setw(20) << fixed << setprecision(2) << yearlyBilled 
             << setw(20) << yearlyCollected
             << setw(20) << (yearlyBilled - yearlyCollected);

        // Vẽ biểu đồ đơn giản
        cout << "  ";
        int barLength = (yearlyBilled/maxYearlyBilled) * 30;
        cout << string(barLength, '*');
        cout << endl;
    }
}

void Payment::searchByTenantID(string tenantID) {
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
