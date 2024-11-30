#include "Reservation.h"
#include <admin.h>

int Reservation::total = 0;
int Reservation::currentNumber = 0;
LinkedList<Reservation> Reservation::reservationList;

Reservation::Reservation() {}
Reservation::Reservation(const string& roomId, const string& tenantId, DATE& start, int time, int stat)
    : room_ID(roomId), tenant_ID(tenantId), startDate(start), staytime(time), status(stat) {
    currentNumber++;
    reservation_ID = generateID(currentNumber);
    endDate = startDate + staytime; // Tính ngày kết thúc dựa trên `staytime`
}
Reservation::~Reservation() {}

string Reservation::generateID(int number) {
    stringstream ss;
    ss << "RS." << setw(3) << setfill('0') << number;
    return ss.str();
}

void Reservation::load(const string& filename) { reservationList.load(filename); }
void Reservation::updateFile(const string& filename) { reservationList.updateFile(filename); }

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

void Reservation::setStartDay(const string& day) {
    stringstream ss(day);
    int d, m, y;
    char delimiter;
    ss >> d >> delimiter >> m >> delimiter >> y;
    startDate = DATE(d, m, y);
    endDate = startDate + staytime;
}
void Reservation::setRoomID(const string& id) { room_ID = id; }
void Reservation::setTenantID(const string& id) { tenant_ID = id; }
void Reservation::setStatus(int stat) { status = stat; }
void Reservation::setStaytime(int stime) { staytime = stime; }

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

string Reservation::toString() const {
    stringstream ss;
    ss << reservation_ID << "," << room_ID << "," << tenant_ID << ","
       << startDate.toString() << "," << staytime << "," << status;
    return ss.str();
}

void Reservation::showAllReservations(Admin* adminWindow) {
    reservationList.show(adminWindow);
}

void Reservation::display(Admin* adminWindow) const {
    adminWindow->displayReservations(*this);  // Gọi hàm displayRoom của Admin với Room hiện tại
}

void Reservation::searchByID(const string& id, Admin* adminWindow) {
    bool found = false;
    LinkedList<Reservation>::Node* current = reservationList.begin();
    while (current != nullptr) {
        string ID = current->data.getID();
        if ( ID.find(id) != string::npos) {
            current->data.display(adminWindow);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        return;
    }
}

void Reservation::searchByStatus(int status, Admin* adminWindow) {
    reservationList.searchStatus(status, adminWindow);
}

void Reservation::sortID(bool sx){
    reservationList.sortByID(sx);
}

