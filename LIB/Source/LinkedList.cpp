#include <iostream>
#include "Header/LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
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
void LinkedList<T>::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file " << filename << endl;
        return;
    }
    string line;
    getline(file, line); // Skip header line if it exists
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
void LinkedList<T>::deleteNode(const string& value) {
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
            if (tail == current)
                tail = current->prev;
            delete current;
            count--;
            return;
        }
        current = current->next;
    }
    cout << "Not found in the list " << value << ".\n";
}
template <typename T>
void LinkedList<T>::edit(const string& ID) {
    Node* current = head;
    while (current) {
        if (current->data.getId() == ID) {
            current->data.updateRoom();
            return;
        }
        current = current->next;
    }
    cout << "Room not found with this ID." << endl;
}
template <typename T>
T* LinkedList<T>::search(const string& ID) {
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
void LinkedList<T>::show() const {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
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
            string name1 = current->data.getname();
            string name2 = current->next->data.getname();
            // Compare names directly
            bool shouldSwap = ascending ? (name1 > name2) : (name1 < name2);
            if (shouldSwap) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

