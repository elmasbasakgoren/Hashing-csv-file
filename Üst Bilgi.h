#pragma once
/***
#include<iostream>
#include<cassert>
using namespace std;

class Hash {
public:
	Hash(int size = 1000000);
	void insert(int hashIndex, const int& rec);
	void search(int& hashIndex, const int& rec, bool& found) const;
	bool isItemAtEqual(int hashIndex, const int& rec) const;
	void print() const;
	~Hash();


	int *HTable; //pointer to the hash table
	int *indexStatusList; //pointer to the array indicating the
	int length; //# of items in the hash table
	int HTSize; //max size of the hash table
	int coll;

}; ***/