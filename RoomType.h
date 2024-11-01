#ifndef ROOMTYPE_H
#define ROOMTYPE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

class RoomType {
protected:
    string type_ID;         // ID của loại phòng
    string description;     // Mô tả loại phòng
    double price;           // Giá phòng
public:
    static int total;       // Tổng số loại phòng
    static int currentNumber; // Số lượng loại phòng hiện tại
    static LinkedList<RoomType> roomTypeList;

    // Constructors
    RoomType(); 
    RoomType(const string& desc, double price);
    RoomType(const string id, const string& desc, double price);
    
    // Destructor
    ~RoomType();

    // Methods for data handling
    void fromString(const string& line);
    string toString() const;
    string generateID(int number);
    
    // Getters
    string getID() const;
    string getDescription() const;
    double getPrice() const;

    // Setters
    void setTypeID(const string& id);
    void setDescription(const string& desc);
    void setPrice(double price);

    // Static methods for RoomType management
    static void load(const string& filename);
    static void addRoomType();
    static void updateRoomType();
    static void deleteRoomType();
    static void updateFile(const string& filename);
    static void showAllRoomTypes();
    static void searchByID();
    static void searchAll();

    // Overloaded output operator
    friend ostream& operator<<(ostream& os, const RoomType& rt);
};

#include "RoomType.cpp"

#endif
