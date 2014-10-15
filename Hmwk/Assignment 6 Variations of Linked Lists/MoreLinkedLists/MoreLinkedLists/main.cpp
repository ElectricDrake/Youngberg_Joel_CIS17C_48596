/*
* File:   main.cpp
* Author: Dr. Mark E. Lehr Edited by Joel R. Youngberg
* Created on September 18, 2014, 1:55 PM
* Purpose:  Explore creation of a linked list class Version 3
* Note: This code utilizes some C++ 11 functions i.e. to_string()
* It may not compile without a C++ 11 compatible compiler
*/

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {

	cout << "Linked List By Joel R. Youngberg: " << endl;

	//Create a linked list
	LnkdLst list(0);
	//Append 3 more chains
	cout << "Appending three values to list: " << endl;
	int clinks = 3;
	for (int i = 1; i <= clinks; i++){
		list.append(i);
	}
	//Print the data
	cout << "Test print of entire list: " << endl;
	cout << list.toString() << endl;

	cout << "Getting first value in list: " << endl;
	cout << list.getFirst() << endl;

	cout << "Getting last value in list: " << endl;
	cout << list.getLast() << endl;

	cout << "Prepending new first value (5) to list: " << endl;
	list.prepend(5);
	cout << list.toString() << endl;//Re output list...

	cout << "Returning Second Value from list..." << endl;
	cout << "(could be any value... takes an int - index starts at 1): " << endl;
	cout << list.position(2) << endl;

	cout << "Extracting value 2 from list: " << endl;
	list.extract(2);
	cout << list.toString() << endl;//Re output list...


	//Exit stage right!
	return 0;
}
