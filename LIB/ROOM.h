#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "RoomType.h"
using namespace std;

class Room {
    string room_ID;
    string type_ID;
    int status;
    static int total_room;

    string tenant_ID;
public:
    Room() {}
    Room(const string& id, const string& typeId, int s, const string& tenantId = "") 
        : room_ID(id), type_ID(typeId), status(s), tenant_ID(tenantId) {
        total_room++;
    }
    ~Room() {
        total_room--;
    }
    string getID() {return room_ID;}
    void fromString(const string& line) { //Nhập tt từ file
        stringstream ss(line);
        getline(ss, room_ID, ',');
        getline(ss, type_ID, ',');
        ss >> status;
        ss.ignore(1);  // Bỏ qua dấu phẩy sau status
        if (ss.peek() != EOF) {// Đọc tenant_ID nếu có
            getline(ss, tenant_ID, ',');
        } else {
            tenant_ID = "";  // Để trống nếu không có tenant_ID
        }
    } 
    friend ostream& operator<<(ostream& os, const Room& r) {
        os << "Room [ID: " << r.room_ID << ", Type ID: " << r.type_ID
        << ", Status: " << r.status << ", Tenant ID: " << (r.tenant_ID.empty() ? "N/A" : r.tenant_ID) << "]\n";
        return os;
    }

    static void addRoom(LinkedList<Room>& roomList) {
        string room_ID, type_ID, tenant_ID;
        int status;
        // Nhập thông tin cho phòng mới
        cout << "Nhap thong tin phong:" << endl;
        cout << "Room ID: ";
        cin >> room_ID;
        cout << "Type ID: ";
        cin >> type_ID;
        cout << "Status (0: Trong, 1: Dang su dung): ";
        cin >> status;
        cout << "Tenant ID (de trong neu khong co): ";
        cin.ignore(); // Xóa bộ đệm
        getline(cin, tenant_ID);
        Room newRoom(room_ID, type_ID, status, tenant_ID);// Tạo đối tượng Room mới và thêm vào danh sách
        roomList.add(newRoom);
        cout << "Room Added!!" << endl;
    }
    static void searchRoomByID(LinkedList<Room>& roomList) {
        string roomID;
        cout << "Nhap Room ID de tim kiem ";
        cin >> roomID;

        Room* room = roomList.search(roomID);
        if (room) {
            cout << "Da tim thay: " << *room << endl;
        } else {
            cout << "Khong tim thay phong voi ID: " << roomID << endl;
        }
    }
};
int Room::total_room = 0;

#endif
