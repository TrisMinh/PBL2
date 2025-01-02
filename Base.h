#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual void fromString(const string& line) = 0; 
    virtual string toString() const = 0; 
    virtual void getID() const;
};
#endif 