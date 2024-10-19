#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
class Payment {
    string payment_ID;
    string reservation_ID;
    int payment_month;
    string payment_day;
    int rent_amount;
    int service_amount;
    int total_amount;
    int status;  // 0: Chưa thanh toán, 1: Đã thanh toán
public:
    Payment();
    Payment(const string& id, const string& resId, int month, const string& day, int rentAmt, int servAmt, int totalAmt, int stat);
    ~Payment();
    string getID();
    void fromString(const string& line);
    friend ostream& operator<<(ostream& os, const Payment& p);
    static void addPayment(LinkedList<Payment>& paymentList);
    static void searchPaymentByID(LinkedList<Payment>& paymentList);
    static void updatePayment(LinkedList<Payment>& paymentList);
    static void deletePayment(LinkedList<Payment>& paymentList);
    static void showAllPayments(LinkedList<Payment>& paymentList);
};
#endif
