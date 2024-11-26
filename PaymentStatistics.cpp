#include "PaymentStatistics.h"

void PaymentStatistics::showRevenueStatistics() {
    // Kiểm tra xem có dữ liệu payment nào không
    if (Payment::paymentList.begin() == nullptr) {
        cout << "\nKhong co du lieu payment nao trong he thong!" << endl;
        return;
    }

    int choice;
    do {
        cout << "\n=== THONG KE DOANH THU ===\n";
        cout << "1. Xem doanh thu theo thang\n";
        cout << "2. So sanh doanh thu cac thang trong nam\n";
        cout << "3. So sanh doanh thu qua cac nam\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int month, year;
                cout << "Nhap thang (1-12): "; cin >> month;
                if (month < 1 || month > 12) {
                    cout << "Thang khong hop le!" << endl;
                    continue;
                }
                cout << "Nhap nam: "; cin >> year;
                if (year < 2000) {
                    cout << "Nam khong hop le!" << endl;
                    continue;
                }
                
                double totalBilled = calculateTotalBilled(month, year);
                double totalCollected = calculateTotalCollected(month, year);
                
                cout << "\nThong ke thang " << month << "/" << year << ":\n";
                cout << "Tong so tien hoa don: " << fixed << setprecision(2) << totalBilled << endl;
                cout << "Tong so tien da thu: " << totalCollected << endl;
                cout << "So tien chua thu: " << (totalBilled - totalCollected) << endl;
                break;
            }
            case 2: {
                int year;
                cout << "Nhap nam can thong ke: "; cin >> year;
                if (year < 2000) {
                    cout << "Nam khong hop le!" << endl;
                    continue;
                }
                showMonthlyComparison(year);
                break;
            }
            case 3: {
                int startYear, endYear;
                cout << "Nhap nam bat dau: "; cin >> startYear;
                cout << "Nhap nam ket thuc: "; cin >> endYear;
                if (startYear > endYear || startYear < 2000) {
                    cout << "Nam khong hop le!" << endl;
                    continue;
                }
                showYearlyComparison(startYear, endYear);
                break;
            }
        }
    } while (choice != 0);
}

void PaymentStatistics::showMonthlyComparison(int year) {
    cout << "\nSo sanh doanh thu cac thang trong nam " << year << ":\n";
    cout << setw(10) << "Thang" 
         << setw(20) << "Tong hoa don" 
         << setw(20) << "Da thu" 
         << setw(20) << "Chua thu" << endl;
    cout << string(70, '-') << endl;
    
    // Tìm giá trị lớn nhất để scale biểu đồ
    double maxBilled = 0;
    for (int month = 1; month <= 12; month++) {
        double billed = calculateTotalBilled(month, year);
        if (billed > maxBilled) maxBilled = billed;
    }

    for (int month = 1; month <= 12; month++) {
        double totalBilled = calculateTotalBilled(month, year);
        double totalCollected = calculateTotalCollected(month, year);
        
        cout << setw(10) << month 
             << setw(20) << fixed << setprecision(2) << totalBilled 
             << setw(20) << totalCollected
             << setw(20) << (totalBilled - totalCollected);
        
        // Vẽ biểu đồ đơn giản
        cout << "  ";
        int barLength = maxBilled > 0 ? (totalBilled/maxBilled) * 30 : 0;
        cout << string(barLength, '*');
        cout << endl;
    }
}

void PaymentStatistics::showYearlyComparison(int startYear, int endYear) {
    cout << "\nSo sanh doanh thu qua cac nam:\n";
    cout << setw(10) << "Nam" 
         << setw(20) << "Tong hoa don" 
         << setw(20) << "Da thu" 
         << setw(20) << "Chua thu" << endl;
    cout << string(70, '-') << endl;

    double maxYearlyBilled = 0;
    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
        }
        if (yearlyBilled > maxYearlyBilled) maxYearlyBilled = yearlyBilled;
    }

    if (maxYearlyBilled == 0) {
        cout << "Khong co du lieu doanh thu trong khoang thoi gian nay!" << endl;
        return;
    }

    for (int year = startYear; year <= endYear; year++) {
        double yearlyBilled = 0;
        double yearlyCollected = 0;
        
        for (int month = 1; month <= 12; month++) {
            yearlyBilled += calculateTotalBilled(month, year);
            yearlyCollected += calculateTotalCollected(month, year);
        }
        
        cout << setw(10) << year 
             << setw(20) << fixed << setprecision(2) << yearlyBilled 
             << setw(20) << yearlyCollected
             << setw(20) << (yearlyBilled - yearlyCollected);

        // Vẽ biểu đồ
        cout << "  ";
        int barLength = static_cast<int>((yearlyBilled/maxYearlyBilled) * 30);
        cout << string(barLength, '*');
        cout << endl;
    }
}

double PaymentStatistics::calculateTotalBilled(int month, int year) {
    double total = 0;
    for (LinkedList<Payment>::Node* current = Payment::paymentList.begin(); 
         current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getPayMonth() == month && payment.getPayYear() == year) {
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
        if (payment.getPayMonth() == month && payment.getPayYear() == year) {
            total += payment.getDepositAmount();
        }
    }
    return total;
} 