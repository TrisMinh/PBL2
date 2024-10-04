#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Template để sử dụng cho nhiều kiểu dữ liệu
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count; // Biến đếm số phần tử
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    int size() const { // Hàm trả về số lượng phần tử
        return count;
    }
    // Hàm để load dữ liệu từ file
    void load(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Khong the mo file " << filename << endl;
            return;
        }
    
        string line;
        getline(file, line); // Bỏ qua dòng tiêu đề (nếu có)
        while (getline(file, line)) {
            if (line.empty()) {
                continue; // Bỏ qua dòng trống
            }
            
            T obj;
            obj.fromString(line);
            add(obj);
        }
        file.close();
    }
    void add(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void deleteNode(const string& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.getID() == value) {
                if (head == nullptr) {
                    cout << "List is empty!!" << endl;
                    return;
                }
                if (head == current)
                    head = current->next;
                if (current->next != nullptr)
                    current->next->prev = current->prev;
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                free (current);
                return;
            }
            current = current->next;
        }
        cout << "Khong Tim Thay trong danh sach " << value << ".\n";
    }

    T* search(const string& ID) {
        Node* current = head;
        while (current) {
            if (current->data.getID() == ID) {
                return &(current->data);
            }
            current = current->next;
        }
        return NULL;
    }

    void show() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif
