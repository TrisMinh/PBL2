#ifndef PAYMENTSTATISTICS_H
#define PAYMENTSTATISTICS_H
#include "Payment.h"
class PaymentStatistics {
public:
    static void showRevenueStatistics();
    static void showMonthlyComparison(int year);
    static void showYearlyComparison(int startYear, int endYear);
    static double calculateTotalBilled(int month, int year);
    static double calculateTotalCollected(int month, int year);
}; 

#include "PaymentStatistics.cpp"
#endif