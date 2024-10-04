#ifndef ROOMTYPE_H
#define ROOMTYPE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
using namespace std;

class RoomType {
    string type_ID;
    string name;
    int price;
    string description;
public:
    RoomType() {}
    RoomType(const string& id, const string& n, int p, const string& desc)
        : type_ID(id), name(n), price(p), description(desc) {}
    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, type_ID, ',');
        getline(ss, name, ',');
        ss >> price;
        ss.ignore(1);
        getline(ss, description, ',');
    }
    friend ostream& operator<<(ostream& os, const RoomType& rt) {
        os << "RoomType [ID: " << rt.type_ID << ", Name: " << rt.name
           << ", Price: " << rt.price << ", Description: " << rt.description << "]\n";
        return os;
    }
};

#endif
