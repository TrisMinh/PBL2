#ifndef PAYMENT_H
#define PAYMENT_H
#include "LinkedList.h"
#include "ServiceUsage.h"
#include "Service.h"
#include "Contract.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Payment {
    private:
        string paymentID,roomID,tenantID;
        double rentAmount, serviceAmount, totalAmount;
        DATE payDate;
        int payMonth, payYear;
        bool status; // 0: pending, 1: paid
        double depositAmount;
    public:
        static int total;
        static int currentNumber;
        static LinkedList<Payment> paymentList;

        Payment();
        Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount,
             double totalAmount, int payMonth, int payYear, bool status = 0);
        ~Payment();

        static string generateID(int number);

        string getID() const;
        string getRoomID() const;
        string getTenantID() const;
        double getRentAmount() const;
        double getServiceAmount() const;
        double getTotalAmount() const;
        int getPayMonth();
        int getPayYear();

        void fromString(const string& line);
        string toString() const;

        static void autocreatePayment();

        friend ostream& operator<<(ostream& os, const Payment& p);

        static void load(const string& filename);
        static void updateFile(const string& filename);

        static void showAllPayments();

        static void searchByMonth();

        void makePayment();
        double getRemainingAmount() const { return totalAmount - depositAmount; }
        static void managePayments();
// Statistics

        // Thống kê doanh thu
        static void showRevenueStatistics();
        
        // Tính toán doanh thu
        static double calculateTotalBilled(int month, int year);
        static double calculateTotalCollected(int month, int year);
        
        // Hiển thị so sánh
        static void showMonthlyComparison(int year);
        static void showYearlyComparison(int startYear, int endYear);

        static void searchByTenantID(string tenantID);
};



#include "Payment.cpp"
#endif