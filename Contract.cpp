#include "Contract.h"

// Static Element
int Contract::currentNumber = 0;
int Contract::total = 0;
LinkedList<Contract> Contract::contractList;
bool Contract::is_header_printed = false;
void Contract::resetHeader() { is_header_printed = false; }

// Constructors
Contract::Contract() : Reservation() {this->reservation_ID = "Empty"; this->contractID = "Empty";}
Contract::Contract(const string& roomID, const string& tenantID,
                   const DATE& start, const DATE& end, int status)
    : Reservation() {
    this->contractID = generateID(++currentNumber);
    this->room_ID = roomID;
    this->tenant_ID = tenantID;
    this->startDate = start;
    this->endDate = end;
    this->status = status;
    this->rentprice = Reservation::getPrice();
}
Contract::~Contract() {}

// ID Generate
string Contract::generateID(int number) {
    stringstream ss;
    ss << "CT." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Load function
void Contract::load(const string& filename) { contractList.load(filename); }
void Contract::updateFile(const string& filename) { contractList.updateFile(filename); }

// Get function
string Contract::getID() const { return contractID; }
DATE Contract::getStartDate() const { return startDate; }
DATE Contract::getEndDate() const { return endDate; }
double Contract::getPrice() const { return Reservation::getPrice(); } 
bool Contract::getStatus() const { return status; }

// Set function
void Contract::setStartDate(const DATE& startDate) { this->startDate = startDate; }
void Contract::setEndDate(const DATE& endDate) { this->endDate = endDate; }
void Contract::setPrice(double rprice) { this->rentprice = rprice; }
void Contract::setStatus(bool status) { this->status = status; }

// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void Contract::fromString(const string& line) {
    stringstream ss(line);
    string startDateStr, endDateStr;
    getline(ss, contractID, ',');          // Đọc mã hợp đồng
    getline(ss, room_ID, ',');             // Đọc mã phòng
    getline(ss, tenant_ID, ',');           // Đọc mã khách thuê
    getline(ss, startDateStr, ',');        // Đọc ngày bắt đầu dưới dạng chuỗi
    getline(ss, endDateStr, ',');          // Đọc ngày kết thúc dưới dạng chuỗi
    ss >> staytime;                        // Đọc thời gian lưu trú
    ss.ignore(1, ',');                     // Bỏ qua dấu phẩy
    ss >> status;                          // Đọc trạng thái
    ss.ignore(1, ',');                     // Bỏ qua dấu phẩy
    ss >> rentprice;     
    startDate.fromString(startDateStr);    // Chuyển chuỗi ngày bắt đầu thành đối tượng DATE
    endDate.fromString(endDateStr);        // Chuyển chuỗi ngày kết thúc thành đối tượng DATE

    total++;                               // Tăng số lượng hợp đồng tổng
}

// Ham chuyen thanh chuoi de ghi du lieu vao file
string Contract::toString() const {
    stringstream ss;
    ss << contractID << ',' 
       << room_ID << ','           // Mã phòng
       << tenant_ID << ','         // Mã khách thuê
       << startDate.toString() << ',' // Chuyển đổi ngày bắt đầu sang chuỗi
       << endDate.toString() << ','   // Chuyển đổi ngày kết thúc sang chuỗi
       << staytime << ','        
       << status << ','            // Trạng thái của hợp đồng
       << fixed << setprecision(2) << rentprice; // Giá tiền
    return ss.str();
}

// Chuc nang co ban (Basic Function)

