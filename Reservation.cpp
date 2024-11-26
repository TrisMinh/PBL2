#include "Reservation.h"

// Static Element
int Reservation::total = 0;
int Reservation::currentNumber = 0;
LinkedList<Reservation> Reservation::reservationList;
bool Reservation::is_header_printed = false;
void Reservation::resetHeader() { is_header_printed = false;}

// Constructor
Reservation::Reservation() {}
Reservation::Reservation(const string& roomId, const string& tenantId, DATE& start, int time, int stat)
    : room_ID(roomId), tenant_ID(tenantId), startDate(start), staytime(time), status(stat) {
    currentNumber++;
    reservation_ID = generateID(currentNumber);
    endDate = startDate + staytime; // Tính ngày kết thúc dựa trên `staytime`
}
Reservation::~Reservation() {}

// ID Generate
string Reservation::generateID(int number) {
    stringstream ss;
    ss << "RS." << setw(3) << setfill('0') << number;
    return ss.str();
}

// Load function
void Reservation::load(const string& filename) { reservationList.load(filename); }
void Reservation::updateFile(const string& filename) { reservationList.updateFile(filename); }

// Get function
int Reservation::getPrice() const {
    Room* room = Room::roomList.searchID(room_ID);
    return room->getPrice();
}
string Reservation::getID() const { return reservation_ID; }
string Reservation::getRoomID() const { return room_ID; }
string Reservation::getTenantID() const { return tenant_ID; }
DATE Reservation::getStartDate() const { return startDate; }
DATE Reservation::getEndDate() const {  return endDate; }
int Reservation::getStatus() const { return status; }

// Set function
void Reservation::setRoomID(const string& id) { room_ID = id; }
void Reservation::setTenantID(const string& id) { tenant_ID = id; }
void Reservation::setStartDay(const string& day) {
    stringstream ss(day);
    int d, m, y;
    char delimiter;
    ss >> d >> delimiter >> m >> delimiter >> y;
    startDate = DATE(d, m, y);
    endDate = startDate + staytime; 
}
void Reservation::setStatus(int stat) { status = stat; }
void Reservation::setStaytime(int stime) { staytime = stime; }


// Ham bien doi nham doc du lieu tu file (moi du lieu se co 1 fromstring khac nhau)
void Reservation::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, reservation_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, tenant_ID, ',');    
    string start_day;
    int staytime, status;
    getline(ss, start_day, ',');
    ss >> staytime;
    ss.ignore(1); // bỏ qua dấu phẩy
    ss >> status;
    this->startDate.fromString(start_day);
    this->staytime = staytime;
    this->status = status;
    this->endDate = this->startDate + staytime;
    total++;
}


// Ham chuyen thanh chuoi de ghi du lieu vao file
string Reservation::toString() const {
    stringstream ss;
    ss << reservation_ID << "," << room_ID << "," << tenant_ID << "," 
       << startDate.toString() << "," << staytime << "," << status;
    return ss.str();
}

// Chuc nang co ban (Basic Function)
void Reservation::addReservation() {
    string room_ID;
    Room* room = nullptr;
    // Hiển thị và kiểm tra room_ID trước
    cout << "Danh sach phong con trong: " << endl;
    Room::roomList.searchStatus(0);
    
    do {
        cout << "Nhap Room ID: "; 
        cin >> room_ID;
        room = Room::roomList.searchID(room_ID);
        
        if (!room || room->getStatus() != 0) {
            cout << "Phong khong ton tai hoac da co nguoi o. Vui long nhap lai Room ID hoac nhap '0' de thoat: " << endl;
        }
        
        if (room_ID == "0") return; // Thoát nếu người dùng nhập 0
        
    } while (!room || room->getStatus() != 0);
    
    // Chỉ nhập các thông tin còn lại khi đã có phòng hợp lệ
    DATE startDate;
    int staytime;
    cout << "Nhap Start Date: "; cin >> startDate;
    do {
        cout << "Nhap Stay Time (so ngay): "; cin >> staytime;
        if (staytime <= 0) {
            cout << "So ngay thue phong phai lon hon 0. Vui long nhap lai!" << endl;
        }
    } while (staytime <= 0);
    
    Reservation newReservation(room_ID, Account::currentTenantID, startDate, staytime, 0);
    reservationList.add(newReservation);
    room->setStatus(2);
    cout << "Dat phong thanh cong!" << endl;
    total++;
}


