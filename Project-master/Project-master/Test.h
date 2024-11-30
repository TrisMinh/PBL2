#ifndef TEST_H
#define TEST_H
#include "LinkedList.h"
#include <QFile>

class Test
{
public:
    static LinkedList<Test> roomList;
    static void read();
    Test();
};

#endif // TEST_H
