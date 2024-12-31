#include "User.h"
#include "RoomType.h"
#include "Room.h"
#include "Service.h"
#include "ServiceUsage.h"
#include "Reservation.h"
#include "Contract.h"
#include "PaymentStatistics.h"
#include "Payment.h"
#include "Menu.h"
using namespace std;

void User::displayTenantMenu() {
    cout << "\n========= TENANT MENU =========" << endl;
    cout << "    Current UserID: " << Account::currentTenantID << endl;
    Payment::checkUnpaidPayments(Account::currentTenantID);
    Service::notifyNewService();
    cout << "  1. Account Management" << endl;
    cout << "  2. Make Room Reservation" << endl;
    cout << "  3. View My Room" << endl;
    cout << "  4. Contract Management" << endl;
    cout << "  5. Service Management" << endl;
    cout << "  6. Payment Management" << endl;
    cout << "  0. Sign Out" << endl;
    cout << "===============================" << endl;
}

void User::controlTenantMenu() {
    int choice;
    do {
        displayTenantMenu();
        cout << "Please select an option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int select;
                do {
                    cout << "\n-- Account Management --" << endl
                         << "   1. View Personal Information" << endl
                         << "   2. Update Personal Information" << endl
                         << "   3. Change Password" << endl
                         << "   0. Back to Main Menu" << endl;
                    cout << "Please select an option: "; cin >> select;
                    switch (select) {
                        case 1: 
                            Tenant::resetHeader();
                            cout << *Tenant::tenantList.searchID(Account::currentTenantID); 
                            break;
                        case 2: Tenant::updateTenant(); break;
                        case 3: Account::changePassword(); break;
                        case 0: cout << "Exiting Account Management." << endl; break;
                        default: cout << "Invalid selection. Please try again." << endl; break;
                    }
                } while (select != 0);
                break;
            }
            case 2: Reservation::addReservation(); break;
            case 3: Room::searchRoomByTenantID(Account::currentTenantID); break;
            case 4: {
                int contractChoice;
                do {
                    cout << "\n=== Contracts Management ===" << endl;
                    cout << "1. View Active Contracts" << endl;
                    cout << "2. Contracts History" << endl;
                    cout << "3. Extension Contract" << endl;
                    cout << "4. Terminate Contract" << endl;
                    cout << "0. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> contractChoice;
                    switch(contractChoice) {
                        case 1: Contract::searchByTenantID(Account::currentTenantID,1); break;
                        case 2: Contract::searchByTenantID(Account::currentTenantID,0); break;
                        case 3: Contract::extensionContract(); break;
                        case 4: Contract::deleteContract(); break;
                        case 0: break;
                        default: cout << "Invalid choice. Please try again." << endl;
                    }
                } while(contractChoice != 0);
                break;
            }
            case 5: {
                int serviceChoice;
                do {
                    cout << "\n=== Service Management ===" << endl;
                    cout << "1. View Service Usage" << endl;
                    cout << "2. Register New Service" << endl;
                    cout << "3. Stop Using Service" << endl;
                    cout << "0. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> serviceChoice;
                    switch(serviceChoice) {
                        case 1: ServiceUsage::searchByTenantID(Account::currentTenantID); break;
                        case 2: ServiceUsage::addServiceUsage(); break;
                        case 3: ServiceUsage::stopService(); break;
                        case 0: break;
                        default: cout << "Invalid choice. Please try again." << endl;
                    }
                } while(serviceChoice != 0);
                break;
            }
            case 6: {
                int paymentChoice;
                do {
                    cout << "\n=== Payment Management ===" << endl;
                    cout << "1. View Payment Status" << endl;
                    cout << "2. Pay Bill" << endl;
                    cout << "0. Back" << endl;
                    cout << "Enter your choice: ";
                    cin >> paymentChoice;
                    switch(paymentChoice) {
                        case 1: Payment::searchByTenantID(Account::currentTenantID); break;
                        case 2: Payment::managePayments(); break;
                        case 0: break;
                        default: cout << "Invalid choice. Please try again." << endl;
                    }
                } while(paymentChoice != 0);
                break;
            }
            case 0:
                cout << "Logging out..." << endl;
                updateAllFile();
                Account::currentTenantID = ""; 
                displayLoginMenu();
                return;
            default: 
                cout << "Invalid selection. Please try again." << endl;
                break;
        }
    } while (choice != 0);
} 