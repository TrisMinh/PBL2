#include "Header/Payment.h"
#include <sstream>
Payment::Payment() {}
Payment::Payment(const string& id, const string& resId, int month, const string& day, int rentAmt, int servAmt, int totalAmt, int stat)
    : payment_ID(id), reservation_ID(resId), payment_month(month), payment_day(day),
      rent_amount(rentAmt), service_amount(servAmt), total_amount(totalAmt), status(stat) {}
Payment::~Payment() {}
string Payment::getID() {
    return payment_ID;
}
void Payment::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, payment_ID, ',');
    getline(ss, reservation_ID, ',');
    ss >> payment_month;
    ss.ignore(1);
    getline(ss, payment_day, ',');
    ss >> rent_amount;
    ss.ignore(1);
    ss >> service_amount;
    ss.ignore(1);
    ss >> total_amount;
    ss.ignore(1);
    ss >> status;
}
ostream& operator<<(ostream& os, const Payment& p) {
    os << "Payment [ID: " << p.payment_ID << ", Reservation ID: " << p.reservation_ID
       << ", Payment Month: " << p.payment_month << ", Payment Day: " << p.payment_day
       << ", Rent Amount: " << p.rent_amount << ", Service Amount: " << p.service_amount
       << ", Total Amount: " << p.total_amount << ", Status: " << (p.status == 1 ? "Paid" : "Unpaid") << "]\n";
    return os;
}
void Payment::addPayment(LinkedList<Payment>& paymentList) {
    string payment_ID, reservation_ID, payment_day;
    int payment_month, rent_amount, service_amount, total_amount, status;
    cout << "Nhap thong tin thanh toan:" << endl;
    cout << "Payment ID: ";
    cin >> payment_ID;
    cout << "Reservation ID: ";
    cin >> reservation_ID;
    cout << "Payment Month: ";
    cin >> payment_month;
    cout << "Payment Day: ";
    cin >> payment_day;
    cout << "Rent Amount: ";
    cin >> rent_amount;
    cout << "Service Amount: ";
    cin >> service_amount;
    total_amount = rent_amount + service_amount;
    cout << "Total Amount: " << total_amount << endl;
    cout << "Status (0: Chua thanh toan, 1: Da thanh toan): ";
    cin >> status;
    Payment newPayment(payment_ID, reservation_ID, payment_month, payment_day, rent_amount, service_amount, total_amount, status);
    paymentList.add(newPayment);
    cout << "Payment added successfully!" << endl;
}
void Payment::searchPaymentByID(LinkedList<Payment>& paymentList) {
    string paymentID;
    cout << "Nhap Payment ID de tim kiem: ";
    cin >> paymentID;
    Payment* payment = paymentList.search(paymentID);
    if (payment) {
        cout << "Da tim thay: " << *payment << endl;
    } else {
        cout << "Khong tim thay thanh toan voi ID: " << paymentID << endl;
    }
}
void Payment::updatePayment(LinkedList<Payment>& paymentList) {
    string paymentID;
    cout << "Nhap Payment ID de cap nhat: ";
    cin >> paymentID;
    Payment* payment = paymentList.search(paymentID);
    if (payment) {
        string newReservationID, newPaymentDay;
        int newPaymentMonth, newRentAmount, newServiceAmount, newTotalAmount, newStatus;
        cout << "Cap nhat Payment ID: " << payment->payment_ID << endl;
        cout << "Reservation ID (nhap moi neu muon thay doi): ";
        cin >> newReservationID;
        cout << "Payment Month: ";
        cin >> newPaymentMonth;
        cout << "Payment Day: ";
        cin >> newPaymentDay;
        cout << "Rent Amount: ";
        cin >> newRentAmount;
        cout << "Service Amount: ";
        cin >> newServiceAmount;
        newTotalAmount = newRentAmount + newServiceAmount;
        cout << "Total Amount: " << newTotalAmount << endl;
        cout << "Status (0: Chua thanh toan, 1: Da thanh toan): ";
        cin >> newStatus;
        payment->reservation_ID = newReservationID;
        payment->payment_month = newPaymentMonth;
        payment->payment_day = newPaymentDay;
        payment->rent_amount = newRentAmount;
        payment->service_amount = newServiceAmount;
        payment->total_amount = newTotalAmount;
        payment->status = newStatus;
        cout << "Payment updated successfully!" << endl;
    } else {
        cout << "Khong tim thay thanh toan voi ID: " << paymentID << endl;
    }
}
void Payment::deletePayment(LinkedList<Payment>& paymentList) {
    string paymentID;
    cout << "Nhap Payment ID de xoa: ";
    cin >> paymentID;
    paymentList.deleteNode(paymentID);
    cout << "Payment deleted successfully!" << endl;
}
void Payment::showAllPayments(LinkedList<Payment>& paymentList) {
    cout << "Danh sach tat ca cac thanh toan:" << endl;
    paymentList.show();
}
