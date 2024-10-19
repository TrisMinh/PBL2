#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data);
    };
    Node* head;
    Node* tail;
    int count; // Count of elements
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    void load(const string& filename);
    void add(const T& data);
    void deleteNode(const string& value);
    void edit(const string& ID);
    T* search(const string& ID);
    void show() const;
    void sortByID(bool ascending = true);
    //void sortByAlphabet(bool ascending = true);
    void sortByAlphabet(bool ascending = true) {
        // Check empty list
        if (head == NULL) return;

        bool swapped;

        do {
            swapped = false;
            Node* current = head;

            while (current->next) {
                // Lay Id va chu de so sanh
                string parts1 = current->data.getname();
                string parts2 = current->next->data.getname();
                // So sanh chu truoc, neu giong so sanh so
                bool shouldSwap = ascending ? (parts1.letters > parts2.letters  (parts1.letters == parts2.letters && parts1.number > parts2.number))
                                            : (parts1.letters < parts2.letters  (parts1.letters == parts2.letters && parts1.number < parts2.number));

                if (shouldSwap) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};

#endif
