/*
* File:   main.cpp
* Author: Dr. Mark E. Lehr Edited by Joel R. Youngberg
* Created on September 18, 2014, 1:55 PM
* Purpose:  Explore creation of a linked list class Version 3
* Note: This code utilizes some C++ 11 functions i.e. to_string()
* It may not compile without a C++ 11 compatible compiler
*Create a stack/queue from your linked list.

Create a doubly linked list.

Create a circularly linked list.

Create a priority linked list -> priority queue.

Create a sorted linked list.

Submit here, email, post at Github.  Copy yourself on email, and send to mark.lehr@rcc.edu with subject:  Lastname, Firstname - Assignment 6 - 48596
*/

//Our Librarys
#include "LnkdLst.h"
#include "StackQueue.h"
#include "DoublyLinked.h"
#include "CircList.h"

int main(int argc, char** argv) {

	cout << "Linked List By Joel R. Youngberg: " << endl;

	//Create a linked list
	LnkdLst<int> List(0);
	//Append 3 more chains
	cout << "Appending three values to list: " << endl;
	int clinks = 3;
	for (int i = 1; i <= clinks; i++){
		List.append(i);
	}
	//Print the data
	cout << "Test print of entire list: " << endl;
	cout << List.toString() << endl;

	//Create a stack (inherits from linked list...)
	StackQueue<int> Stack(0);
	cout << "Adding values to stack: " << endl;
	Stack.push(1);
	Stack.push(2);
	Stack.push(3);

	
	cout << Stack.toString() << endl;
	cout << endl;

	cout << "Removing from top: " << endl;
	Stack.pop();

	
	cout << Stack.toString() << endl;
	cout << endl;

	StackQueue<int> Queue(0);
	cout << "Adding values to back of queue: " << endl;
	Queue.add(1);
	Queue.add(2);
	Queue.add(3);

	
	cout << Queue.toString() << endl;
	cout << endl;

	cout << "Removing value from front of queue: " << endl;
	Queue.pop();

	
	cout << Queue.toString() << endl;
	cout << endl;

	DoublyLinked<int> dblList(0);

	dblList.dblAppend(1);
	dblList.dblAppend(2);
	dblList.dblAppend(3);

	cout << "Test print doubly linked list: " << endl;
	cout << "Printing forward: " << endl;
	cout << dblList.toString() << endl;
	
	cout << "Test print doubly linked list: " << endl;
	cout << "Printing backward: " << endl;
	cout << dblList.backwardPrint();
	cout << endl;

	cout << "Testing circularly linked list: " << endl;
	CircLinked<int> CircList(0);
	CircList.circInsertSort(1);
	CircList.circInsertSort(2);
	CircList.circInsertSort(3);
	CircList.circInsertSort(4);
	CircList.circInsertSort(5);
	CircList.circInsertSort(6);

	cout << CircList.toString() << endl;
	//Exit stage right!
	return 0;
}
