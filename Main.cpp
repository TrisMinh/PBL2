#include <iostream>
#include <string>

#include "LIB/ROOM.h"
#include "ROOM_LIST.h"

int main() {
    // Tạo một đối tượng RoomList
    RoomList roomList;
    roomList.inputfromfile(roomList, "Data/Room.txt");


    // Thêm các phòng vào danh sách
    // roomList.addRoom(Room("R001", "M001", 1, 0, "T001", "Conference Room"));
    // roomList.addRoom(Room("R002", "M002", 2, 1, "T002", "Meeting Room"));
    // roomList.addRoom(Room("R003", "M003", 1, 0, "T003", "Storage Room"));

    // roomList.inputRoom();
    
    // Hiển thị danh sách phòng
    roomList.displayAllRooms();

    return 0;
}
