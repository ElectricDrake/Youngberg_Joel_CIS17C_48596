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
	LnkdLst List(0);
	//Append 3 more chains
	cout << "Appending three values to list: " << endl;
	int clinks = 3;
	for (int i = 1; i <= clinks; i++){
		List.append(i);
	}
	//Print the data
	cout << "Test print of entire list: " << endl;
	cout << List.toString() << endl;

	cout << "Getting first value in list: " << endl;
	cout << List.getFirst() << endl;

	cout << "Getting last value in list: " << endl;
	cout << List.getLast() << endl;

	cout << "Prepending new first value (5) to list: " << endl;
	List.prepend(5);
	cout << List.toString() << endl;//Re output list...

	cout << "Returning Second Value from list..." << endl;
	cout << "(could be any value... takes an int - index starts at 1): " << endl;
	cout << List.position(2) << endl;

	cout << "Extracting value 2 from list: " << endl;
	List.extract(2);
	cout << List.toString() << endl;//Re output list...

	cout << "Demonstrating copy constructor: " << endl;
	//Declare second list object:
	LnkdLst List2(List);

	cout << "First List: " << endl;
	cout << List.toString() << endl;
	cout << "Copied List: " << endl;
	cout << List2.toString() << endl;//Re output list...

	cout << "Changing values of list 1 for assignment" << endl;
	cout << "operator demonstration..." << endl;
	List.extract(5);
	List.extract(1);
	List.extract(3);

	for (int i = 1; i <= clinks; i++){
		List.append(i);
	}

	cout << "First List: " << endl;
	cout << List.toString() << endl;
	cout << "Second List: " << endl;
	cout << List2.toString() << endl;//Re output list...

	cout << "Assignment Occurs Here: " << endl;
	List2 = List;
	cout << endl;
	cout << "First List: " << endl;
	cout << List.toString() << endl;
	cout << "Second List: " << endl;
	cout << List2.toString() << endl;//Re output list...

	cout << "Sorted Insert function(before and after)..." << endl;
	List.insertSort(2);
	List.insertSort(0);
	List.insertSort(9);
	cout << List.toString() << endl;








	//Exit stage right!
	return 0;
}
