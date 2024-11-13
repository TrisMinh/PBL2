#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string.h>
#include "LinkedList.h"
#include "Room.h"
#include "Tenant.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "Account.h"


// #include "Payment.cpp"
using namespace std;

void displayAdminMenu() {
    cout << "\n========= ROOM MANAGEMENT SYSTEM MENU =========" << endl;
    cout << "             Current TenantID: " << Account::currentTenantID << endl;
    cout << "  1. Room Management " << endl;
    cout << "  2. Tenant Management" << endl;
    cout << "  3. Service Management" << endl;
    cout << "  4. Service Usage Management" << endl;
    cout << "  5. Reservation Management" << endl;
    cout << "  6. Payment Management (Not)" << endl;
    cout << "  7. Maintenance Management (Not)" << endl;
    cout << "  8. Reports and Statistics (Not)" << endl;
    cout << "  9. RoomType Management" << endl;
    cout << "  10. Contract Management" << endl;
    cout << "  11. Update All File" << endl;
    cout << "  12. Set AdminCode" << endl;
    cout << "  0. Exit" << endl;
    cout << "===============================================" << endl;
}

// Hàm điều khiển menu cho admin
void controlAdminMenu() {
    int choice;
    do {
        displayAdminMenu();
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Room Management
                int select;
                do {
                    cout << "\n-- Room Management --" << endl
                         << "   1. Add New Room" << endl
                         << "   2. Edit Room Information" << endl
                         << "   3. Delete Room" << endl
                         << "   4. Display Room List" << endl
                         << "   5. Search Room" << endl
                         << "   6. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: Room::addRoom(); break;
                        case 2: Room::updateRoom(); break;
                        case 3: Room::deleteRoom(); break;
                        case 4: Room::showAllRooms(); break;
                        case 5: Room::searchAll(); break;
                        case 6: Room::updateFile("Data/Room.txt"); break;
                        case 0: cout << "Exiting Room Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 2: { // Tenant Management
                int select;
                do {
                    cout << "\n-- Tenant Management --" << endl
                         << "   1. Add New Tenant" << endl
                         << "   2. Edit Tenant Information" << endl
                         << "   3. Delete Tenant" << endl
                         << "   4. Display Tenant List" << endl
                         << "   5. Search Tenant" << endl
                         << "   6. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: Tenant::addTenant(); break;
                        case 2: Tenant::updateTenant(); break;
                        case 3: Tenant::deleteTenant(); break;
                        case 4: Tenant::showAllTenants(); break;
                        case 5: Tenant::searchAll(); break;
                        case 6: Tenant::updateFile("Data/Tenant.txt"); break;
                        case 0: cout << "Exiting Tenant Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 3: { // Service Management
                int select;
                do {
                    cout << "\n-- Service Management --" << endl
                         << "   1. Add New Service" << endl
                         << "   2. Edit Service Information" << endl
                         << "   3. Delete Service" << endl
                         << "   4. Display Service List" << endl
                         << "   5. Search Service" << endl
                         << "   6. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: Service::addService(); break;
                        case 2: Service::updateService(); break;
                        case 3: Service::deleteService(); break;
                        case 4: Service::showAllServices(); break;
                        case 5: Service::searchAll(); break;
                        case 6: Service::updateFile("Data/Service.txt"); break;
                        case 0: cout << "Exiting Service Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 4: { // Service Usage Management
                int select;
                do {
                    cout << "\n-- Service Usage Management --" << endl
                         << "   1. Add New Service Usage" << endl
                         << "   2. Edit Service Usage Information" << endl
                         << "   3. Delete Service Usage" << endl
                         << "   4. Display Service Usage List" << endl
                         << "   5. Search Service Usage" << endl
                         << "   6. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: ServiceUsage::addServiceUsage(); break;
                        case 2: ServiceUsage::updateServiceUsage(); break;
                        case 3: ServiceUsage::deleteServiceUsage(); break;
                        case 4: ServiceUsage::showAllServiceUsages(); break;
                        case 5: ServiceUsage::searchAll(); break;
                        case 6: ServiceUsage::updateFile("Data/ServiceUsage.txt"); break;
                        case 0: cout << "Exiting Service Usage Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 5: { // Reservation Management
                int select;
                do {
                    cout << "\n-- Reservation Management --" << endl
                         << "   1. Create New Reservation" << endl
                         << "   2. Edit Reservation Information" << endl
                         << "   3. Delete Reservation" << endl
                         << "   4. Display Reservation List" << endl
                         << "   5. Search Reservation" << endl
                         << "   6. Update File" << endl
                         << "   7. Confirm" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: Reservation::addReservation(); break;
                        case 2: Reservation::updateReservation(); break;
                        case 3: Reservation::deleteReservation(); break;
                        case 4: Reservation::showAllReservations(); break;
                        case 5: Reservation::searchAll(); break;
                        case 6: Reservation::updateFile("Data/Reservation.txt"); break;
                        case 7: Contract::confirmReservationandcreatContract(); break;
                        case 0: cout << "Exiting Reservation Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 6: { // Payment Management
                int select;
                do {
                    cout << "\n-- Payment Management --" << endl
                         << "   1. Create Payment Invoice" << endl
                         << "   2. Display Payment Status" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // Payment::addPayment(paymentList);
                            break;
                        case 2:
                            // Payment::showAllPayments(paymentList);
                            break;
                        case 0: cout << "Exiting Payment Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 7: { // Maintenance Management
                int select;
                do {
                    cout << "\n-- Maintenance Management --" << endl
                         << "   1. Schedule Maintenance" << endl
                         << "   2. Display Maintenance Status" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // Maintenance::scheduleMaintenance();
                            break;
                        case 2:
                            // Maintenance::showAllMaintenance();
                            break;
                        case 0: cout << "Exiting Maintenance Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 8: { // Reports and Statistics
                cout << "\n-- Reports and Statistics --" << endl;
                // Implement your report functionality here
                break;
            }
            case 9: { // RoomType Management
                int select;
                do {
                    cout << "\n-- RoomType Management --" << endl
                         << "   1. Add New RoomType" << endl
                         << "   2. Edit RoomType Information" << endl
                         << "   3. Delete RoomType" << endl
                         << "   4. Display RoomType List" << endl
                         << "   5. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: RoomType::addRoomType(); break;
                        case 2: RoomType::updateRoomType(); break;
                        case 3: RoomType::deleteRoomType(); break;
                        case 4: RoomType::showAllRoomTypes(); break;
                        case 6: RoomType::updateFile("Data/RoomType.txt"); break;
                        case 0: cout << "Exiting RoomType Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 10: { // Contract Management
                int select;
                do {
                    cout << "\n-- Contract Management --" << endl
                         << "   1. Delete Contract" << endl
                         << "   2. Display Contract List" << endl
                         << "   3. Update File" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1: Contract::deleteContract(); break;
                        case 2: Contract::showAllContracts(); break;
                        case 3: Contract::updateFile("Data/Contract.txt"); break;
                        case 0: cout << "Exiting Contract Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 11: 
                RoomType::updateFile("Data/RoomType.txt");
                Room::updateFile("Data/Room.txt");
                Tenant::updateFile("Data/Tenant.txt");
                Service::updateFile("Data/Service.txt");
                ServiceUsage::updateFile("Data/ServiceUsage.txt");
                Reservation::updateFile("Data/Reservation.txt"); 
                Contract::updateFile("Data/Contract.txt");
                break;
            case 12:
                Account::setAdminCode();
                break;
            case 0: cout << "Exiting program. Thank you!" << endl; break;
            default: cout << "Invalid selection. Please try again." << endl; break;
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
         << "7. Search" << endl
         << "0. Exit" << endl
        << "===============================" << endl;
}

void controlTenantMenu() {
    int choice;
    do {
        displayTenantMenu();
        cout << "Please select an option: ";
        cin >> choice;
        switch(choice) {
            case 7:{
                int h1choice;
                do {
                    cout << "   1. Room" << endl
                         << "   2. Reservation" << endl
                         << "   3. Payment" << endl
                         << "   0. Exit" << endl;
                     cin >> h1choice;
                    switch (h1choice) {
                        case 1:
                            Room::searchAll();
                            break;
                        case 2:
                            //reservationList.searchAll(reservationList);
                            break;
                        case 3:
                            //paymentList.searchAll(paymentList);
                            break;
                    } 
                } while (h1choice!=0);
                break;
            }
                
            case 0:
                cout << "Exit" << endl;
                break; 
        } 
    } while (choice != 0);
}

void displayMenu() {
    bool rollcheck;
    cout << "Who are you? (0:Admin | 1:Tenant)" << endl;
    cin >> rollcheck;
    if (rollcheck == 0) {
        controlAdminMenu();
    }
    else {
        controlTenantMenu(); 
    }
}

void displayLoginMenu() {
    int choice;
    do {
        cout << "\n========= LOGIN MENU =========" << endl;
        cout << "  1. Sign in" << endl;
        cout << "  2. Sign up" << endl;
        cout << "  0. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: // Sign in
                if (Account::signin()) {
                    choice  = 0;
                    controlAdminMenu();
                } 
                break;
            case 2: // Sign up
                Account::signup();
                break;
            case 0:
                cout << "Exiting program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
        }
    } while (choice != 0);
}   




#endif