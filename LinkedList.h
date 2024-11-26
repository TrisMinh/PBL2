#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename T>
class LinkedList {
private:
    int count; // Count of elements
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& data);
    };
    Node* head;
    Node* begin();
    Node* tail;
    Node* end();
    LinkedList();
    ~LinkedList();
    int size() const;

    void load(const string& filename);
    void updateFile(const string& filename) const;
    void add(const T& data);
    void deleteNode(const string& value);
    void edit(const string& ID);
    T* searchID(const string& ID) const;
    void searchStatus(const int& status);
    void show() const;
    void sortByID(bool ascending = true);
    void sortByAlphabet(bool ascending = true);

    const T& operator[](int index) const;
};

#include "LinkedList.cpp" // Bao gồm file cpp ở cuối header

#endif // LINKEDLIST_H
