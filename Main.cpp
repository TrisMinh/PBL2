#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Guest {
private:
    std::string name, cmnd, day_of_birth, phone_number;
    int key_user;    
    unsigned int age;
public:
    Guest(int key_user,std::string name,std::string cmnd,unsigned int age,std::string day_of_birth,std::string phone_number) 
    : key_user(key_user),name(name),cmnd(cmnd),age(age),day_of_birth(day_of_birth),phone_number(phone_number) {};
    
    //Ham get
    int get_key_user()     {return key_user;}
    std::string get_name()         {return name;}
    std::string get_cmnd()         {return cmnd;}
    std::string get_day_of_birth() {return day_of_birth;}
    int         get_age()          {return age;}
    std::string get_phone_number() {return phone_number;}
    //Ham set
    void set_name(std::string name)                 {this->name = name;};
    void set_cmnd(std::string cmnd)                 {this->cmnd = cmnd;};
    void set_age(unsigned int age)                           {this->age = age;};
    void set_day_of_birth(std::string day_of_birth) {this->day_of_birth = day_of_birth;};
    void set_phone_number(std::string phone_number) {this->phone_number = phone_number;};

    void show_information() {
        std::cout << "Thong tin nguoi dung co ma key_user " << key_user << " la: " 
                  << " Ten: " << name << "  |" 
                  << " Tuoi: " << age << "  |"
                  << " Cmnd: " << cmnd << "  |"
                  << " Ngaysinh: " << day_of_birth << "  |"
                  << " Sodienthoai: " << phone_number << "  |" << std::endl; 
    };
};

struct Node {
    Guest data;
    Node* next;
    Node* prev;
    Node(Guest data) : data(data), next(NULL), prev(NULL) {};
};

class Guest_Manager {
private:
    int Guest_count = 0;
    Node* head;
    Node* tail;
public:
    Guest_Manager() : head(NULL), tail(NULL) {};
    void increase_guest() {
        this->Guest_count++;
    }
    void decrease_guest() {
        this->Guest_count--;
    }
    void add() {
        std::string name, cmnd, day_of_birth, phone_number;
        unsigned int age;
        int key_user; 

        //Input from keyboard
        key_user = Guest_count; 
        std::cout << "Nhap ten cua ban: ";          std::cin >> name;
        std::cout << "Nhap tuoi cua ban: ";         std::cin >> age;   
        std::cout << "Nhap CMND cua ban: ";         std::cin >> cmnd;
        std::cout << "Nhap ngay sinh cua ban:";     std::cin >> day_of_birth;
        std::cout << "Nhap so dien thoai cua ban:"; std::cin >> phone_number;

        //Them node
        Guest new_Guest(key_user, name, cmnd, age, day_of_birth, phone_number);
        Node* new_Node = new Node(new_Guest);
        if(head == NULL) {
            head = tail = new_Node;
        }
        else {
            tail->next = new_Node;
            new_Node->prev = tail;
            tail = new_Node->next;
        }
        std::cout << "Added new Guest !!" << std::endl;    
        increase_guest();
    }

    void show_all_guests() {
        if(head ==NULL) {
            std::cout << "Khong co nguoi dung nao " << std::endl;
        }
        Node* current = head;
        while (current != nullptr) {
            current->data.show_information();
            current = current->next;
        }
    }

    void add_from_file(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            std::cerr << "Could not open file " << filename << std::endl;
            return;
        }

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string key_user_str, name, cmnd, age_str, day_of_birth, phone_number;

            std::getline(ss, key_user_str, ',');
            std::getline(ss, name, ',');
            std::getline(ss, cmnd, ',');
            std::getline(ss, age_str, ',');
            std::getline(ss, day_of_birth, ',');
            std::getline(ss, phone_number);

            int key_user = std::stoi(key_user_str);
            unsigned int age = std::stoul(age_str);

            Guest new_Guest(key_user, name, cmnd, age, day_of_birth, phone_number);
            Node* new_Node = new Node(new_Guest);

            if (head == nullptr) {
                head = tail = new_Node;
            } else {
                tail->next = new_Node;
                new_Node->prev = tail;
                tail = new_Node;
            }

            Guest_count++;
        }

        file.close();
        std::cout << "Added guests from file successfully!" << std::endl;
    }
};

int main() {
    Guest_Manager manager;
    
    // Thêm một vài khách hàng mới

    manager.add_from_file("Data_user.txt");
    // manager.add();
    // manager.add();

    // Hiển thị thông tin của tất cả khách hàng
    manager.show_all_guests();
}