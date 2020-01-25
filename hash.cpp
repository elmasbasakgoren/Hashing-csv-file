#include "hash.h"
#include<iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include<sstream>

using namespace std;

Hash::Hash() //constructor
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->StockCode = "empty";
		HashTable[i]->Desc = "empty";
		HashTable[i]->Quantity = "empty";
		HashTable[i]->next = NULL;
	}
}

void Hash::AddItem(string StockCode, string Desc, string Quantity)
{ 
	//int b = atoi(Quantity.c_str());
	stringstream  geek(Quantity);
	int b = 0;
	geek >> b;

	int index = HashF(StockCode);

	if (HashTable[index]->StockCode == "empty")
	{
		HashTable[index]->StockCode = StockCode;
		HashTable[index]->Desc = Desc;
		HashTable[index]->q = b;
	}

	else if (HashTable[index]->StockCode == StockCode) {
		HashTable[index]->q += b;
	}
	
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->StockCode = StockCode;
		n->Desc = Desc;
		n->q = b;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
	
}

int Hash::NumberOfItemsInIndex(int index) // check to see how many items in bucket
{
	int count = 0;

	if (HashTable[index]->StockCode == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];

		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void Hash::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		if (HashTable[i]->StockCode != "empty") {
			number = NumberOfItemsInIndex(i);
			cout << "---------------------\n";
			cout << "index = " << i << endl;
			cout << HashTable[i]->StockCode << endl;
			cout << HashTable[i]->Desc << endl;
			cout << HashTable[i]->q<< endl;
			cout << "# of items = " << number << endl;
			cout << "---------------------\n";

		}
	}
	
}

void Hash::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];//check just this bucket or index

	if (Ptr->StockCode == "empty")
	{
		cout << "bucket " << index << " is empty";
		cout << endl;
	}
	else
	{
		cout << "bucket " << index << " contains the following item\n";

		while (Ptr != NULL) // as long as bucket is not empty
		{
			cout << "--------------------\n";
			cout << Ptr->StockCode << endl;
			cout << Ptr->Desc << endl;
			cout << Ptr->Quantity << endl;
			cout << "--------------------\n";
			Ptr = Ptr->next; // check for next name
		}
	}

}

int Hash::HashF(string key)  //fonksiyonu burda yazýyoruz

{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

//void Hash::Quicksort(HashTable->q, int low, int high)
//	{
//		if (low < high)
//		{
//			/* pi is partitioning index, arr[p] is now
//			   at right place */
//			int pi = partition(*HashTable->q, low, high);
//	
//			QuickSort(HashTable->q, low, pi - 1);
//			QuickSort(item*HashTable, pi + 1, high);
//		}
//	}
//
//int Hash:: partition(item* HashTable, int low, int high)
//{
//	int pivot = arr[high];    // pivot 
//	int i = (low - 1);  // Index of smaller element 
//
//	for (int j = low; j <= high - 1; j++)
//	{
//		// If current element is smaller than or 
//		// equal to pivot 
//		if (arr[j] <= pivot)
//		{
//			i++;    // increment index of smaller element 
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}

