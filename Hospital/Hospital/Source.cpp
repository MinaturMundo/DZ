#include <iostream>
#include <conio.h>
#include <fstream>
//#include <list>
#include <windows.h>
#include "Local.h"
#include <vector>
//#include <locale.h>
using namespace std;
using namespace a;



int main()
{
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=120 lines=50");
    char ch_key;
    char ch;
    bool bMENU = true;
    string filenameProduct = "dataProduct.txt";
    string filenameService = "dataService.txt";
    string filenameDoctor = "dataDoctor.txt";
    vector<Product> product = ReadFromFileProduct(filenameProduct);
    vector<Service> service = ReadFromFileService(filenameService);
    vector<Doctor> doctor = ReadFromFileDoctors(filenameDoctor);


    while (bMENU)
    {
        system("cls");
        menu();
        std::cout << "\t\t\t\t\t\t\t";
        switch (ch_key = _getch())
        {
        case '1':
            system("cls");
            ViewProducts(product);
            system("pause");
            break;
        case '2':
            system("cls");
            AddProducts(product);
            system("pause");
            break;
        case '3':
            system("cls");
            DeleteProducts(product);
            system("pause");
            break;
        case '4':
            system("cls");
            ListOfDoctor(doctor);

            system("pause");
            break;
        case '5':
            system("cls");
            ListOfService(service);
            system("pause");
            break;
        case '6':
            system("cls");
            MakeAnAppointment(service);
            system("pause");
            break;
        case '7':
            system("cls");
            ViewRecord(service);
            system("pause");
            break;
        case '8':
            system("cls");
            cout << "Какой файл вы хотите сохранить>? (1 - Товаров, 2 - Услуг)";
            cin >> ch;
            switch (ch) {
            case '1':
                system("cls");
                SaveToFileProduct(product,filenameProduct);
                break;
            case '2':
                system("cls");
                SaveToFileService(service, filenameService);
                break;
            default:
                cout << "Неверное значение.";
                break;

            }
            
            system("pause");
            break;
        case 27:
            bMENU = false;
            cout << "Exit from program\n";
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
