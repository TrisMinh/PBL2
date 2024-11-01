#include "Date.h"
using namespace std;

DATE::DATE(int d, int m, int y) :day(d), month(m), year(y) {}

void DATE::fromString(const string& dateStr) {
    stringstream ss(dateStr);
    char delimiter; // Dùng để đọc dấu phân cách '/'
    ss >> day >> delimiter >> month >> delimiter >> year; // Đọc ngày, tháng, năm
    adjust(); // Có thể gọi hàm điều chỉnh nếu cần
}

bool DATE::is_nam_nhuan(int year) {
    return (year %4 == 0 && year %100 !=0) || (year %400 == 0);
}

int DATE::day_in_month(int month, int year) {
    switch (month)
    {
    case 4: case 6: case 9:  case 11: 
        return 30;
        break;
    case 2:
        return is_nam_nhuan(year) ? 29 : 28;
        break;
    default:
        return 31;
        break;
    }
}

void DATE::adjust() {
    while (day > day_in_month(month, year)) {
        day = day - day_in_month(month, year);
        month++;
        if(month > 12) {
            month = 1;
            year++;
        }
    }
    while (day < 1) {
        month--;
        if(month < 1) {
            month = 12;
            year--;
        }
        day = day + day_in_month(month, year);
    }
}

istream &operator >>(istream &is, DATE &date) {
    cout << "Enter day: "; is >> date.day;
    cout << "Enter month: "; is >> date.month;
    cout << "Enter year: "; is >> date.year;
    return is;
} 

ostream &operator <<(ostream &os,const DATE &date) {
    os << (date.day <10 ? "0" : "") << date.day << "/"
       << (date.month <10 ? "0" : "") << date.month << "/"
       << date.year;
    return os;
}
//tt
DATE& DATE::operator++() {
    ++day;
    adjust();
    return *this;
}
//ht
DATE DATE::operator++(int) {
    DATE temp = *this;
    ++(*this);
    return temp;
}
//tt
DATE& DATE::operator--() {
    --day;
    adjust();
    return *this;
}
//ht
DATE DATE::operator--(int) {
    DATE temp = *this;
    --(*this);
    return temp;
}
DATE DATE::operator+(int days) const {
    DATE temp = *this;
    temp.day += days;
    temp.adjust();
    return temp;
}
DATE DATE::operator-(int days) const {
    DATE temp = *this;
    temp.day -= days;
    temp.adjust();
    return temp;
}
