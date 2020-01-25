#include"hash.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <ctime>
using namespace std;
//Timer
clock_t startTime, endTime;

int main() {
	time_t srand(time(NULL));
	startTime = clock();

	Hash Hashy;

	ifstream OnlineRetail("C:\\Users\\elmas\\OneDrive\\Masaüstü\\OnlineRetail.csv", ios::in);

	if (!OnlineRetail.is_open()) std::cout << "ERROR: File Open" << '\n';

	string InvoiceNo; //igno
	string StockCode;
	string Description;
	string Quantity;
	string Date; //igno
	string Price; //igno
	string CusId;  //igno
	string Country; //igno


	while (OnlineRetail.good()) {

		getline(OnlineRetail, InvoiceNo, ';');
		//cout << "Invoice No " << InvoiceNo << " " << '\n';
		getline(OnlineRetail, StockCode, ';');
		//cout << "StockCode:   " << StockCode << " " << '\n';
		getline(OnlineRetail, Description, ';');
		//std::cout << "Desc:   " << Description << " " << '\n';
		getline(OnlineRetail, Quantity, ';');
		//std::cout << "Quantity:  " << Quantity << " " << '\n';
		getline(OnlineRetail, Date, ';');
		//std::cout << "Date " << Date << " " << '\n';
		getline(OnlineRetail, Price, ';');
		//std::cout << "Price " << Price << " " << '\n';
		getline(OnlineRetail, CusId, ';');
		//std::cout << "CusId " << CusId << " " << '\n';
		getline(OnlineRetail, Country, '\n');
		//std::cout << "Country " << Country << " " << '\n'; 

		Hashy.AddItem(StockCode, Description, Quantity);

	}
	Hashy.PrintTable();

	OnlineRetail.close();
	endTime = clock();

	double diff((double)((float)endTime - (float)startTime) / 1000);
	cout << "\n\n    Total Second : " << diff << "\n\n" << endl;


	system("pause");

	

	return 0;
}

