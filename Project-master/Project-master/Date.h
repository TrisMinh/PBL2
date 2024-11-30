#ifndef DATE_H
#define DATE_H

#include <iomanip>
#include <string>
#include <QDate>

using namespace std;

class DATE {
private:
protected:
    int day, month, year;
    void adjust();
public:
    void fromString(const string& dateStr);
    void fromQDate(const QDate& qdate);
    DATE(int d = 0, int m = 0, int year = 0);
    int get_year() const;
    int get_month() const;
    int get_day() const;
    bool is_nam_nhuan(int year);
    int day_in_month(int month, int year);
    string toString() const {
        ostringstream oss;
        oss << setw(2) << setfill('0') << day << '/'
            << setw(2) << setfill('0') << month << '/'
            << year;
        return oss.str();
    }
    DATE& operator ++(); // tien to
    DATE operator ++(int); // hau to

    DATE& operator --(); //tien to
    DATE operator --(int); //hauto

    DATE operator +(int days) const; //const de khong thay doi d1 truoc dau +
    DATE operator -(int days) const; // tuong tu cai tren
    int operator -(DATE& other);

    int toDays();

    DATE addMonths(int months) const;

    bool operator<(const DATE& other) const;
    bool operator>(const DATE& other) const;
    bool operator<=(const DATE& other) const;
    bool operator>=(const DATE& other) const;
    bool operator==(const DATE& other) const;
    bool operator!=(const DATE& other) const;
};

#endif // DATE_H
