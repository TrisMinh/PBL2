#include "Payment.h"

// Static Element
int Payment::total = 0;
int Payment::currentNumber = 0;
LinkedList<Payment> Payment::paymentList;

Payment::Payment() {}
Payment::Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount,
             double totalAmount, int payMonth, int payYear, bool status) :  roomID(roomID), tenantID(tenantID), rentAmount(rentAmount), serviceAmount(serviceAmount),
                totalAmount(totalAmount) ,payMonth(payMonth), payYear(payYear), status(status) {
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
    total++;
}

string Payment::toString() const {
    stringstream ss;
    ss << paymentID << "," << roomID << "," << tenantID << ","
       << int(rentAmount) << "," << int(serviceAmount) << "," << int(totalAmount) << "," << payMonth << "," << payYear << ","
       << payDate.toString() << "," << status; 
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
        if (roomID == usage.getRoomID() && tenantID == usage.getTenantID() && usage.getUsageMonth() == payMonth && usage.getUsageYear() == payYear) {
            serviceAmount += usage.getQuantity() * Service::serviceList.searchID(usage.getServiceID())->getUnitPrice(); // * unit price nếu cần
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
           << setw(width_status) << "Status"
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
       << setw(width_status) << (p.status ? "Paid" : "Pending")
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