void Reservation::deleteReservation() {
    string reservationID;
    cout << "Nhap Reservation ID de xoa: "; cin >> reservationID;
    reservationList.deleteNode(reservationID);
    total--;
}

// Search Function
void Reservation::searchByID() {
    Reservation::resetHeader();
    string reservationID;
    cout << "Nhap Reservation ID de tim kiem: "; cin >> reservationID;
    Reservation* reservation = reservationList.searchID(reservationID);
    if (reservation) { cout << "Da tim thay: " << *reservation << endl; } 
    else { cout << "Khong tim thay dat phong voi ID: " << reservationID << endl; }
}

void Reservation::searchByStatus() {
    int status;
    cout << "Nhap Status de tim kiem (0: Waiting, 1: Accepted, 2: Rejected): "; cin >> status;
    reservationList.searchStatus(status);
}

void Reservation::searchAll() {
    resetHeader();
    int choice;
    do {
        cout << "Room Searching Function: " << endl 
             << "   1. Search by ID" << endl
             << "   2. Search by Status" << endl
             << "   0. Exit" << endl
             << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: searchByID(); break;
            case 2: searchByStatus(); break;
            case 0: return; 
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void Reservation::showAllReservations() {
    resetHeader();
    cout << "Danh sach tat ca cac dich vu:" << endl;
    reservationList.show();
    cout << "1. Sap xep tang ID\n2. Sap xep giam ID\n3. Tim kiem\n0. Thoat!\n";
    int choice;
    cout << "Vui long chon mot lua chon: ";
    cin >> choice;
    switch (choice) {
        case 1: reservationList.sortByID(true); showAllReservations(); break;
        case 2: reservationList.sortByID(false); showAllReservations(); break;
        case 3: searchAll(); break;
        case 0: return;
        default: cout << "Invalid choice. Please try again." << endl;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Reservation& r) {
    const int w1 = 15, w2 = 15, w3 = 15, w4 = 10, w5 = 10, w6 = 10;

    if (!Reservation::is_header_printed) {
        os << left 
           << setw(w1) << "Reservation ID" << " | "
           << setw(w2) << "Room ID" << " | "
           << setw(w3) << "Tenant ID" << " | "
           << setw(w4) << "Start Date" << " | "
           << setw(w5) << "End Date" << " | "
           << setw(w6) << "Status" << endl
           << setfill('-') << setw(w1 + w2 + w3 + w4 + w5 + w6 + 10) << "" 
           << setfill(' ') << endl;
        Reservation::is_header_printed = true;
    }

    os << left
       << setw(w1) << r.reservation_ID << " | "
       << setw(w2) << r.room_ID << " | "
       << setw(w3) << r.tenant_ID << " | "
       << setw(w4) << r.startDate.toString() << " | "
       << setw(w5) << r.endDate.toString() << " | "
       << setw(w6);
    
    switch (r.getStatus()) {
        case 0: os << "Waiting"; break;
        case 1: os << "Accepted"; break;
        case 2: os << "Rejected"; break;
        default: os << "Unknown";
    }
    os << "\n";
    return os;
}

void Reservation::checkNewReservations() {
    int count = 0;
    for (LinkedList<Reservation>::Node* current = reservationList.begin(); current != nullptr; current = current->next) {
        Reservation& reservation = current->data;
        if (reservation.getStatus() == 0) { count++; }
    }
    if (count == 0) { return; } 
    cout << "Thong bao: Co " << count << " lenh dat phong moi!" << endl;
}



