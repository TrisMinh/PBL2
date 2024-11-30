#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
template <typename T>
LinkedList<T>::Node::Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}
template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}
template <typename T>
int LinkedList<T>::size() const {
    return count;
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::begin() { return head; }
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::end() { return nullptr; }
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getHead() {
    return head;
}

template <typename T>
void LinkedList<T>::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    string line;
    getline(file, line);// Skip dong 1
    if (getline(file, line) && !line.empty()) {
        T::currentNumber = std::stoi(line);
    } else {
        cerr << "Dong dau tien cua file txt khong hop le hoac tep rong" << endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        T obj;
        obj.fromString(line);
        add(obj);
    }
    file.close();
}
template <typename T>
void LinkedList<T>::updateFile(const string& filename) const {
    ifstream fileIn(filename);
    string firstline;
    if (fileIn.is_open()) {
        // Đọc dòng đầu tiên
        getline(fileIn, firstline);
        fileIn.close();
    } else {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    ofstream file(filename);
    file << firstline << endl;
    file << T::currentNumber << endl;
    Node* current = head;
    while (current != nullptr) {
        file << current->data.toString() << endl;
        current = current->next;
    }
    file.close();
}

template <typename T>
void LinkedList<T>::add(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::deleteNode(const string& value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getID() == value) {
            if (head == nullptr) {
                cout << "List is empty!!" << endl;
                return NULL;
            }
            if (head == current)
                head = current->next;
            if (current->next != nullptr)
                current->next->prev = current->prev;
            if (current->prev != nullptr)
                current->prev->next = current->next;
            if (tail == current)
                tail = current->prev;
            Node* temp = current;
            delete current;
            count--;
            cout << "Delete succesfully!" << endl;
            return temp;
        }
        current = current->next;
    }
    return nullptr;
}
// template <typename T>
// void LinkedList<T>::edit(const string& ID) {
//     Node* current = head;
//     while (current) {
//         if (current->data.getId() == ID) {
//             current->data.updateRoom();
//             return;
//         }
//         current = current->next;
//     }
//     cout << "Room not found with this ID." << endl;
// }


template <typename T>
void LinkedList<T>::sortByID(bool ascending) {
    if (head == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            string id1 = current->data.getID();
            string id2 = current->next->data.getID();
            if (ascending ? (id1 > id2) : (id1 < id2)) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
template <typename T>
void LinkedList<T>::sortByAlphabet(bool ascending) {
    if (head == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            string name1 = current->data.getFirstName();
            string name2 = current->next->data.getFirstName();
            bool shouldSwap = ascending ? (name1 > name2) : (name1 < name2);
            if (shouldSwap) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
// //Search
template <typename T>
T* LinkedList<T>::searchID(const string& ID) const{
    Node* current = head;
    while (current) {
        if (current->data.getID() == ID) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}
template <typename T>
void LinkedList<T>::searchStatus(const int& status, Admin* adminWindow) {
    Node* current = head;
    while (current) {
        if (current->data.getStatus() == status) {
            current->data.display(adminWindow);
        }
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::searchStatus(const int& status, Createpayment* adminWindow) {
    Node* current = head;
    while (current) {
        if (current->data.getStatus() == status) {
            current->data.displayuser(adminWindow);
        }
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::searchRoomType(const string& RT, Admin* adminWindow) {
    Node* current = head;
    while (current) {
        if (current->data.getRoomTypeID() == RT) {
            current->data.display(adminWindow);
        }
        current = current->next;
    }
}
// template <typename T>
// void LinkedList<T>::searchAll(LinkedList<T>& list) {
//     int choice;
//     do {
//         cout << "   1. Search by ID" << endl
//              << "   2. Search by Name" << endl
//              << "   0. Exit" << endl;
//         cout << "Please enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//         case 1:
//             T::searchByID();
//             break;
//         case 2:
//             // T::searchByName(list);
//             break;
//         case 0:
//             cout << "Exiting search menu." << endl;
//             break;
//         default:
//             cout << "Invalid choice. Please try again." << endl;
//             break;
//         }
//     } while (choice != 0);
// }
template <typename T>
const T& LinkedList<T>::operator[](int index) const {
    Node* current = head; // Assuming LinkedList has a head pointer
    int currentIndex = 0;
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }
    return T();
}
// template <typename T>
// T& LinkedList<T>::operator[](int index) {
//     Node* current = head; // Assuming LinkedList has a head pointer
//     int currentIndex = 0;
//     while (current != nullptr) {
//         if (currentIndex == index) {
//             return current->data;
//         }
//         current = current->next;
//         currentIndex++;
//     }
//     return T();
// }
template <typename T>
void LinkedList<T>::show(Admin* adminWindow) const {
    Node* current = head;
    if (current == NULL) { qDebug() << "List is empty! ";}
    while (current) {
        current->data.display(adminWindow);
        current = current->next;
    }
}



