#include <iostream>
#include "LIB/LinkedList.h"
#include "LIB/RoomType.h"
#include "LIB/Room.h"
#include "LIB/Tenant.h"
#include "LIB/Reservation.h"
#include "LIB/Service.h"
#include "LIB/ServiceUsage.h"
#include "LIB/Payment.h"
int main() {
    LinkedList<RoomType> roomtypeList;          roomtypeList.load("Data/RoomType.txt");
    LinkedList<Room> roomList;                  roomList.load("Data/Room.txt");
    LinkedList<Tenant> tenantList;              tenantList.load("Data/Tenant.txt");
    LinkedList<Service> serviceList;            serviceList.load("Data/Service.txt");
    LinkedList<ServiceUsage> serviceusageList;  serviceusageList.load("Data/ServiceUsage.txt");
    LinkedList<Reservation> reservationList;    reservationList.load("Data/Reservation.txt");
    LinkedList<Payment> paymentList;            paymentList.load("Data/Payment.txt");
    // cout << "Danh sach roomtype" << endl;
    // roomtypeList.show();
    cout << "Danh sach cac phong" << endl;
    roomList.show();
    roomList.deleteNode("R.008");
    roomList.show();
    // cout << "Danh sach nguoi thue" << endl;
    // tenantList.show();
    // cout << "Danh sach Reservation" << endl;
    // reservationList.show();
    // cout << "Danh sach service" << endl;
    // serviceList.show();
    // cout << "Danh sach ServiceUsage" << endl;
    // serviceusageList.show();
    // cout << "Danh sach bill" << endl;
    // paymentList.show();
    return 0;
}
