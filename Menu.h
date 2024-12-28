#ifndef MENU_H
#define MENU_H

#include "RoomType.h"
#include "Room.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "PaymentStatistics.h"
#include "Payment.h"
#include "Admin.h"
#include "User.h"

// update all file
void updateAllFile() {
    RoomType::updateFile("Data/RoomType.txt");
    Room::updateFile("Data/Room.txt");
    Tenant::updateFile("Data/Tenant.txt");
    Service::updateFile("Data/Service.txt");
    ServiceUsage::updateFile("Data/ServiceUsage.txt");
    Reservation::updateFile("Data/Reservation.txt"); 
    Contract::updateFile("Data/Contract.txt");
    Payment::updateFile("Data/Payment.txt");
}


void displayLoginMenu() {
    int choice;
    do {
        cout << "\n========= LOGIN MENU =========" << endl;
        cout << "  1. Sign in" << endl;
        cout << "  2. Sign up" << endl;
        cout << "  0. Exit Program" << endl;
        cout << "==============================" << endl;
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: // Sign in
                if (Account::signin()) {
                    cout << "Login as: " << (Account::currentrole == 1 ? "Admin" : "Tenant") << endl;
                    if (Account::currentrole == 1) {
                        Admin admin; // Khởi tạo đối tượng Admin
                        admin.controlAdminMenu();
                    } else {
                        User user; // Khởi tạo đối tượng User
                        user.controlTenantMenu();
                    }
                } 
                break;
            case 2: // Sign up
                Account::signup(); 
                break;
            case 0: // Exit program
                cout << "Exiting program. Thank you!" << endl;
                exit(0);
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
        }
    } while (choice != 0); 
}

#endif