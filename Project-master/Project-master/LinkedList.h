#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <QFile>
#include "admin.h"
#include "Createpayment.h"
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
    Node* begin();
    Node* tail;
    Node* end();
    LinkedList();
    ~LinkedList();
    int size() const;

    void load(const string& filename);
    void updateFile(const string& filename) const;
    void add(const T& data);
    Node* deleteNode(const string& value);
    // void edit(const string& ID);
    Node* getHead();
    T* searchID(const string& ID) const;
    void searchStatus(const int& status, Admin* adminWindow);
    void searchStatus(const int& status, Createpayment* adminWindow);
    void searchRoomType(const string& RT, Admin* adminWindow);
    // void searchAll(LinkedList<T>& list);
    void show(Admin* adminWindow) const;
    void sortByID(bool ascending = true);
    void sortByAlphabet(bool ascending = true);

    const T& operator[](int index) const;
};

#include "LinkedList.cpp"

#endif // LINKEDLIST_H
