#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    string room_ID;
    string tenant_ID;
    string manager_ID;
    string room_Description;
    int room_Type;
    int room_Status;
    int room_Price;
    double room_Area;

    static int get_price_from_type(int type) {
        switch (type) {
        case 1:
            return 100;
        case 2:
            return 200;
        default:
            return 0;
        }
    }

    static int get_area_from_type(int area) {
        switch (area) {
        case 1:
            return 10;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

    string get_status(int status) {
        switch (status)
        {
        case 1:
            return "Rented!!";
            break;
        
        default:
            return "Empty!!";
            break;
        }
    }
public:
    Room() 
        : room_ID(""), tenant_ID("None"), manager_ID(""), room_Description("None"),
          room_Type(0), room_Status(0), room_Price(get_price_from_type(0)) {}

    Room(string id, string manager, int type, int status, string tenant = "None", string description = "None")
        : room_ID(id), tenant_ID(tenant), manager_ID(manager), room_Description(description),
          room_Type(type), room_Status(status), room_Price(get_price_from_type(type)), room_Area(get_area_from_type(type)) {}

    // Toán tử << cho lớp Room
    friend ostream& operator<<(ostream& os, Room& room) {
        os << " Room ID: " << room.room_ID
           << ", Tenant ID: " << room.tenant_ID
           << ", Manager ID: " << room.manager_ID
           << ", Description: " << room.room_Description
           << ", Type: " << room.room_Type
           << ", Status: " << room.get_status(room.room_Status)
           << ", Price: " << room.room_Price
           << ", Area: " << room.room_Area;
        cout << endl;
        return os;
    }
};

#endif // ROOM_H
