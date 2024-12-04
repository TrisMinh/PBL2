#ifndef PAYMENT_H
#define PAYMENT_H
#include "ServiceUsage.h"
#include "Service.h"

class Contract;

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
        Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount,
             double totalAmount, int billMonth, int billYear, bool status = 0);
        ~Payment();

        static string generateID(int number);

        string getID() const;
        string getRoomID() const;
        string getTenantID() const;
        double getRentAmount() const;
        double getServiceAmount() const;
        double getTotalAmount() const;
        double getDepositAmount() const;
        double getRemainingAmount() const;
        int getBillMonth () const;
        int getBillYear() const;

        void fromString(const string& line);
        string toString() const;

        static void autocreatePayment();

        friend ostream& operator<<(ostream& os, const Payment& p);

        static void load(const string& filename);
        static void updateFile(const string& filename);

        static void showAllPayments();

        static void searchByMonth();

        void makePayment();
        static void managePayments();
        

        static void searchByTenantID(string tenantID);

        static void checkUnpaidPayments(const string& tenantID);
        static bool checkUnpaidPaymentForRoom(const string& tenantID, const string& roomID);

        static double calculateProRatedRent(double fullRentAmount, int startDay, int billMonth, int billYear);

        static bool isPaymentExist(const string& roomID, const string& tenantID, int billMonth, int billYear);

        static bool isValidPaymentDate(const DATE& paymentDate, const Contract& contract);
};
#include "Payment.cpp"
#endif