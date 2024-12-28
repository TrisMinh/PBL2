#include "Admin.h"
#include "RoomType.h"
#include "Room.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "PaymentStatistics.h"
#include "Payment.h"
#include "Menu.h"

void Admin::displayAdminMenu() {
    cout << "\n========= ROOM MANAGEMENT SYSTEM MENU =========" << endl;
    cout << "             Current UserID: " << Account::currentTenantID << endl;
    Reservation::checkNewReservations();
    cout << "  1. Room Management " << endl;
    cout << "  2. Tenant Management" << endl;
    cout << "  3. Service Management" << endl;
    cout << "  4. Service Usage Management" << endl;
    cout << "  5. Reservation Management" << endl;
    cout << "  6. Payment Management " << endl;
    cout << "  7. Reports and Statistics " << endl;
    cout << "  8. Contract Management" << endl;
    cout << "  9. Account Management" << endl;
    cout << "  0. Sign Out" << endl;
    cout << "===============================================" << endl;
}

void Admin::controlAdminMenu() {
    int choice;
    do {
        displayAdminMenu();
        cout << "Please select an option: "; cin >> choice;
        switch (choice) {
            case 1: { // Room Management
                int select;
                do {
                    cout << "\n-- Room Management --" << endl
                         << "   1. Add New Room" << endl
                         << "   2. Edit Room Information" << endl
                         << "   3. Delete Room" << endl
                         << "   4. Display Room List" << endl
                         << "   5. RoomType Management" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Room::addRoom(); break;
                        case 2: Room::updateRoom(); break;
                        case 3: Room::deleteRoom(); break;
                        case 4: Room::showAllRooms(); break;
                        case 5: { // RoomType Management
                            int select;
                            do {
                                cout << "\n-- RoomType Management --" << endl
                                    << "   1. Add New RoomType" << endl
                                    << "   2. Edit RoomType Information" << endl
                                    << "   3. Delete RoomType" << endl
                                    << "   4. Display RoomType List" << endl
                                    << "   0. Back to Main Menu" << endl;
                                cout << "Please select an option: "; cin >> select;
                                switch (select) {
                                    case 1: RoomType::addRoomType(); break;
                                    case 2: RoomType::updateRoomType(); break;
                                    case 3: RoomType::deleteRoomType(); break;
                                    case 4: RoomType::showAllRoomTypes(); break;
                                    case 0: cout << "Exiting RoomType Management." << endl; break;
                                    default: cout << "Invalid selection. Please try again." << endl; break;
                                }
                            } while (select != 0);
                            break;
                        }
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
                         << "   1. Edit Tenant Information" << endl
                         << "   2. Display Tenant List" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Tenant::updateTenant(); break;
                        case 2: Tenant::showAllTenants(); break;
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
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Service::addService(); break;
                        case 2: Service::updateService(); break;
                        case 3: Service::deleteService(); break;
                        case 4: Service::showAllServices(); break;
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
                         << "   1. Display Service Usage List" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: ServiceUsage::showAllServiceUsages(); break;
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
                         << "   1. Display Reservation List" << endl
                         << "   2. Confirm Reservation" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Reservation::showAllReservations(); break;
                        case 2: Contract::confirmReservationandcreatContract(); break;
                        case 0: cout << "Exiting Reservation Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 6: { // Payment Management
                int select;
                do {
                    cout << "-- Payment Management --" << endl
                         << "   1. Auto Create Payment" << endl
                         << "   2. Display Payment List" << endl
                         << "   3. Pay Bill" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Payment::autocreatePayment(); break;
                        case 2: Payment::showAllPayments(); break;
                        case 3: Payment::managePayments(); break;
                        case 0: cout << "Exiting Payment Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 7: { // Reports and Statistics
                cout << "\n-- Reports and Statistics --" << endl;
                PaymentStatistics::showRevenueStatistics();
                break;
            }
            case 8: { // Contract Management
                int select;
                do {
                    cout << "\n-- Contract Management --" << endl
                         << "   1. Terminate Contract" << endl
                         << "   2. Display Contract List" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Contract::deleteContract(); break;
                        case 2: Contract::showAllContracts(); break;
                        case 0: cout << "Exiting Contract Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 9: { // Account Management
                int select;
                do {
                    cout << "\n-- Account Management --" << endl
                         << "   1. Display All Accounts" << endl
                         << "   2. Change Admin Code" << endl
                         << "   3. Change Current Password" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: Account::showAllAccount(); break;
                        case 2: Account::setAdminCode(); break;
                        case 3: Account::changePassword(); break;
                        case 0: cout << "Exiting Account Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 0: 
                cout << "Logging out..." << endl;
                updateAllFile();
                Account::currentTenantID = ""; 
                displayLoginMenu(); 
                return; 
            default: cout << "Invalid selection. Please try again." << endl; break;
        }
    } while (choice != 0);
} 