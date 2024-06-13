#pragma once
#include<vector>
#include<iostream>
#include<string.h>

namespace assa {
    struct Room {
        int number{};
        std::string guestInfo{};
        bool isVIP{};
        bool needsCleaning{};
        bool foodDeliveryRequested{};
        bool isBooked{};
    };
}
using namespace assa;
//eng
void menu();
void showRooms(std::vector<Room> rooms);
void saveToFile(const std::vector<Room>& rooms, const std::string& filename);
std::vector<Room> createRoom();
std::vector<Room>* addNewRooms(std::vector<Room>& rooms);
std::vector<Room> readFromFile(const std::string& filename);
std::vector<Room>* changeRoom(std::vector<Room>& rooms);
std::vector<Room>* requestCleaning(std::vector<Room>& rooms);
std::vector<Room>* foodDelivery(std::vector<Room>& rooms);
std::vector<Room>* deleteGuest(std::vector<Room>& rooms);
//ru
void errorInfoRus();
std::vector<Room>* requestCleaningRus(std::vector<Room>& rooms);
std::vector<Room>* foodDeliveryRus(std::vector<Room>& rooms);
std::vector<Room>* deleteGuestRus(std::vector<Room>& rooms);
std::vector<Room>* changeRoomRus(std::vector<Room>& rooms);
void saveToFileRus(const std::vector<Room>& rooms, const std::string& filename);
std::vector<Room>* addNewRoomsRus(std::vector<Room>& rooms);
void showRoomsRus(std::vector<Room> rooms);
void menuRus();
