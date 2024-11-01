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
        Node* prev;
        Node* next;
        Node(const T& data);
    };
    Node* head;
    Node* tail;
    LinkedList();
    ~LinkedList();
    int size() const;

    void load(const string& filename);
    void updateFile(const string& filename) const;
    void add(const T& data);
    Node* deleteNode(const string& value);
    void edit(const string& ID);
    Node* getHead();
    T* searchID(const string& ID) const;
    void searchStatus(const int& status);
    void searchAll(LinkedList<T>& list);
    void show() const;
    void sortByID(bool ascending = true);
    void sortByAlphabet(bool ascending = true);

    const T& operator[](int index) const;
    T& operator[](int index);
};

#include "LinkedList.cpp" // Bao gồm file cpp ở cuối header

#endif // LINKEDLIST_H
