#ifndef PAYMENTSTATISTICS_H
#define PAYMENTSTATISTICS_H

#include "Payment.h"
#include "admin.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>

class PaymentStatistics
{
public:
    PaymentStatistics();
    static void showRevenueStatistics();
    static void showMonthlyComparison(int year, QChart *chart, Admin* adminWindow);
    static void showYearlyComparison(int startYear, int endYear, QChart *chart, Admin* adminWindow);
    static double calculateTotalBilled(int month, int year);
    static double calculateTotalCollected(int month, int year);
};

#endif // PAYMENTSTATISTICS_H
