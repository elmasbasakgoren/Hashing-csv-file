/***#include"Üst Bilgi.h"

Hash::Hash(int size) {
	assert(size > 0);
	HTSize = size;

	HTable = new int[HTSize];
	indexStatusList = new int[HTSize];

	length = 0;

	for (size_t i = 0; i < HTSize; i++)
	{
		indexStatusList[i] = 0;
	}
	coll = 0;
}
****/