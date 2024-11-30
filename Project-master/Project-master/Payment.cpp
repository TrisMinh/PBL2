#include "Payment.h"

int Payment::total = 0;
int Payment::currentNumber = 0;
LinkedList<Payment> Payment::paymentList;

Payment::Payment() : depositAmount(0) {}
Payment::Payment(const string& roomID, const string& tenantID, double rentAmount, double serviceAmount,
                 double totalAmount, int billMonth, int billYear, bool status) :  roomID(roomID), tenantID(tenantID), rentAmount(rentAmount), serviceAmount(serviceAmount),
    totalAmount(totalAmount) ,billMonth(billMonth), billYear(billYear), status(status), depositAmount(0) {
    paymentID = generateID(++currentNumber);
    totalAmount = rentAmount + serviceAmount;
}
Payment::~Payment() {}

string Payment::generateID(int number) {
    stringstream ss;
    ss << "P." << setw(3) << setfill('0') << number;
    return ss.str();
}

void Payment::load(const string& filename) { paymentList.load(filename); }
void Payment::updateFile(const string& filename) { paymentList.updateFile(filename); }

string Payment::getID() const { return paymentID; }
string Payment::getRoomID () const { return roomID; }
string Payment::getTenantID () const { return tenantID; }
DATE Payment::getpayDate() const {return payDate; }
bool Payment::getStatus() const {return status;}
double Payment::getdepositAmount() const {return depositAmount;}
double Payment::getRentAmount() const {return rentAmount; }
double Payment::getServiceAmount() const {return serviceAmount; }
double Payment::getTotalAmount() const {return totalAmount;}
int Payment::getBillMonth() const { return billMonth; }
int Payment::getBillYear() const { return billYear; }

void Payment::fromString(const string& line) {
    stringstream ss(line);
    getline(ss, paymentID, ',');
    getline(ss, roomID, ',');
    getline(ss, tenantID, ',');
    ss >> rentAmount; ss.ignore(1);
    ss >> serviceAmount; ss.ignore(1);
    ss >> totalAmount; ss.ignore(1);
    ss >> billMonth; ss.ignore(1);
    ss >> billYear; ss.ignore(1);
    string payDatestr;
    getline(ss, payDatestr, ',');
    payDate.fromString(payDatestr);
    ss >> status; ss.ignore(1);
    ss >> depositAmount;
    total++;
}

string Payment::toString() const {
    return paymentID + "," + roomID + "," + tenantID + "," + to_string(rentAmount) + "," + to_string(serviceAmount) + "," +
           to_string(totalAmount) + "," + to_string(billMonth) + "," +
           to_string(billYear) + "," + payDate.toString() + "," +
           to_string(status) + "," + to_string(depositAmount);
}


// double Payment::calculateTotalBilled(int month, int year) {
//     double total = 0;
//     for (LinkedList<Payment>::Node* current = paymentList.begin();
//          current != nullptr; current = current->next) {
//         Payment& payment = current->data;
//         if (payment.payMonth == month && payment.payYear == year) {
//             total += payment.totalAmount;
//         }
//     }
//     return total;
// }

// double Payment::calculateTotalCollected(int month, int year) {
//     double total = 0;
//     for (LinkedList<Payment>::Node* current = paymentList.begin();
//          current != nullptr; current = current->next) {
//         Payment& payment = current->data;
//         if (payment.payMonth == month && payment.payYear == year && payment.status) {
//             total += payment.totalAmount;
//         }
//     }
//     return total;
// }

void Payment::showAllPayments(Admin* adminWindow) {
    paymentList.show(adminWindow);
}

void Payment::display(Admin* adminWindow) const {
    adminWindow->displayPayments(*this);
}

void Payment::searchByMonth(int month, int year, Admin* adminWindow) {
    bool found = false;
    for (auto current = paymentList.begin(); current != nullptr; current = current->next) {
        if (current->data.billMonth == month && current->data.billYear == year) {
            current->data.display(adminWindow);
            found = true;
        }
    }
    if (!found) { return; }
}

bool Payment::isValidPaymentDate(const DATE& paymentDate, const Contract& contract) {
    return !(paymentDate > contract.getEndDate() ||
             (paymentDate.get_year() < contract.getStartDate().get_year()) ||
             (paymentDate.get_year() == contract.getStartDate().get_year() &&
              paymentDate.get_month() < contract.getStartDate().get_month()));
}

bool Payment::isPaymentExist(const string& roomID, const string& tenantID, int billMonth, int billYear) {
    for (LinkedList<Payment>::Node* current = paymentList.begin(); current != nullptr; current = current->next) {
        Payment& payment = current->data;
        if (payment.getRoomID() == roomID && payment.getTenantID() == tenantID &&
            payment.getBillMonth() == billMonth && payment.getBillYear() == billYear) {
            return true;
        }
    }
    return false;
}

double Payment::calculateProRatedRent(double fullRentAmount, int startDay, int billMonth, int billYear) {
    int daysInMonth = 31; // Mặc định là 31 ngày
    if (billMonth == 4 || billMonth == 6 || billMonth == 9 || billMonth == 11) {
        daysInMonth = 30;
    } else if (billMonth == 2) {
        daysInMonth = (billYear % 4 == 0 && (billYear % 100 != 0 || billYear % 400 == 0)) ? 29 : 28;
    }

    int remainingDays = daysInMonth - startDay + 1;
    return (fullRentAmount / daysInMonth) * remainingDays;
}

bool Payment::createPayment(int billMonth, int billYear, Createpayment* adminWindow) {
    bool hasCreated = false;
    DATE paymentDate(1, billMonth, billYear);

    for (LinkedList<Contract>::Node* current = Contract::contractList.begin();
         current != nullptr; current = current->next) {
        Contract& contract = current->data;

        if (!contract.getStatus() || !isValidPaymentDate(paymentDate, contract)) continue;

        string roomID = contract.getRoomID();
        string tenantID = contract.getTenantID();

        if (isPaymentExist(roomID, tenantID, billMonth, billYear)) continue;

        Room::searchByID(roomID, adminWindow);

        hasCreated = true;
    }
    if (!hasCreated) {
        return false;
    }
    return true;
}

void Payment::autocreatePayment(int billMonth, int billYear) {
    DATE paymentDate(1, billMonth, billYear);

    for (LinkedList<Contract>::Node* current = Contract::contractList.begin();
         current != nullptr; current = current->next) {
        Contract& contract = current->data;

        if (!contract.getStatus() || !isValidPaymentDate(paymentDate, contract)) continue;

        string roomID = contract.getRoomID();
        string tenantID = contract.getTenantID();

        if (isPaymentExist(roomID, tenantID, billMonth, billYear)) continue;

        double rentAmount = contract.getPrice();
        if (billMonth == contract.getStartDate().get_month() &&
            billYear == contract.getStartDate().get_year()) {
            rentAmount = calculateProRatedRent(rentAmount, contract.getStartDate().get_day(), billMonth, billYear);
        }

        double serviceAmount = ServiceUsage::calculateServiceAmountForRoom(roomID, tenantID);

        Payment p(roomID, tenantID, rentAmount, serviceAmount, rentAmount + serviceAmount, billMonth, billYear);
        paymentList.add(p);
    }
}
