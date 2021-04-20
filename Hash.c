#include<stdio.h>
#include "Hash.h"

int hash_main()
{

	struct Node* HashTable[10];
	initHashTable(HashTable);
	insertHashTable(HashTable, 11);
	insertHashTable(HashTable, 22);
	insertHashTable(HashTable, 33);
	insertHashTable(HashTable, 42);
	insertHashTable(HashTable, 29);
	displayHashTable(HashTable);
	return 0;
}