#include <iostream>
#include "LIB/RoomType.h"
#include "LIB/Source/LinkedList.cpp"
#include "LIB/Source/Room.cpp"
#include "LIB/Source/Tenant.cpp"
#include "LIB/Source/Reservation.cpp"
#include "LIB/Source/Service.cpp"
#include "LIB/Source/ServiceUsage.cpp"
#include "LIB/Source/Payment.cpp"
#include "Menu.h"

int main() {
    LinkedList<RoomType> roomtypeList;          roomtypeList.load("Data/RoomType.txt");
    LinkedList<Room> roomList;                  roomList.load("Data/Room.txt");
    LinkedList<Tenant> tenantList;              tenantList.load("Data/Tenant.txt");
    LinkedList<Service> serviceList;            serviceList.load("Data/Service.txt");
    LinkedList<ServiceUsage> serviceusageList;  serviceusageList.load("Data/ServiceUsage.txt");
    LinkedList<Reservation> reservationList;    reservationList.load("Data/Reservation.txt");
    LinkedList<Payment> paymentList;            paymentList.load("Data/Payment.txt");
    displayMenu(roomList, tenantList, serviceList, serviceusageList, reservationList, paymentList);

    return 0;
}