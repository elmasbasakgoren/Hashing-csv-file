#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include <ctime>

using namespace std;
class Hash
{
public:
	static const int tableSize = 100; //sets table size

	struct item //defines each "array cell"
	{
		string StockCode;
		string Desc;
		string Quantity;
		int q;
		item* next;
	};

	item* HashTable[tableSize];

	Hash(); //constructor

	int HashF(string key); // determines index

	void AddItem(string StockCode, string Desc, string Quantity);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	/*void Quicksort(HashTable->q, int low,int high);
	int partition(item*HashTable, int low, int high);*/
};