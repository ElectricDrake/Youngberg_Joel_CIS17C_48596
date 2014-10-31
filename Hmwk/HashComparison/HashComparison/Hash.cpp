#include "Hash.h"

void Hash::FindDrink(string name){
	int index = hash(name);
	bool foundName = false;
	string drink;

	item *Ptr = HashTable[index];
	while (Ptr != NULL){
		if (Ptr->name == name){
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true){
		cout << "Favorite Drink = " << drink << endl;
	}
	else{
		cout << name << "'s info not found in table" << endl;
	}
}

void Hash::PrintTable(){
	int number;
	for (int i = 0; i < tableSize; i++){
		number = NumberOfItems(i);
		cout << "-----------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------------\n";
	}
}

void Hash::PrintItemsInIndex(int index){
	item *Ptr = HashTable[index];
	if (Ptr->name == "empty"){
		cout << "index " << index << " is empty...";
	}
	else{
		cout << "index " << index << " contains the following items\n";
		while (Ptr != NULL){
			cout << "-----------------------\n";
			cout << Ptr->name << endl;
			cout << Ptr->drink << endl;
			cout << "-----------------------\n";
			Ptr = Ptr->next;
		}
	}

}

int Hash::NumberOfItems(int index){
	int count = 0;
	if (HashTable[index]->name == "empty"){
		return count;
	}
	else{
		count++;
		item *Ptr = HashTable[index];
		while (Ptr->next != NULL){
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void Hash::AddItem(string name, string drink){
	int index = hash(name);

	if (HashTable[index]->name == "empty"){
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else{//Create new item (append to list)
		item *Ptr = HashTable[index];
		item *n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL){//Traverse to end of list
			Ptr = Ptr->next;
		}
		Ptr->next = n;//Setting new item to be last in list
	}
}

Hash::Hash(){

	for (int i = 0; i < tableSize; i++){
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;

	}
}

int Hash::hash(string key){

	int hash = 0;
	int index;

	index = key.length();

	for (int i = 0; i < key.length(); i++){
		//Cumulatively add integer (ASCII Value) of string 
		hash = (hash + (int)key[i]) * 17;					
	}

	index = hash % tableSize;

	return index;
	
}