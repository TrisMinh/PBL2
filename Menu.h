#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string.h>
#include "LIB/LinkedList.h"
#include "LIB/RoomType.h"
#include "LIB/Room.h"
#include "LIB/Tenant.h"
#include "LIB/Reservation.h"
#include "LIB/Service.h"
#include "LIB/ServiceUsage.h"
#include "LIB/Payment.h"
using namespace std;

void displayAdminMenu() {
    cout << "========= ROOM MANAGEMENT SYSTEM MENU =========" << endl
         << "1. Room Management" << endl
         << "   1.1 Add New Room" << endl
         << "   1.2 Edit Room Information" << endl
         << "   1.3 Delete Room" << endl
         << "   1.4 Display Room List" << endl
         << "2. Tenant Management" << endl
         << "   2.1 Add New Tenant" << endl
         << "   2.2 Edit Tenant Information" << endl
         << "   2.3 Delete Tenant" << endl
         << "   2.4 Display Tenant List" << endl
         << "3. Rental Contract Management" << endl
         << "   3.1 Create New Rental Contract" << endl
         << "   3.2 Update Rental Contract" << endl
         << "   3.3 Display Rental Contracts" << endl
         << "4. Payment Management" << endl
         << "   4.1 Create Payment Invoice" << endl
         << "   4.2 Display Payment Status" << endl
         << "5. Maintenance Management" << endl
         << "   5.1 Add Maintenance Request" << endl
         << "   5.2 Display Maintenance Requests" << endl
         << "6. Reports and Statistics" << endl
         << "   6.1 Room Status Report" << endl
         << "   6.2 Revenue Report" << endl
         << "0. Exit" << endl
         << "===============================================" << endl;
}
void controlAdminMenu(LinkedList<Room>& roomList, LinkedList<Tenant>& tenantList) {
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
                        case 4:
                            int sortchoice;
                            Room::showAllRooms(roomList);
                            do {
                                cout << "1. Sap xep tang dan" << endl
                                     << "2. Sap xep giam dan" << endl
                                     << "0. Exit" << endl;
                                cout << "Please select an option: ";
                                cin >> sortchoice;
                                switch (sortchoice) {
                                    case 1:
                                        roomList.sortByID(true);
                                        Room::showAllRooms(roomList);
                                        break;
                                    case 2:
                                        roomList.sortByID(false);
                                        Room::showAllRooms(roomList);
                                        break;
                                    case 0:
                                        cout << "Exit" << endl;
                                    default:
                                        break;

                                }
                            } while (sortchoice!=0);
                            break;
                        case 0:
                            cout << "Exiting Room Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
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
                            //Tenant::addTenant(tenantList); 
                            break;
                        case 2:
                            // Chỉnh sửa thông tin người thuê
                            break;
                        case 3: {
                            string deleteid;
                            cout << "Enter the ID of the tenant you want to delete: ";
                            cin >> deleteid;
                            tenantList.deleteNode(deleteid); 
                            break;
                        }
                        case 4:
                            tenantList.show();  
                            break;
                        case 0:
                            cout << "Exiting Tenant Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                    }
                } while(select != 0);
                break;
            }
            case 3: { // Rental Contract Management
                int select;
                do {
                    cout << "You selected Rental Contract Management." << endl
                         << "   1. Create New Contract" << endl
                         << "   2. Edit Contract" << endl
                         << "   3. Delete Contract" << endl
                         << "   4. Display Contract List" << endl
                         << "   0. Exit" << endl;
                    cout << "Please select an option: ";
                    cin >> select;
                    switch (select) {
                        case 1:
                            // Tạo hợp đồng thuê
                            break;
                        case 2:
                            // Chỉnh sửa hợp đồng
                            break;
                        case 3:
                            // Xóa hợp đồng
                            break;
                        case 4:
                            // Hiển thị danh sách hợp đồng
                            break;
                        case 0:
                            cout << "Exiting Contract Management." << endl;
                            break;
                        default:
                            cout << "Invalid selection. Please try again." << endl;
                    }
                } while(select != 0);
                break;
            }
            case 4: { // Payment Management
                // Thêm các chức năng liên quan đến quản lý thanh toán
                cout << "Payment Management is selected." << endl;
                break;
            }
            case 5: { // Maintenance Management
                // Thêm các chức năng liên quan đến quản lý bảo trì
                cout << "Maintenance Management is selected." << endl;
                break;
            }
            case 6: { // Reports and Statistics
                // Thêm các chức năng liên quan đến báo cáo và thống kê
                cout << "Reports and Statistics is selected." << endl;
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
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

void displayMenu(LinkedList<Room>& roomList,LinkedList<Tenant>& tenantList) {
    bool rollcheck;
    cout << "Who are you? (0:Admin | 1:Tenant)" << endl;
    cin >> rollcheck;
    if (rollcheck == 0) {
        controlAdminMenu(roomList,tenantList);
    }
    else {
        controlTenantMenu();
    }
}

   

#endif