#include "Menu.h"
int main() {
    Account::load("Data/Account.txt");
    RoomType::load("Data/RoomType.txt");
    Room::load("Data/Room.txt");
    Tenant::load("Data/Tenant.txt");
    Service::load("Data/Service.txt");
    ServiceUsage::load("Data/ServiceUsage.txt");
    Reservation::load("Data/Reservation.txt");
    Contract::load("Data/Contract.txt");
    Payment::load("Data/Payment.txt");
    displayLoginMenu();    
    return 0;
}