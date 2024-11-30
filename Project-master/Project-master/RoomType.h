#ifndef ROOMTYPE_H
#define ROOMTYPE_H
#include <string>
#include "LinkedList.h"
#include "admin.h"

class Admin;
class RoomType
{
protected:
    string type_ID;
    string name;
    string description;
    double price;
public:
    friend class Admin;
    string getID() const;
    double getPrice() const;
    string getDescription() const;
    string getName() const;

    void setTypeID(const string& id);
    void setDescription(const string& desc);
    void setPrice(double price);
    void setName(const string& name);

    static LinkedList<RoomType> roomTypeList;
    static int total;
    static int currentNumber;

    RoomType();
    RoomType(const string& desc, double price, const string& name = "Standard Room");
    ~RoomType();
    // static void searchByID();
    static string generateID(int number);
    static void load(const string& filename);

    void fromString(const string& line);
    string toString() const;

    static void addRoomType(const string& name, const string& desc, double price);
    static void updateRoomType(const string& id, const string& name, const string& desc, double price);
    static void deleteRoomType(const string& id);
    static void showAllRoomTypes(Admin* adminWindow);

    static bool isActive(string& id);
    static void searchByID(const string& id, Admin* adminWindow);
    static void searchByName(const string& name, Admin* adminWindow);
    static void searchByPrice(const string& price, Admin* adminWindow);
    static void searchAll();

    void display(Admin* adminWindow) const;
};

#endif // ROOMTYPE_H
