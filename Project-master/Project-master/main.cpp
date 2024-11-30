#include "admin.h"
#include "Login.h"
// #include "Test.h"
// #include "Menu.h"
#include "RoomType.h"
#include "Room.h"
#include "Tenant.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Payment.h"
#include "Contract.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    RoomType::load("RoomType.txt");
    Room::load();
    // Room::showAllRooms();
    // Test::read();
    // Account::load("E:\\GUI\\Data\\Account.txt");
    // RoomType::load("E:\\GUI\\Data\\RoomType.txt");
    // Room::load();
    Tenant::load("Tenant.txt");
    Service::load("Service.txt");
    ServiceUsage::load("ServiceUsage.txt");
    Reservation::load("Reservation.txt");
    Account::load("Account.txt");
    Payment::load("Payment.txt");
    Contract::load("Contract.txt");
    // displayMenu(roomList, tenantList, serviceList, serviceusageList, reservationList, paymentList);
    // Room::showAllRooms(roomList);

    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
    // return 0;
}
