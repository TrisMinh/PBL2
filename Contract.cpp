#include "Contract.h"

// Khởi tạo biến tĩnh
int Contract::currentNumber = 0;
int Contract::total = 0;
LinkedList<Contract> Contract::contractList;

// Constructors
Contract::Contract() : Reservation(), contractID(""), price(0.0) {}
Contract::Contract(const string& roomID, const string& tenantID,
                   const DATE& start, const DATE& end, int status, double price)
    : Reservation() {
    this->contractID = generateID(++currentNumber);
    this->room_ID = roomID;
    this->tenant_ID = tenantID;
    this->startDate = start;
    this->endDate = end;
    this->status = status;
    this->price = price;
    total++;
}


// Destructor
Contract::~Contract() {}

// Generate contract ID
string Contract::generateID(int number) {
    stringstream ss;
    ss << "CT." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Getters
string Contract::getID() const { return contractID; }
string Contract::getReservationID() const { return reservation_ID; } // Getter cho reservationID
DATE Contract::getStartDate() const { return startDate; }
DATE Contract::getEndDate() const { return endDate; }
double Contract::getPrice() const { return price; } // Getter cho giá tiền

// Setters
void Contract::setStartDate(const DATE& startDate) { this->startDate = startDate; }
void Contract::setEndDate(const DATE& endDate) { this->endDate = endDate; }
void Contract::setPrice(double price) { this->price = price; }

// Convert contract to string
string Contract::toString() const {
    stringstream ss;
    ss << contractID << ',' 
       << room_ID << ','           // Mã phòng
       << tenant_ID << ','         // Mã khách thuê
       << reservation_ID << ','    // ID của đặt phòng
       << startDate.toString() << ',' // Chuyển đổi ngày bắt đầu sang chuỗi
       << endDate.toString() << ','   // Chuyển đổi ngày kết thúc sang chuỗi
       << staytime << ','          // Thời gian lưu trú
       << status << ','            // Trạng thái của hợp đồng
       << fixed << setprecision(2) << price; // Giá tiền
    return ss.str();
}


// Convert string to contract
void Contract::fromString(const string& line) {
    stringstream ss(line);
    string startDateStr, endDateStr;

    getline(ss, contractID, ',');          // Đọc mã hợp đồng
    getline(ss, room_ID, ',');             // Đọc mã phòng
    getline(ss, tenant_ID, ',');           // Đọc mã khách thuê
    getline(ss, reservation_ID, ',');      // Đọc ID của đặt phòng
    getline(ss, startDateStr, ',');        // Đọc ngày bắt đầu dưới dạng chuỗi
    getline(ss, endDateStr, ',');          // Đọc ngày kết thúc dưới dạng chuỗi
    ss >> staytime;                        // Đọc thời gian lưu trú
    ss.ignore(1, ',');                     // Bỏ qua dấu phẩy
    ss >> status;                          // Đọc trạng thái
    ss.ignore(1, ',');                     // Bỏ qua dấu phẩy
    ss >> price;                           // Đọc giá tiền

    startDate.fromString(startDateStr);    // Chuyển chuỗi ngày bắt đầu thành đối tượng DATE
    endDate.fromString(endDateStr);        // Chuyển chuỗi ngày kết thúc thành đối tượng DATE

    total++;                               // Tăng số lượng hợp đồng tổng
}


// Load contracts from file
void Contract::load(const string& filename) {
    contractList.load(filename);
}

void Contract::addContract(const string& roomID, const string& tenantID,
                            const DATE& start, const DATE& end, int status, double price) {
    Contract newContract(roomID, tenantID, start, end, status, price);
    contractList.add(newContract);
    cout << "Contract added: " << newContract.getID() << endl;
}

void Contract::confirmReservationandcreatContract() {
    int choice;
    string tempRE;
    do {
        Reservation::reservationList.searchStatus(1);
        do {
            cout << "Enter ReservationID to manage (or type '0' to quit): "; 
            cin >> tempRE;
            
            // Kiểm tra nếu nhập '0' để thoát
            if (tempRE == "0") {
                cout << "Exiting Reservation Confirm." << endl;
                break;
            }
            
            // Kiểm tra nếu không bắt đầu bằng "RS"
            if (tempRE.substr(0, 2) != "RS") {
                cout << "Invalid ReservationID. It must start with 'RS'. Please try again." << endl;
                continue;
            }
            if (Reservation::reservationList.searchID(tempRE) == NULL) { 
            cout << "ReservationID does not exist. Please try again." << endl;
            }
        } while (Reservation::reservationList.searchID(tempRE) == NULL);
        if (tempRE == "0") {
            cout << "Exiting Reservation Confirm." << endl;
            break;  
        }
        cout << "   1. Confirm" << endl
             << "   2. Reject"  << endl
             << "   0. Exit" << endl;  
        cout << "Please select an option: "; cin >> choice;
        switch (choice) {
            case 1: {
                Reservation* re = reservationList.searchID(tempRE);
                Room* ro = Room::roomList.searchID(re->getRoomID());
                if (re && ro) {
                    if (ro->getStatus() == 1) {
                        cout << "Room was rented!" << endl;
                        break;
                    }
                    re->setStatus(0); // Confirm reservation
                    ro->setStatus(1); // Mark room as occupied
                    ro->setTenantID(re->getTenantID());
                    cout << "Reservation confirmed." << endl;
                    addContract(re->getRoomID(),re->getTenantID(),re->getStartDay(),re->getEndDate(),1,ro->getroomtype().getPrice());
                } else {
                    cout << "Invalid Reservation ID or Room ID." << endl;
                }
                break;
            }   
            case 2: {
                Reservation* re = reservationList.searchID(tempRE);
                if (re) {
                    re->setStatus(2); // Reject reservation
                    cout << "Reservation rejected." << endl;
                } else {
                    cout << "Invalid Reservation ID." << endl;
                }
                break;
            }
            case 0: 
                cout << "Exiting Reservation Confirm." << endl; 
                break;
            default: 
                cout << "Invalid selection. Please try again." << endl; 
                break;
        }
    } while (choice != 0);
}




// Edit an existing contract
// void Contract::editContract() {
//     string id;
//     cout << "Nhap Contract ID de chinh sua: "; cin >> id;
//     Contract* contract = contractList.searchID(id);
//     if (contract) {
//         cout << "Editing contract: " << id << endl;
//         // Cập nhật thông tin (như startDate, endDate, price, ...)
//         // Cụ thể tùy thuộc vào thông tin bạn muốn sửa
//         string newStartDate, newEndDate;
//         cout << "Enter new start date: ";
//         cin >> newStartDate;
//         cout << "Enter new end date: ";
//         cin >> newEndDate;

//         contract->setStartDate(newStartDate);
//         contract->setEndDate(newEndDate);
//         // Cập nhật giá nếu cần
//         cout << "Contract updated." << endl;
//     } else {
//         cout << "Contract ID not found." << endl;
//     }
// }

// Delete a contract
void Contract::deleteContract() {
    string contractID;
    cout << "Nhap Contract ID de xoa: ";
    cin >> contractID;
    contractList.deleteNode(contractID);
    cout << "Contract deleted successfully!" << endl;
    total--;
}

// Show all contracts
void Contract::showAllContracts() {
    cout << "Danh sach hop dong:" << endl;
    contractList.show();
}

// Update contract information in file
void Contract::updateFile(const string& filename) {
    contractList.load(filename);
}

// Operator overloading for displaying contract information
ostream& operator<<(ostream& os, const Contract& c) {
    Tenant* t = Tenant::tenantList.searchID(c.tenant_ID);
    Room* r = Room::roomList.searchID(c.room_ID);
    os << "     --------------------------------\n"
       << "     Contract ID: " << c.contractID << endl
       << "     Room ID: " << c.room_ID << endl
       << "     RoomType: " << r->getroomtype().getDescription() << endl
       << "     Tenant ID: " << c.tenant_ID << endl 
       << "     Name: " << t->getName() << endl
       << "     Age: " << t->getAge() << endl
       << "     CCCD: " << t->getCCCD() << endl
       << "     Phone: " << t->getCCCD() << endl
       << "     Start Date: " << c.startDate.toString() << endl 
       << "     End Date: " << c.endDate.toString() << endl 
       << "     Price: " << fixed << setprecision(2) << c.price << " VND/ 1 month\n" 
       << "     --------------------------------\n";
    return os;
}

