#include "Contract.h"

// Static Element
int Contract::currentNumber = 0;
int Contract::total = 0;
LinkedList<Contract> Contract::contractList;

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
string Contract::getReservationID() const { return reservation_ID; } 
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
    Room::searchRoomByTenantID(Account::currentTenantID);
    string roomIDtodelete;
    cout << "Nhap RoomID ban muon huy thue hoac nhap '0' de thoat: "; cin >> roomIDtodelete;
    if (roomIDtodelete == "0") { return; }
    
    Contract* ct = Contract::searchByRidAndTid(roomIDtodelete, Account::currentTenantID);
    if (ct == nullptr ) {
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
            ct->setStatus(0);  // Đổi thành 0 thay vì false để đảm bảo nhất quán
            total--;
            cout << "Da huy thue phong thanh cong!\n";
        }
    } else {
        cout << "Phong voi ID: " << roomIDtodelete << " khong duoc thue hoac khong phai cua ban." << endl;
    }
}

void Contract::extensionContract() {
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
        cout << "Hop dong nay da bi huy, khong the gia han." << endl;
    }

}

// Show all contracts
void Contract::showAllContracts() {
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
    int choice;
    string tempRE;
    do {
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
    Tenant* t = Tenant::tenantList.searchID(c.tenant_ID);
    Room* r = Room::roomList.searchID(c.room_ID);

    // Định nghĩa độ rộng cho từng cột
    const int width_id = 12;
    const int width_room_id = 8;
    const int width_room_type = 30;
    const int width_tenant_id = 12;
    const int width_name = 15;
    const int width_age = 7;
    const int width_cccd = 12;
    const int width_phone = 12;
    const int width_start_date = 15;
    const int width_end_date = 15;
    const int width_price = 10;
    const int width_status = 15;


    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_id) << "Contract ID" << " | "
           << setw(width_room_id) << "Room ID" << " | "
           << setw(width_room_type) << "Room Type" << " | "
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_name) << "Name" << " | "
           << setw(width_age) << "Age" << " | "
           << setw(width_cccd) << "CCCD" << " | "
           << setw(width_phone) << "Phone" << " | "
           << setw(width_start_date) << "Start Date" << " | "
           << setw(width_end_date) << "End Date" << " | "
           << setw(width_price + 12) << "Price" << " | "
           << setw(width_status) << "Status" << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_id + width_room_id + width_room_type + width_tenant_id + width_name + width_age + width_cccd + width_phone + width_start_date + width_end_date + width_price + width_status + 45) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In thông tin hợp đồng
    os << left
       << setw(width_id) << c.contractID << " | "
       << setw(width_room_id) << c.room_ID << " | "
       << setw(width_room_type) << r->getroomtype().getDescription() << " | "
       << setw(width_tenant_id) << c.tenant_ID << " | "
       << setw(width_name) << t->getName() << " | "
       << setw(width_age) << t->getAge() << " | "
       << setw(width_cccd) << t->getCCCD() << " | "
       << setw(width_phone) << t->getPhone() << " | "
       << setw(width_start_date) << c.startDate.toString() << " | "
       << setw(width_end_date) << c.endDate.toString() << " | "
       << setw(width_price) << fixed << setprecision(2) << c.rentprice << " VND/1 month" << " | "
       << setw(width_status) << (c.status == 1 ? "Active" : "Expired") << endl;
    return os;
}



