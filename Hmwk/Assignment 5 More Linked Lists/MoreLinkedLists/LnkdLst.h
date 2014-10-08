#ifndef LNKDLST_H
#define LNKDLST_H

/*
* File:   LnkdLst.h
* Author: Dr. Mark E. Lehr Edited by Joel Youngberg
* Created on September 18, 2014, 3:09 PM
*/

//Including all applicable libraries
#include <iostream>//I/O + Iostream defines null on some implementations? http://stackoverflow.com/questions/12023476/what-header-defines-null-in-c
//This is because iostream includes cstddef...?
#include <string>

using namespace std;

class LnkdLst {
private://Class private variables/etc.
	struct Node{
		int data;
		Node *next;//For linking to next node
	};
	Node *head;
	Node *worker;

public://Class member functions
	LnkdLst(int);
	void append(int);
	void prepend(int);//More Linked List
	string toString();
	virtual ~LnkdLst();

	//More Linked List Additional Functions:
	int getFirst();
	int getLast();

	//copy constructor and assignment operator
	LnkdLst(LnkdLst &obj);
	void operator=(LnkdLst &obj);

	int position(int);//Returns value in that position... similar to array
	void extract(int);
	void insertSort(int);
	//void insertAfter(int);

	

};

#endif	/* LNKDLST_H */

