#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string.h>
#include "LIB/Header/LinkedList.h"
#include "LIB/RoomType.h"
#include "LIB/Source/LinkedList.cpp"
#include "LIB/Source/Room.cpp"
#include "LIB/Source/Tenant.cpp"
#include "LIB/Source/Reservation.cpp"
#include "LIB/Source/Service.cpp"
#include "LIB/Source/ServiceUsage.cpp"
#include "LIB/Source/Payment.cpp"
using namespace std;

void displayAdminMenu() {
    cout << "========= ROOM MANAGEMENT SYSTEM MENU =========" << endl
     << "1. Room Management " << endl
     << "   1.1 Add New Room " << endl
     << "   1.2 Edit Room Information " << endl
     << "   1.3 Delete Room " << endl
     << "   1.4 Display Room List " << endl
     << "2. Tenant Management" << endl
     << "   2.1 Add New Tenant" << endl
     << "   2.2 Edit Tenant Information" << endl
     << "   2.3 Delete Tenant" << endl
     << "   2.4 Display Tenant List" << endl
     << "3. Service Management" << endl
     << "   3.1 Add New Service" << endl
     << "   3.2 Edit Service Information" << endl
     << "   3.3 Delete Service" << endl
     << "   3.4 Display Service List" << endl
     << "4. Service Usage Management" << endl
     << "   4.1 Record Service Usage" << endl
     << "   4.2 Display Service Usage" << endl
     << "5. Reservation Management" << endl
     << "   5.1 Create New Reservation" << endl
     << "   5.2 Update Reservation" << endl
     << "   5.3 Display Reservations" << endl
     << "6. Payment Management" << endl
     << "   6.1 Create Payment Invoice" << endl
     << "   6.2 Display Payment Status" << endl
     << "7. Maintenance Management" << endl
     << "   7.1 Add Maintenance Request" << endl
     << "   7.2 Display Maintenance Requests" << endl
     << "8. Reports and Statistics" << endl
     << "   8.1 Room Status Report" << endl
     << "   8.2 Revenue Report" << endl
     << "0. Exit" << endl
     << "===============================================" << endl;
}
void controlAdminMenu(LinkedList<Room>& roomList, LinkedList<Tenant>& tenantList, LinkedList<Service>& serviceList, LinkedList<ServiceUsage>& serviceusageList, LinkedList<Reservation>& reservationList, LinkedList<Payment>& paymentList) {
    int choice;
    do {
        displayAdminMenu();
        cout << "Please select an option: ";
        cin >> choice;
        switch(choice) {
            case 1: { // Room Management
                int select;
                do {
                    cout << "You selected Room Management." << endl
                         << "   1. Add New Room" << endl
                         << "   2. Edit Room Information" << endl
                         << "   3. Delete Room" << endl
                         << "   4. Display Room List" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            Room::addRoom(roomList);
                            break;
                        case 2:
                            Room::updateRoom(roomList);
                            break;
                        case 3: 
                            Room::deleteRoom(roomList);
                            break;
                        case 4: {
                            Room::showAllRooms(roomList);
                            break;
                        }
                        case 0:
                            cout << "Exiting Room Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 2: { // Tenant Management
                int select;
                do {
                    cout << "You selected Tenant Management." << endl
                         << "   1. Add New Tenant" << endl
                         << "   2. Edit Tenant Information" << endl
                         << "   3. Delete Tenant" << endl
                         << "   4. Display Tenant List" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            Tenant::addTenant(tenantList);
                            break;
                        case 2:
                            Tenant::updateTenant(tenantList);
                            break;
                        case 3: 
                            Tenant::deleteTenant(tenantList);
                            break;
                        case 4: 
                            Tenant::showAllTenants(tenantList);
                            break;
                        case 0:
                            cout << "Exiting Tenant Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 3: { // Service Management
                int select;
                do {
                    cout << "You selected Service Management." << endl
                         << "   1. Add New Service" << endl
                         << "   2. Edit Service Information" << endl
                         << "   3. Delete Service" << endl
                         << "   4. Display Service List" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            Service::addService(serviceList);
                            break;
                        case 2:
                            Service::updateService(serviceList);
                            break;
                        case 3: 
                            Service::deleteService(serviceList);
                            break;
                        case 4:
                            Service::showAllServices(serviceList);  
                            break;
                        case 0:
                            cout << "Exiting Service Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 4: { // Service Usage Management
                int select;
                do {
                    cout << "You selected Service Usage Management." << endl
                         << "   1. Record Service Usage" << endl
                         << "   2. Display Service Usage" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // ServiceUsage::recordUsage(serviceusageList);
                            break;
                        case 2:
                            ServiceUsage::showAllServiceUsages(serviceusageList);
                            break;
                        case 0:
                            cout << "Exiting Service Usage Management." << endl;
                            break;
                        default:
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 5: { // Reservation Management
                int select;
                do {
                    cout << "You selected Reservation Management." << endl
                         << "   1. Create New Reservation" << endl
                         << "   2. Update Reservation" << endl
                         << "   3. Display Reservations" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            //Reservation::addReservation( roomList, reservationList);
                            break;
                        case 2:
                            //Reservation::updateReservation(reservationList);
                            break;
                        case 3:
                            //Reservation::showAllReservations(reservationList);
                            break;
                        case 0:
                            cout << "Exiting Reservation Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 6: { // Payment Management
                int select;
                do {
                    cout << "You selected Payment Management." << endl
                         << "   1. Create Payment Invoice" << endl
                         << "   2. Display Payment Status" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            Payment::addPayment(paymentList);
                            break;
                        case 2:
                            Payment::showAllPayments(paymentList);
                            break;
                        case 0:
                            cout << "Exiting Payment Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 7: { // Maintenance Management
                int select;
                do {
                    cout << "You selected Maintenance Management." << endl
                         << "   1. Add Maintenance Request" << endl
                         << "   2. Display Maintenance Requests" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // Maintenance::addRequest(maintenanceList);
                            break;
                        case 2:
                            // maintenanceList.showRequests();
                            break;
                        case 0:
                            cout << "Exiting Maintenance Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 8: { // Reports and Statistics
                int select;
                do {
                    cout << "You selected Reports and Statistics." << endl
                         << "   1. Room Status Report" << endl
                         << "   2. Revenue Report" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // Report::generateRoomStatus();
                            break;
                        case 2:
                            // Report::generateRevenue();
                            break;
                        case 0:
                            cout << "Exiting Reports and Statistics." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                            break;
                    }
                } while(select != 0);
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
        }
    } while (choice != 0);
}



void displayTenantMenu() {
    cout << "========= GUEST MENU =========" << endl
         << "1. View Room Information" << endl
         << "2. View Rental Contract" << endl
         << "3. View Payment Status" << endl 
         << "4. Request Maintenance" << endl
         << "5. View Personal Information" << endl
         << "6. Update Personal Information" << endl
         << "0. Exit" << endl
        << "===============================" << endl;
}

void controlTenantMenu() {

}

void displayMenu(LinkedList<Room>& roomList,LinkedList<Tenant>& tenantList,  LinkedList<Service>& serviceList, LinkedList<ServiceUsage>& serviceusageList, LinkedList<Reservation>& reservationList, LinkedList<Payment>& paymentList) {
    bool rollcheck;
    cout << "Who are you? (0:Admin | 1:Tenant)" << endl;
    cin >> rollcheck;
    if (rollcheck == 0) {
        controlAdminMenu(roomList,tenantList,serviceList,serviceusageList,reservationList,paymentList);
    }
    else {
        controlTenantMenu();
    }
}

   

#endif