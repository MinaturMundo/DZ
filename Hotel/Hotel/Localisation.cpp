#include "Localisation.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace assa;


void errorInfoRus() {
    system("cls");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================  ������  ===================================|" << std::endl;
    std::cout << "\t\t|=================== ������� ��������� � ������� ���������� ====================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}

std::vector<Room>* requestCleaningRus(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|============================== ��������� ������ ===============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t������� ���-�� ������ ��� ������� ������\n";
    std::cin >> num;
    std::cout << "\t\t������� �������\n";
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].needsCleaning = true;

    }
    return &rooms;

}
std::vector<Room>* foodDeliveryRus(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================ �������� ��� =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|================= ������� ���-�� ������ ��� ������ �������� ===================|\n";
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cin >> num;
    std::cout << "\t\t������� �������\n";
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].foodDeliveryRequested = true;

    }
    return &rooms;

}


std::vector<Room>* deleteGuestRus(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|============================= ��������� ������� ===============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|=================== ������� ����������� ������ ��� ������ =====================|\n";
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cin >> num;
    std::cout << "\t\t������� �������\n";
    if (num == 0) return &rooms;
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].foodDeliveryRequested = false;
        rooms[room - 1].isBooked = false;
        rooms[room - 1].needsCleaning = false;
        rooms[room - 1].guestInfo = "";
        rooms[room - 1].isVIP = false;
    }
    return &rooms;

}


std::vector<Room>* changeRoomRus(std::vector<Room>& rooms) {
    int num;
    int room;
    std::string name;
    int vip;
    bool res;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=============================== �������� ����� ================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "������� ���-�� ������ ��� ���������: ����� �������, ��� ������������, ������� ���?(0 - ���, 1 - ��)\n";
    std::cin >> num;
    if (num <= 0) { errorInfoRus(); return &rooms; }
    for (int i = 1; i <= num; ++i) {
        std::cin >> room >> name >> vip;
        if (rooms.size() < room) {
            errorInfoRus();
            return &rooms;
        }
        if (vip == 1) res = true;
        else if (vip == 0) res = false;
        else { errorInfoRus(); return &rooms; }
        rooms[room - 1].guestInfo = name;
        rooms[room - 1].isVIP = res;
        rooms[room - 1].isBooked = true;


    }
    return &rooms;

}

void saveToFileRus(const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "�������� � �����������: " << filename << std::endl;
        return;
    }

    for (const auto& room : rooms) {
        outFile << room.number << " " << room.guestInfo << " " << room.isVIP << " "
            << room.needsCleaning << " " << room.foodDeliveryRequested << " " << room.isBooked << std::endl;
    }

    outFile.close();
    std::cout << "���������� ��������� � " << filename << std::endl;
}





std::vector<Room>* addNewRoomsRus(std::vector<Room>& rooms) {
    int numRoomsToAdd;
    std::cout << "������� ������ ��������� �������: ";
    std::cin >> numRoomsToAdd;

    for (int i = 0; i < numRoomsToAdd; ++i) {
        Room newRoom;
        newRoom.number = rooms.size() + 1;
        rooms.push_back({ newRoom.number, " ", false, false,false,false });
    }

    return &rooms;
}

void showRoomsRus(std::vector<Room> rooms) {

    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================== ��� ������ ==================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& x : rooms) {
        std::cout << "\t\t\t\t" << x.number << " " << x.guestInfo << " " << (x.isVIP ? " VIP " : " ������� ") << " " << (x.isBooked ? " ����� " : " �������� ") << (x.needsCleaning ? " ������ " : " ") << (x.foodDeliveryRequested ? " �������� " : "  ") << std::endl;
    }
}



void menuRus() {
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================== HOTEL ====================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 1 ��� ��������� ������                        |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 2 ����� �������� �����                        |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                       ������� 3 ��� ������ ������ �������                     |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                        ������� 4 ��� ������ ��� � �����                       |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 5 ��� �������� ������                         |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                        ������� 6 ��� ���������� �����                         |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                        ������� 7 ��� ���������� ������                        |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            ������� 0 ��� ������                               |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}

