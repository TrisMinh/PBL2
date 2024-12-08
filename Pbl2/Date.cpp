#include "Date.h"

using namespace std;

DATE::DATE(int d, int m, int y) :day(d), month(m), year(y) {}

int DATE::get_year() const { return year; };
int DATE::get_month() const { return month; };
int DATE::get_day() const { return day; };

void DATE::fromString(const string& dateStr) {
    stringstream ss(dateStr);
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year; // Đọc ngày, tháng, năm
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

// istream &operator >>(istream &is, DATE &date) {
//     cout << "\nEnter day, month, year: "; is >> date.day >> date.month >> date.year;
//     return is;
// }

// ostream &operator <<(ostream &os,const DATE &date) {
//     os << (date.day <10 ? "0" : "") << date.day << "/"
//        << (date.month <10 ? "0" : "") << date.month << "/"
//        << date.year;
//     return os;
// }
// //tt

void DATE::fromQDate(const QDate &qDate) {
    this->day = qDate.day();
    this->month = qDate.month();
    this->year = qDate.year();
}
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

DATE DATE::addMonths(int months) const {
    DATE temp = *this;
    temp.month += months;

    // Điều chỉnh năm nếu tháng > 12
    while (temp.month > 12) {
        temp.month -= 12;
        temp.year++;
    }

    // Điều chỉnh ngày nếu vượt quá số ngày trong tháng mới
    int max_days = temp.day_in_month(temp.month, temp.year);
    if (temp.day > max_days) {
        temp.day = max_days;
    }

    return temp;
}

int DATE::toDays() {
    int totalDays = day;
    for (int i = 1; i < year; ++i) {
        totalDays += (is_nam_nhuan(i) ? 366 : 365);
    }
    for (int i = 1; i < month; ++i) {
        totalDays += day_in_month(i, year);
    }
    return totalDays;
}

int DATE::operator-(DATE& other)  {
    return this->toDays() - other.toDays();
}


bool DATE::operator<(const DATE& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool DATE::operator>(const DATE& other) const { return other < *this; }
bool DATE::operator<=(const DATE& other) const { return !(other < *this); }
bool DATE::operator>=(const DATE& other) const { return !(*this < other); }
bool DATE::operator==(const DATE& other) const { return (day == other.day && month == other.month && year == other.year); }
bool DATE::operator!=(const DATE& other) const { return !(*this == other); }
