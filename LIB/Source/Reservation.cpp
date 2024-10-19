#include "Reservation.h"
Reservation::Reservation() {}
Reservation::Reservation(const string& id, const string& roomId, const string& tenantId, const string& day, int price, int deposit, int stat)
    : reservation_ID(id), room_ID(roomId), tenant_ID(tenantId), start_day(day), 
      rent_price(price), deposit_amount(deposit), status(stat) {}
Reservation::~Reservation() {}
string Reservation::getID() {
    return reservation_ID;
}
void Reservation::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, reservation_ID, ',');
    getline(ss, room_ID, ',');
    getline(ss, tenant_ID, ',');
    getline(ss, start_day, ',');
    ss >> rent_price;
    ss.ignore(1);
    ss >> deposit_amount;
    ss.ignore(1);
    ss >> status;
}
ostream& operator<<(ostream& os, const Reservation& r) {
    os << "Reservation [ID: " << r.reservation_ID << ", Room ID: " << r.room_ID
       << ", Tenant ID: " << r.tenant_ID << ", Start Day: " << r.start_day
       << ", Rent Price: " << r.rent_price << ", Deposit Amount: " << r.deposit_amount
       << ", Status: " << (r.status == 1 ? "Completed" : "New") << "]\n";
    return os;
}
void Reservation::addReservation(LinkedList<Room>& roomList, LinkedList<Reservation>& reservationList) {
    string reservation_ID, room_ID, start_day;
    int rent_price, deposit_amount, status = 0;
    string tenantID;
    cout << "Enter your tenantID" << endl; cin >> tenantID;
    cout << "Nhap thong tin dat phong:" << endl;
    cout << "Reservation ID: ";
    cin >> reservation_ID;
    cout << "Room ID: ";
    cin >> room_ID;
    cout << "Start Day: ";
    cin >> start_day;
    cout << "Rent Price: ";
    cin >> rent_price;
    cout << "Deposit Amount: ";
    cin >> deposit_amount;
    Room* room = roomList.search(room_ID);
    if (room && room->getStatus() == 0) {
        Reservation newReservation(reservation_ID, room_ID, tenantID, start_day, rent_price, deposit_amount, status);
        reservationList.add(newReservation);
        room->setStatus(1);
        cout << "Reservation added successfully!" << endl;
    } else {
        cout << "Khong the dat phong, phong da co nguoi su dung hoac khong ton tai." << endl;
    }
}
void Reservation::searchReservationByID(LinkedList<Reservation>& reservationList) {
    string reservationID;
    cout << "Nhap Reservation ID de tim kiem: ";
    cin >> reservationID;
    Reservation* reservation = reservationList.search(reservationID);
    if (reservation) {
        cout << "Da tim thay: " << *reservation << endl;
    } else {
        cout << "Khong tim thay dat phong voi ID: " << reservationID << endl;
    }
}
void Reservation::updateReservation(LinkedList<Reservation>& reservationList) {
    string reservationID;
    cout << "Nhap Reservation ID de cap nhat: ";
    cin >> reservationID;
    Reservation* reservation = reservationList.search(reservationID);
    if (reservation) {
        string newRoomID, newStartDay;
        int newRentPrice, newDepositAmount, newStatus;
        cout << "Cap nhat Reservation ID: " << reservation->reservation_ID << endl;
        cout << "Room ID (nhap moi neu muon thay doi): ";
        cin >> newRoomID;
        cout << "Start Day: ";
        cin >> newStartDay;
        cout << "Rent Price: ";
        cin >> newRentPrice;
        cout << "Deposit Amount: ";
        cin >> newDepositAmount;
        cout << "Status (0: Moi, 1: Hoan thanh): ";
        cin >> newStatus;
        reservation->room_ID = newRoomID;
        reservation->start_day = newStartDay;
        reservation->rent_price = newRentPrice;
        reservation->deposit_amount = newDepositAmount;
        reservation->status = newStatus;
        cout << "Reservation updated successfully!" << endl;
    } else {
        cout << "Khong tim thay dat phong voi ID: " << reservationID << endl;
    }
}
void Reservation::deleteReservation(LinkedList<Reservation>& reservationList) {
    string reservationID;
    cout << "Nhap Reservation ID de xoa: ";
    cin >> reservationID;
    reservationList.deleteNode(reservationID);
    cout << "Reservation deleted successfully!" << endl;
}
void Reservation::showAllReservations(LinkedList<Reservation>& reservationList) {
    cout << "Danh sach tat ca cac dat phong:" << endl;
    reservationList.show();
}
string Reservation::getRoomID() const {
    return room_ID;
}
void Reservation::setStatus(int s) {
    status = s;
}
