#include<vector>
#include<iostream>
#include<string.h>

namespace a {
	struct Service
	{
		int number{};
		std::string name{};
		int price{};
		bool IsRecorded{};
	};

	struct Doctor {
		int number{};
		std::string special{};

	};

	struct Product {
		int number{};
		std::string name{};
	};
}
using namespace a;

void menu();
void ViewProducts(std::vector<Product> pr);
std::vector<Product>*AddProducts(std::vector<Product>& pr);
std::vector<Product>* DeleteProducts(std::vector<Product>& pr);
void ListOfDoctor(std::vector<Doctor>& dc);
void ListOfService(std::vector<Service>& sv);
std::vector<Service>* MakeAnAppointment(std::vector<Service>& sv);
void ViewRecord(std::vector<Service> sv);
void SaveToFileProduct(const std::vector<Product> pr, const std::string& filename);
void SaveToFileService(const std::vector<Service> sv, const std::string& filename);
void Error();
std::vector<Product> CreateProduct();
std::vector<Service> CreateService();
std::vector<Doctor> CreateDoctor();
std::vector<Product> ReadFromFileProduct(const std::string& filename);
std::vector<Service> ReadFromFileService(const std::string& filename);
std::vector<Doctor> ReadFromFileDoctors(const std::string& filename);