#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "Date.h"
#include "LinkedList.h"
#include "Contract.h"
#include "ServiceUsage.h"
#include "Createpayment.h"

using namespace std;

class Payment {
private:
    string paymentID,roomID,tenantID;
    double rentAmount, serviceAmount, totalAmount;
    DATE payDate;
    int billMonth, billYear;
    bool status; // 0: pending, 1: paid
    double depositAmount;
public:
    static int total;
    static int currentNumber;
    static LinkedList<Payment> paymentList;
    static bool is_header_printed;
    static void resetHeader();

    Payment();
    Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount, double totalAmount, int payMonth, int payYear, bool status = 0);
    ~Payment();

    static string generateID(int number);

    string getID() const;
    string getRoomID() const;
    string getTenantID() const;
    double getRentAmount() const;
    double getServiceAmount() const;
    double getTotalAmount() const;
    DATE getpayDate() const;
    int getPayMonth() const;
    int getPayYear() const;
    bool getStatus() const;
    double getdepositAmount() const;
    int getBillMonth () const;
    int getBillYear() const;

    void fromString(const string& line);
    string toString() const;

    static bool createPayment(int billMonth, int billYear, Createpayment* adminWindow);
    static void autocreatePayment(int billMonth, int billYear);
    friend ostream& operator<<(ostream& os, const Payment& p);

    static void load(const string& filename);
    static void updateFile(const string& filename);

    static void showAllPayments(Admin* adminWindow);

    static void searchByMonth(int month, int year, Admin* adminWindow);
    static double calculateProRatedRent(double fullRentAmount, int startDay, int billMonth, int billYear);

    void makePayment();
    double getRemainingAmount() const { return totalAmount - depositAmount; }
    static void managePayments();
    // Statistics

    // Thống kê doanh thu
    static void showRevenueStatistics();

    // Tính toán doanh thu
    static double calculateTotalBilled(int month, int year);
    static double calculateTotalCollected(int month, int year);
    static bool isValidPaymentDate(const DATE& paymentDate, const Contract& contract);
    static bool isPaymentExist(const string& roomID, const string& tenantID, int billMonth, int billYear);

    // Hiển thị so sánh
    static void showMonthlyComparison(int year);
    static void showYearlyComparison(int startYear, int endYear);

    static void searchByTenantID(string tenantID);

    static void checkUnpaidPayments(const string& tenantID);
    void display(Admin* adminWindow) const;
};

#endif // PAYMENT_H
