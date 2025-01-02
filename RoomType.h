#ifndef ROOMTYPE_H
#define ROOMTYPE_H
#include "LinkedList.h"
#include "Base.h"

class RoomType {
private:
    string type_ID;         // ID của loại phòng
    string name;           // Tên loại phòng
    string description;     // Mô tả loại phòng
    double price;          // Giá phòng
    string generateID(int number);
public:
    // Static members
    static int total;      
    static int currentNumber; 
    static LinkedList<RoomType> roomTypeList;
    static bool is_header_printed;

    RoomType(); 
    RoomType(const string& desc, double price, const string& name = "Standard Room");
    ~RoomType();

    static bool isActive(string& id);

    // Getters
    string getID() const;
    string getDescription() const;
    double getPrice() const;
    string getName() const;

    // Setters
    void setTypeID(const string& id);
    void setDescription(const string& desc);
    void setPrice(double price);
    void setName(const string& name);

    // Convert functions
    void fromString(const string& line);
    string toString() const;

    // IO functions
    static void load(const string& filename);
    static void updateFile(const string& filename);
    
    // Basic functions
    static void addRoomType();
    static void updateRoomType();
    static void deleteRoomType();
    static void showAllRoomTypes();

    // Search functions
    static void searchByID();
    static void searchByPrice();
    static void searchByName();
    static void searchAll();

    // Title control
    static void resetHeader();

    friend ostream& operator<<(ostream& os, const RoomType& rt);
};

#include "RoomType.cpp"

#endif
