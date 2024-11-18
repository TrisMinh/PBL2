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

};



#include "Payment.cpp"
#endif