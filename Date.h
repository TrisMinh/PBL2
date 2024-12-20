#ifndef Date_h
#define Date_h
#include <iostream>
#include <iomanip>
using namespace std;

class DATE {
private:
protected:
    int day, month, year;
    void adjust(); // ham xu ly
public:
    void fromString(const string& dateStr);
    DATE(int d = 0, int m = 0, int year = 0);
    int get_year() const;
    int get_month() const;
    int get_day() const;
    bool is_nam_nhuan(int year);
    int day_in_month(int month, int year);
    friend ostream &operator <<(ostream &os,const DATE &date);
    friend istream &operator >>(istream &is, DATE &date); // const :chi in ra khong thay doi
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

    // Khai báo nguyên mẫu các toán tử so sánh
    bool operator<(const DATE& other) const;
    bool operator>(const DATE& other) const;
    bool operator<=(const DATE& other) const;
    bool operator>=(const DATE& other) const;
    bool operator==(const DATE& other) const;
    bool operator!=(const DATE& other) const;
};
#include "Date.cpp"
#endif