std::vector<Room> createRoom() {
    std::vector<Room> rooms;
    for (int i = 1; i <= 10; ++i) {
        rooms.push_back({ i,"Null",0,0,0,0 });
    }
    return rooms;
}

void errorInfo() {
    system("cls");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=================================== ERROR =====================================|" << std::endl;
    std::cout << "\t\t|============================= room now is common ==============================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}

std::vector<Room>* requestCleaning(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|============================== REQUEST CLEANING ===============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\tEnter num of rooms u want to order cleaning\n";
    std::cin >> num;
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].needsCleaning = true;

    }
    return &rooms;

}
std::vector<Room>* foodDelivery(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=============================== FOOD  DELIVERY ================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|================ Enter num of rooms u  want to order delivery =================|\n";
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cin >> num;
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].foodDeliveryRequested = true;

    }
    return &rooms;

}


std::vector<Room>* deleteGuest(std::vector<Room>& rooms) {
    int num;
    int room;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=============================== Delete a guest ================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|====================== Enter num of rooms to clear room =======================|\n";
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cin >> num;
    if (num == 0) return &rooms;
    for (int i = 1; i <= num; ++i) {
        std::cin >> room;
        rooms[room - 1].foodDeliveryRequested = false;
        rooms[room - 1].isBooked = false;
        rooms[room - 1].needsCleaning = false;
        rooms[room - 1].guestInfo = "";
        rooms[room - 1].isVIP = false;
    }
    return &rooms;

}


std::vector<Room>* changeRoom(std::vector<Room>& rooms) {
    int num;
    int room;
    std::string name;
    int vip;
    bool res;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================ CHANGE  ROOM =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "Enter num of rooms u want to change: room num, guest name, is room vip\n";
    std::cin >> num;
    if (num <= 0) { errorInfo(); return &rooms; }
    for (int i = 1; i <= num; ++i) {
        std::cin >> room >> name >> vip;
        if (rooms.size() < room) {
            errorInfo();
            return &rooms;
        }
        if (vip == 1) res = true;
        else if (vip == 0) res = false;
        else { errorInfo(); return &rooms; }
        rooms[room - 1].guestInfo = name;
        rooms[room - 1].isVIP = res;
        rooms[room - 1].isBooked = true;


    }
    return &rooms;

}

void saveToFile(const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& room : rooms) {
        outFile << room.number << " " << room.guestInfo << " " << room.isVIP << " "
            << room.needsCleaning << " " << room.foodDeliveryRequested << " " << room.isBooked << std::endl;
    }

    outFile.close();
    std::cout << "Data has been saved to " << filename << std::endl;
}



std::vector<Room> readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Room> rooms;

    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        rooms = createRoom();
        return rooms;
    }

    Room room;
    while (file >> room.number >> room.guestInfo >> room.isVIP >> room.needsCleaning >> room.foodDeliveryRequested >> room.isBooked) {
        rooms.push_back(room);
    }

    file.close();
    return rooms;
}

std::vector<Room>* addNewRooms(std::vector<Room>& rooms) {
    int numRoomsToAdd;
    std::cout << "Enter the number of rooms to add: ";
    std::cin >> numRoomsToAdd;

    for (int i = 0; i < numRoomsToAdd; ++i) {
        Room newRoom;
        newRoom.number = rooms.size() + 1;
        rooms.push_back({ newRoom.number, " ", false, false,false,false });
    }

    return &rooms;
}

void showRooms(std::vector<Room> rooms) {

    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================== ALL ROOMS ==================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& x : rooms) {
        std::cout << "\t\t\t\t" << x.number << " " << x.guestInfo << " " << (x.isVIP ? " Vip room " : " Common ") << " " << (x.isBooked ? " booked " : " free ") << (x.needsCleaning ? " Ordered to clean " : " ") << (x.foodDeliveryRequested ? " delivery " : "  ") << std::endl;
    }
}



void menu() {
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================== HOTEL ====================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 1 to see all rooms                            |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 2 to add a guest                              |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 3 to request a cleaning                       |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 4 to order a delivery                         |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 5 to delete guest                             |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 6 to save file                                |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            type 7 to add  rooms                               |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                               type 0 to exit                                  |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}