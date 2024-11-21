#include "Reservation.h"

// Static Element
int Reservation::total = 0;
int Reservation::currentNumber = 0;
LinkedList<Reservation> Reservation::reservationList;

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
    cout << "Nhap Stay Time (so ngay): "; cin >> staytime;
    
    Reservation newReservation(room_ID, Account::currentTenantID, startDate, staytime, 0);
    reservationList.add(newReservation);
    room->setStatus(2);
    cout << "Dat phong thanh cong!" << endl;
    total++;
}

//Gia hạn ( chỉnh lại )
// void Reservation::updateReservation() {
//     string id;
//     cout << "Nhap ID dat phong can cap nhat: "; cin >> id;
//     Reservation* reservation = reservationList.searchID(id);
//     if (reservation) {
//         string newRoomID;
//         cout << "Nhap Room ID moi: "; cin >> newRoomID;
//         reservation->setRoomID(newRoomID);

//         int day, month, year;
//         cout << "Nhap ngay bat dau (dd mm yyyy): "; cin >> day >> month >> year;
//         reservation->startDate = DATE(day, month, year);

//         int newStaytime;
//         cout << "Nhap so ngay thue moi: ";cin >> newStaytime;
//         reservation->staytime = newStaytime;
//         reservation->endDate = reservation->startDate + newStaytime;
//         cout << "Cap nhat dat phong thanh cong!" << endl;
//     } else {
//         cout << "Khong tim thay dat phong voi ID: " << id << endl;
//     }
// }

void Reservation::deleteReservation() {
    string reservationID;
    cout << "Nhap Reservation ID de xoa: "; cin >> reservationID;
    reservationList.deleteNode(reservationID);
    total--;
}

// Search Function
void Reservation::searchByID() {
    string reservationID;
    cout << "Nhap Reservation ID de tim kiem: "; cin >> reservationID;
    Reservation* reservation = reservationList.searchID(reservationID);
    if (reservation) { cout << "Da tim thay: " << *reservation << endl; } 
    else { cout << "Khong tim thay dat phong voi ID: " << reservationID << endl; }
}

void Reservation::searchByName() {
    string name;
    cout << "Nhap ten chu phong can tim kiem: "; cin >> name;
    bool found = false;
    LinkedList<Tenant>::Node* current1 = Tenant::tenantList.begin();
    while (current1 != nullptr) {
        if (current1->data.getName() == name) {
            break;
        }
        current1 = current1->next;
    }
    LinkedList<Reservation>::Node* current2 = Reservation::reservationList.begin();
    while (current2 != nullptr) {
        if (current2->data.getTenantID() == current1->data.getID()) {
            cout << current2->data;
            found = true;
        }
        current2 = current2->next;
    }
    if (!found) {
        cout << "Khong tim thay lenh dat phong nao voi ten: " << name << endl;
    }
}

void Reservation::searchAll() {
    int choice;
    do {
        cout << "Room Searching Function: " << endl
             << "   1. Search by ID" << endl
             << "   2. Search by Name" << endl
             << "   0. Exit" << endl
             << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: Reservation::searchByID(); break;
        case 2: Reservation::searchByName(); break;
        case 0: cout << "Exiting search menu." << endl; break;
        default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 0);
}

// Show Function
void Reservation::showAllReservations() {
    cout << "Danh sach tat ca cac dich vu:" << endl;
    reservationList.show();
    cout << "1. Sap xep tang ID" << endl
         << "2. Sap xep giam ID" << endl
         << "0. Thoat!" << endl;
    int choice;
    cout << "Vui long chon mot lua chon: ";
    cin >> choice;
    switch (choice) {
        case 1: reservationList.sortByID(true); showAllReservations(); break;
        case 2: reservationList.sortByID(false); showAllReservations(); break;
        default: break;
    }
}

// Da nang hoa ham xuat
ostream& operator<<(ostream& os, const Reservation& r) {
    // Định nghĩa độ rộng cho từng cột
    const int width_reservation_id = 15;
    const int width_room_id = 15;
    const int width_tenant_id = 15;
    const int width_start_date = 10;
    const int width_end_date = 10;
    const int width_status = 10;

    static bool is_header_printed = false; // Biến tĩnh đảm bảo tiêu đề chỉ in một lần

    // In tiêu đề bảng một lần duy nhất
    if (!is_header_printed) {
        os << left
           << setw(width_reservation_id) << "Reservation ID" << " | "
           << setw(width_room_id) << "Room ID" << " | "
           << setw(width_tenant_id) << "Tenant ID" << " | "
           << setw(width_start_date) << "Start Date" << " | "
           << setw(width_end_date) << "End Date" << " | "
           << setw(width_status) << "Status"
           << endl;

        // In dòng kẻ ngang phân cách tiêu đề và dữ liệu
        os << setfill('-')
           << setw(width_reservation_id + 20) << ""
           << setw(width_room_id) << ""
           << setw(width_tenant_id) << ""
           << setw(width_start_date) << ""
           << setw(width_end_date) << ""
           << setw(width_status) << ""
           << setfill(' ') << endl;

        is_header_printed = true; // Đánh dấu đã in tiêu đề
    }

    // In dữ liệu Reservation
    os << left
       << setw(width_reservation_id) << r.reservation_ID << " | "
       << setw(width_room_id) << r.room_ID << " | "
       << setw(width_tenant_id) << r.tenant_ID << " | "
       << setw(width_start_date) << r.startDate.toString() << " | "
       << setw(width_end_date) << r.endDate.toString() << " | "
       << setw(width_status);
    
    // In trạng thái
    switch (r.getStatus()) {
        case 0:
            os << "Waiting";
            break;
        case 1:
            os << "Accepted";
            break;
        case 2:
            os << "Rejected";
            break;
        default:
            os << "Unknown";
            break;
    }

    os << "\n";
    return os;
}


