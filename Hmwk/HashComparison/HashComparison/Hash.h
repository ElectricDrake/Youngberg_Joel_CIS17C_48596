
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hash {
	private:
		static const int tableSize = 40;

		struct item{
			string name;
			string drink;
			item *next;
		};

		item *HashTable[tableSize];

	public:
		Hash();
		int hash(string key);
		void AddItem(string name, string drink);
		int NumberOfItems(int index);
		void PrintTable();
		void PrintItemsInIndex(int index);
		void FindDrink(string name);
};



#endif /* HASH_H */