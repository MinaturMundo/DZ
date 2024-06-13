#include "Local.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "windows.h"
#include <conio.h>
using namespace a;
void menu() {
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================== Hospital =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 1 ��� ��������� �������                       |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 2  ��� ���������� �������                     |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 3 ��� �������� �������                        |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 4 ������ ������                               |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 5  C����� �����                               |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 6  ������ �� �����                            |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 7  ��� ��������� ����� �������                |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                         ������� 8 ��� ���������� �����                        |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|                            ������� Esc ��� ������                             |" << std::endl;
    std::cout << "\t\t|                                                                               |" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}

std::vector<Product> CreateProduct() {
    std::vector<Product> pr;
    for (int i = 0; i <= 1; ++i)
    {
        pr.push_back({ i,""});
    }

    return pr;
}
std::vector<Service> CreateService() {
    std::vector<Service> sv;
    for (int i = 0; i <= 10; ++i)
    {
        sv.push_back({i,"",0,false });
    }

    return sv;
}
std::vector<Doctor> CreateDoctor() {
    std::vector<Doctor> dc;
    for (int i = 0; i <= 10; ++i)
    {
        dc.push_back({i,""});
    }

    return dc;
}

void Error() {
    system("cls");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================== ������ ===================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
}


void ViewProducts(std::vector<Product> pr) {
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|==================================== ������ ===================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;

    for (const auto& a : pr) {
        std::cout << "\t\t\t\t" <<a.number<<" " << a.name << std::endl;
    }

}

std::vector<Product>* AddProducts(std::vector<Product>& pr)
{
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=================================�������� ������ ==============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;


    int count = 1;
    int quantity;
    std::cout << "������� ������� �� ������ ��������?";
    std::cin >> quantity;
    if (quantity > 100) { Error(); }
    for (int i = 0; i < quantity; ++i)
    {
        Product newNumber;
        newNumber.number = pr.size() + 1;
        pr.push_back({newNumber.number});
        count++;
    }
    std::string product;

    for (int i = 0; i < count - 1; i++)
    {
        Product NewProduct;
        std::cout << "������� ������� ����� ������� ���������� ������ ������� Enter" << std::endl;
        std::cin >> product;
        pr[i].name = product;
    }

    return &pr;

}

std::vector<Product>* DeleteProducts(std::vector<Product>& pr)
{
    int prod;
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=================================������� ������ ===============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& a : pr) {
        std::cout << "\t\t\t\t" << a.number << " " << a.name << std::endl;
    }
    std::cout << "������� ����� ������, ������� ������ �������" << std::endl;
    for (int i = 1; i <= pr.size(); ++i) {
        std::cin >> prod;
        pr[prod - 1].name = "";
        return &pr;
    }
}

void ListOfDoctor(std::vector<Doctor>& dc)
{
    setlocale(LC_ALL, "Russian");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================= ������ ������ ===============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& x : dc) {
        std::cout << x.number << " " << x.special<< std::endl;
    }

}

void ListOfService(std::vector<Service>& sv) {
    setlocale(LC_ALL, "Russian");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================= ������ ����� ================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& x : sv) {
        std::cout << x.number << " " << x.name << " " << x.price << std::endl;
    }
}

std::vector<Service>* MakeAnAppointment(std::vector<Service>& sv)
{
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================ ������ �� ����� ==============================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    int ch;
    for (const auto& x : sv) {
        std::cout << x.number << " " << x.name << " " << x.price << std::endl;
    }
    std::cout << std::endl;
    std::cout << "������� ����� ������ �� ������� ������ ����������" << std::endl;
    std::cin >> ch;

    if (ch >= 1 && ch <= sv.size()) {
        sv[ch - 1].IsRecorded = true;
        std::cout << "�� ��������." << std::endl;
    }
    else {
        std::cout << "����� ������ �����������" << std::endl;
    }

    return &sv;
}

void ViewRecord(std::vector<Service> sv)
{
    setlocale(LC_ALL, "Russian");
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|================================= ���� ������ =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    for (const auto& x : sv) {
        if (x.IsRecorded == true) {
            std::cout << x.number << " " << x.name << " " << x.price << std::endl;
        }
    }
}

void SaveToFileProduct(const std::vector<Product> pr, const std::string& filename)
{
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=============================== ���� �������� =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cout << "���� �� ��������, �������� " << filename << std::endl;
    }
    for (const auto& x : pr) {
        outFile << x.number << " " << x.name << std::endl;
    }

    outFile.close();
    std::cout << "���������� ��������� � " << filename << std::endl;
}
void SaveToFileService(const std::vector<Service> sv, const std::string& filename) 
{
    std::cout << "\t\t _______________________________________________________________________________" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|=============================== ���� �������� =================================|" << std::endl;
    std::cout << "\t\t|===============================================================================|" << std::endl;
    std::cout << "\t\t|_______________________________________________________________________________|" << std::endl;
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cout << "���� �� ��������, �������� " << filename << std::endl;
    }
    for (const auto& x : sv) {
        outFile << x.number << " " << x.name << " "<<x.price  << " "<<x.IsRecorded << std::endl;
    }

    outFile.close();
    std::cout << "���������� ��������� � " << filename << std::endl;
}


std::vector<Product> ReadFromFileProduct(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Product> pr;

    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        pr = CreateProduct();
        return pr;
    }

    Product h;
    while (file >> h.number >> h.name) {
        pr.push_back(h);
    }

    file.close();
    return pr;
}

std::vector<Service> ReadFromFileService(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Service> sv;

    if (!file.is_open()) { 
        std::cout << "Unable to open file: " << filename << std::endl;
        sv = CreateService();
        return sv;
    }

    Service h;
    while (file >> h.number >> h.name >> h.price >> h.IsRecorded) {
        sv.push_back(h);
    }

    file.close();
    return sv;
}

std::vector<Doctor> ReadFromFileDoctors(const std::string& filename) {
    setlocale(0, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file(filename);
    std::vector<Doctor> dc;

    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        dc = CreateDoctor();
        return dc;
    }

    Doctor h;
    while (file >> h.number >>h.special) {
        dc.push_back(h);
    }

    file.close();
    return dc;
}



