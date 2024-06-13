#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
#include <windows.h>
#include "Localisation.h"


using namespace assa;


int main() {
    setlocale(0, "RU");
    system("mode con cols=120 lines=50");
    short setLanguage;
    std::cout << "Введите 0 для выбора английского языка\nВведите 1 для выбора русского языка\nType 0 to set English language\n Type 1 to set Russian language\n";
    std::cin >> setLanguage;
    if (setLanguage == 0) {
        int choice;
        std::vector<Room> sada = readFromFile("data.txt");
        while (true) {
            system("cls");
            menu();
            std::cout << "\t\t\t\t\t\t\t";
            std::cin >> choice;
            if (choice == 0) break;
            switch (choice)
            {
            case 1: {
                system("cls");
                showRooms(sada);
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                changeRoom(sada);
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                requestCleaning(sada);
                system("pause");
                break;
            }
            case 4: {
                system("cls");
                foodDelivery(sada);
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                deleteGuest(sada);
                system("pause");
                break;
            }
            case 6: {
                system("cls");
                saveToFile(sada, "data.txt");
                system("pause");
                break;
            }
            case 7:
            {
                system("cls");
                addNewRooms(sada);
                system("pause");
                break;
            }
            default:
                break;
            }
        }
    }
    else if (setLanguage == 1) {
        int choice;
        std::vector<Room> sada = readFromFile("data.txt");
        while (true) {
            system("cls");
            menuRus();
            std::cout << "\t\t\t\t\t\t\t";
            std::cin >> choice;
            if (choice == 0) break;
            switch (choice)
            {
            case 1: {
                system("cls");
                showRoomsRus(sada);
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                changeRoomRus(sada);
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                requestCleaningRus(sada);
                system("pause");
                break;
            }
            case 4: {
                system("cls");
                foodDeliveryRus(sada);
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                deleteGuestRus(sada);
                system("pause");
                break;
            }
            case 6: {
                system("cls");
                saveToFileRus(sada, "data.txt");
                system("pause");
                break;
            }
            case 7:
            {
                system("cls");
                addNewRoomsRus(sada);
                system("pause");
                break;
            }
            default:
                break;
            }
        }
    }
    else { std::cout << "UNKNOWN DATA\nНЕВЕРНОЕ ЧИСЛО"; }
    return 0;
}