void Contract::deleteContract() {
    if (Account::currentrole == 1) {
        resetHeader();
        contractList.show();
        string roomIDtodelete;
        cout << "Nhap RoomID ban muon huy thue hoac nhap '0' de thoat: "; cin >> roomIDtodelete;
        if (roomIDtodelete == "0") { return; }
        
        Room* room = Room::roomList.searchID(roomIDtodelete);
        if (!room) {
            cout << "Khong tim thay phong!\n";
            return;
        }
        
        Contract* ct = Contract::searchByRidAndTid(roomIDtodelete, room->getTenantID());
        if (ct == nullptr) {
            cout << "Khong tim thay hop dong!\n";
            return;
        }

        cout << "Ban muon huy thue phong " << roomIDtodelete << "?" << endl
             << "1. Yes" << endl
             << "2. No" << endl;
        int choice;
        cout << "Lua chon cua ban: "; cin >> choice;
        if (choice == 1) {
            room->resetRoom();
            ct->setStatus(0);
            total--;
            cout << "Da huy thue phong thanh cong!\n";
        }
    } else {
        // Original code for regular users
        Room::searchRoomByTenantID(Account::currentTenantID);
        string roomIDtodelete;
        cout << "Nhap RoomID ban muon huy thue hoac nhap '0' de thoat: "; cin >> roomIDtodelete;
        if (roomIDtodelete == "0") { return; }
        
        Contract* ct = Contract::searchByRidAndTid(roomIDtodelete, Account::currentTenantID);
        if (ct == nullptr) {
            cout << "Khong tim thay hop dong!\n";
            return;
        }
        
        if (Room::roomList.searchID(roomIDtodelete)->getTenantID() == Account::currentTenantID) {
            cout << "Ban muon huy thue phong " << roomIDtodelete << "?" << endl
                 << "1. Yes" << endl
                 << "2. No" << endl;
            int choice;
            cout << "Lua chon cua ban: "; cin >> choice;
            if (choice == 1) {
                Room::roomList.searchID(roomIDtodelete)->resetRoom();
                ct->setStatus(0);
                total--;
                cout << "Da huy thue phong thanh cong!\n";
            }
        } else {
            cout << "Phong voi ID: " << roomIDtodelete << " khong duoc thue hoac khong phai cua ban." << endl;
        }
    }
}

void Contract::extensionContract() {
    resetHeader();
    Contract::searchByTenantID(Account::currentTenantID);
    int extenmonth;
    string roomIDtoextend;
    DATE extendate;
    cout << "Nhap RoomID ban muon gia han thue hoac nhap '0' de thoat: "; cin >> roomIDtoextend;
    Contract* ct = Contract::searchByRidAndTid(roomIDtoextend, Account::currentTenantID);
    if (roomIDtoextend == "0") { return; }
    else if ( ct != nullptr && ct->getStatus() ==1 ) {
        cout << "So thang ban muon gia han them thue hoac nhap '0' de thoat: "; cin >> extenmonth;
        while (extenmonth < 0) { cout << "So thang khong hop le, vui long nhap lai: "; cin >> extenmonth; }
        if (extenmonth == 0) { return; }
        extendate = ct->getEndDate();
        extendate = extendate.addMonths(extenmonth);
        ct->setStaytime(extendate.toDays() - ct->getStartDate().toDays());
        ct->setEndDate(extendate);
        cout << "Gia han thanh cong phong " << ct->getRoomID() << " den ngay " << ct->getEndDate() << endl;
    }
    else {
        cout << "Nhap sai hoac Hop dong khong the gia han." << endl;
    }

}

// Show all contracts
void Contract::showAllContracts() {
    resetHeader();
    cout << "Danh sach tat ca cac phong:" << endl;
    contractList.show();
    cout << "1. Sap xep ID tang dan" << endl
         << "2. Sap xep ID giam dan" << endl
         << "0. Thoat" << endl;
    int choice;
    cout << "Lua chon cua ban: "; cin >> choice;
    switch (choice) {
        case 1: contractList.sortByID(true); showAllContracts(); break;
        case 2: contractList.sortByID(false); showAllContracts(); break;
        default: break;
    }
}

void Contract::addContract(const string& roomID, const string& tenantID,
                            const DATE& start, const DATE& end, int status) {
    Contract newContract(roomID, tenantID, start, end, status);
    contractList.add(newContract);
    cout << "Contract added: " << newContract.getID() << endl;
    total++;
}

Contract* Contract::searchByRidAndTid(const string& rid, const string& tid) {
    resetHeader();
    LinkedList<Contract>::Node* current = contractList.begin();
    while (current!= nullptr) { 
        if (current->data.getRoomID() == rid && current->data.getTenantID() == tid) {
            return &(current->data);
        }
        current = current->next;    
    }
    return nullptr;
}

