#include "Contract.h"

int Contract::currentNumber = 0;
int Contract::total = 0;
LinkedList<Contract> Contract::contractList;

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


string Contract::generateID(int number) {
    stringstream ss;
    ss << "CT." << setw(3) << setfill('0') << number;
    return ss.str();
}

string Contract::getID() const { return contractID; }
DATE Contract::getStartDate() const { return startDate; }
DATE Contract::getEndDate() const { return endDate; }
double Contract::getPrice() const { return Reservation::getPrice(); }
bool Contract::getStatus() const { return status; }
double Contract::getrentprice() const {return rentprice; }

// Set function
void Contract::setStartDate(const DATE& startDate) { this->startDate = startDate; }
void Contract::setEndDate(const DATE& endDate) { this->endDate = endDate; }
void Contract::setPrice(double rprice) { this->rentprice = rprice; }
void Contract::setStatus(bool status) { this->status = status; }

// Load function
void Contract::load(const string& filename) { contractList.load(filename); }
void Contract::updateFile(const string& filename) { contractList.updateFile(filename); }

void Contract::addContract(const string& roomID, const string& tenantID,
                           const DATE& start, const DATE& end, int status) {
    Contract newContract(roomID, tenantID, start, end, status);
    contractList.add(newContract);
    // cout << "Contract added: " << newContract.getID() << endl;
    total++;
}

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

void Contract::confirmReservationandcreatContract(int choice, const string& tempRE) {
    switch (choice) {
        case 1: {
            Reservation* re = reservationList.searchID(tempRE);
            Room* ro = Room::roomList.searchID(re->getRoomID());
            if (re && ro) {
                re->setStatus(1);
                ro->setStatus(1);
                ro->setTenantID(re->getTenantID());
                addContract(re->getRoomID(),re->getTenantID(),re->getStartDate(),re->getEndDate(),1);
            }
            break;
        }
        case 2: {
            Reservation* re = reservationList.searchID(tempRE);
            Room* ro = Room::roomList.searchID(re->getRoomID());
            if (re) {
                re->setStatus(2);
                ro->setStatus(0);
            }
            break;
        }
    }
}

void Contract::showAllContracts(Admin* adminWindow) {
    contractList.show(adminWindow);
}

void Contract::display(Admin* adminWindow) const {
    adminWindow->displayContracts(*this);
}

void Contract::sortID(bool sx){
    contractList.sortByID(sx);
}
