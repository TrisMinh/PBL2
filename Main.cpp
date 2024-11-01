#include <iostream>
#include "LinkedList.h"
#include "Room.h"
#include "Tenant.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "Room.h"


// #include "Payment.cpp"
#include "Menu.h"

int main() {
    RoomType::load("Data/RoomType.txt");
    Room::load("Data/Room.txt");
    Tenant::load("Data/Tenant.txt");
    Service::load("Data/Service.txt");
    ServiceUsage::load("Data/ServiceUsage.txt");
    Reservation::load("Data/Reservation.txt");
    Contract::load("Data/Contract.txt");
    // LinkedList<Payment> paymentList;            paymentList.load("Data/Payment.txt");
    displayMenu();
    
    return 0;
}