void Contract::searchByTenantID(const string& id) {
    resetHeader();
    int count = 0;
    LinkedList<Contract>::Node* current = contractList.begin();
    if (current == nullptr) { cout << "Khong tim thay hop dong nao" << endl; return; }
    while (current!= nullptr) {
        if (current->data.getTenantID() == id && current->data.status == 1) {
            cout << current->data; count++;
        }
        current = current->next;
    }
    if (count == 0) { cout << "Khong tim thay hop dong nao! "<< endl; }
}

void Contract::confirmReservationandcreatContract() {
    resetHeader();
    int choice;
    string tempRE;
    do {
        resetHeader();
        Reservation::reservationList.searchStatus(0);
        do {
            cout << "Enter ReservationID to manage (or type '0' to quit): "; cin >> tempRE;
            if (tempRE == "0") {
                cout << "Exiting Reservation Confirm." << endl;
                break;
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
                    re->setStatus(1);
                    ro->setStatus(1); 
                    ro->setTenantID(re->getTenantID());
                    cout << "Reservation confirmed." << endl;
                    addContract(re->getRoomID(),re->getTenantID(),re->getStartDate(),re->getEndDate(),1);
                    ServiceUsage::registerMandatoryServices(re->getRoomID(),re->getTenantID());
                } else {
                    cout << "Invalid Reservation ID or Room ID." << endl;
                }
                break;
            }   
            case 2: {
                Reservation* re = reservationList.searchID(tempRE);
                Room* ro = Room::roomList.searchID(re->getRoomID());
                if (re) {
                    re->setStatus(2); 
                    ro->setStatus(0);
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

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Contract& c) {
    const int w_id = 12, w_room_id = 12, w_roomtype = 30, w_tenantid = 10, w_name = 25, w_age = 10,w_cccd = 15, w_phone = 15, w_start_date = 15, w_end_date = 15, w_price = 10, w_status = 10;

    Room* r = Room::roomList.searchID(c.room_ID);
    Tenant* t = Tenant::tenantList.searchID(c.tenant_ID);
    
    if (!Contract::is_header_printed) {
        os << left
           << setw(w_id) << "ContractID" << " | "
           << setw(w_room_id) << "RoomID" << " | "
           << setw(w_roomtype) << "RoomType" << " | "
           << setw(w_tenantid) << "TenantID" << " | "
           << setw(w_name) << "Name" << " | "
           << setw(w_age) << "Age" << " | "
           << setw(w_cccd) << "CCCD" << " | "
           << setw(w_phone) << "Phone" << " | "
           << setw(w_start_date) << "Start Date" << " | "
           << setw(w_end_date) << "End Date" << " | "
           << setw(w_price + 12) << "Price" << " | "
           << setw(w_status) << "Status" << endl;

        os << setfill('-')
           << setw(w_id + w_room_id + w_roomtype + w_tenantid + w_name + w_age + w_cccd + w_phone + w_start_date + w_end_date + w_price + w_status + 45) << ""
           << setfill(' ') << endl;

        Contract::is_header_printed = true;
    }

    os << left
       << setw(w_id) << c.contractID << " | "
       << setw(w_room_id) << c.room_ID << " | "
       << setw(w_roomtype) << r->getRoomType()->getName() << " | "
       << setw(w_tenantid) << c.tenant_ID << " | "
       << setw(w_name) << t->getFullName() << " | "
       << setw(w_age) << t->getAge() << " | "
       << setw(w_cccd) << t->getCCCD() << " | "
       << setw(w_phone) << t->getPhone() << " | "
       << setw(w_start_date) << c.startDate.toString() << " | "
       << setw(w_end_date) << c.endDate.toString() << " | "
       << setw(w_price) << fixed << setprecision(2) << c.rentprice << " VND/1 month" << " | "
       << setw(w_status) << (c.status == 1 ? "Active" : "Expired") << endl;
    return os;
}



