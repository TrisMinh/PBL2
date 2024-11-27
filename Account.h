#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Tenant.h"

class Account {
private:
    string account_ID,username,password,tenant_ID;
    int role; // 0: Khach, 1: Admin
public:
    static int total,currentNumber,currentrole;
    static string currentTenantID,AdminCode;
    static LinkedList<Account> accountList;
    static bool is_header_printed;

    // Constructor, Destructor
    Account();
    Account(const string& username, const string& password, const string& id, int role = 0);
    ~Account();

    // Ham Get
    string getID() const { return account_ID; }
    string getusername();
    string getpassword();
    string gettenantID();
    int getrole();

    // Ham Set
    void setusername(string u);
    void setpassword(string p);
    static void setAdminCode();

    void fromString(const string& line);
    string toString() const;
    static string generateID(int number);

    static void load(const string& filename);
    static void updateFile(const string& filename);
    static bool signin();
    static bool signup();

    // Basic Function
    void addAccount();
    void deleteAccount();
    void editAccount();
    static void showAllAccount();

    // Search function
    static LinkedList<Account>::Node* searchByUsername(string u, int check);
    static LinkedList<Account>::Node* verifyTenantInfo(const string& phone, const string& cccd);
    friend ostream& operator<<(ostream& os, const Account&);
    static void resetHeader();

    static bool forgotPassword();
    static void changePassword();

};
#include "Account.cpp"
#endif