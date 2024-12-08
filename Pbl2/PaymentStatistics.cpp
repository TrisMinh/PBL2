#include "PaymentStatistics.h"
#include "admin.h"

PaymentStatistics::PaymentStatistics() {}

void PaymentStatistics::showMonthlyComparison(int year, QChart *chart, Admin* adminWindow) {
    double maxBilled = 0;
    for (int month = 1; month <= 12; month++) {
        double billed = calculateTotalBilled(month, year);
        if (billed > maxBilled) maxBilled = billed;
    }

    double roundTo = 10.0;
    maxBilled = ceil(maxBilled / roundTo) * roundTo;

    QBarSeries *series = new QBarSeries();

    QBarSet *set1 = new QBarSet("Tổng hóa đơn");
    QBarSet *set2 = new QBarSet("Đã thu");
    QBarSet *set3 = new QBarSet("Chưa thu");
    // set1->setLabelColor(Qt::black);
    // set2->setLabelColor(Qt::black);
    // set3->setLabelColor(Qt::black);

    QStringList Sub;

    for (int month = 1; month <= 12; month++) {
        double totalBilled = calculateTotalBilled(month, year);
        double totalCollected = calculateTotalCollected(month, year);

        Sub.append("Tháng " + QString::number(month));
        set1->append(totalBilled);
        set2->append(totalCollected);
        set3->append((totalBilled - totalCollected));
        adminWindow->displayMonthlyComparison(month, totalBilled, totalCollected, totalBilled - totalCollected);
    }

    series->append(set1);
    series->append(set2);
    series->append(set3);
    // series->setLabelsVisible(true);
    // series->setLabelsAngle(-90);
    // series->setLabelsFormat("@value VND");
    // series->setLabelsPrecision(10);
    // series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);

    chart->addSeries(series);
    chart->setTitle("Biểu đồ doanh thu các tháng trong năm " + QString::number(year));
    chart->setAnimationDuration(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Sub);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxBilled);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->setLabelFormat("%.0f VND");
}

void PaymentStatistics::showYearlyComparison(int startYear, int endYear, QChart *chart, Admin* adminWindow) {
    double maxYearlyBilled = 0;
    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
        }
        if (yearlyBilled > maxYearlyBilled) maxYearlyBilled = yearlyBilled;
    }

    double roundTo = 10.0;
    maxYearlyBilled = ceil(maxYearlyBilled / roundTo) * roundTo;

    QBarSeries *series = new QBarSeries();

    QBarSet *set1 = new QBarSet("Tổng hóa đơn");
    QBarSet *set2 = new QBarSet("Đã thu");
    QBarSet *set3 = new QBarSet("Chưa thu");
    // set1->setLabelColor(Qt::black);
    // set2->setLabelColor(Qt::black);
    // set3->setLabelColor(Qt::black);

    QStringList Sub;

    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        double yearlyCollected = 0;

        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
            yearlyCollected += calculateTotalCollected(month, year);
        }

        Sub.append("Năm " + QString::number(year));
        set1->append(yearlyBilled);
        set2->append(yearlyCollected);
        set3->append(yearlyBilled - yearlyCollected);
        adminWindow->displayYearlyComparison(year, yearlyBilled, yearlyCollected, yearlyBilled - yearlyCollected);
    }
    series->append(set1);
    series->append(set2);
    series->append(set3);
    // series->setLabelsVisible(true);
    // series->setLabelsAngle(-90);
    // series->setLabelsFormat("@value VND");
    // series->setLabelsPrecision(10);
    // series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);

    chart->addSeries(series);
    chart->setTitle("Biểu đồ doanh thu từ năm " + QString::number(startYear) + " đến năm " + QString::number(endYear));
    chart->setAnimationDuration(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Sub);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxYearlyBilled);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->setLabelFormat("%.0f VND");
}

double PaymentStatistics::calculateTotalBilled(int month, int year) {
    double total = 0;
    for (LinkedList<Payment>::Node* current = Payment::paymentList.begin();
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getBillMonth() == month && payment.getBillYear() == year) {
            total += payment.getTotalAmount();
        }
    }
    return total;
}

double PaymentStatistics::calculateTotalCollected(int month, int year) {
    double total = 0;
    for (LinkedList<Payment>::Node* current = Payment::paymentList.begin();
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getBillMonth() == month && payment.getBillYear() == year) {
            total += payment.getdepositAmount();
        }
    }
    return total;
}
