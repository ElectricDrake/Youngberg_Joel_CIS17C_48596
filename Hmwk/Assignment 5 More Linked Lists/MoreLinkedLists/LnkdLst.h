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
template <class T>
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

//Class member function definitions
template <class T>
LnkdLst<T>::LnkdLst(int d){
	head = NULL; //Setting head of linked list to NULL
}
template <class T>
void LnkdLst<T>::append(int integer){
	Node *newNode; //Points to a new node

	//Allocating a new node & storing integer
	newNode = new Node;
	newNode->data = integer;
	newNode->next = NULL;

	//If there are no nodes in the linked list
	//Make newNode be the first node.
	if (!head)
		head = newNode;
	else {//Otherwise, insert newNode at the end
		//Initialize worker to the head of the list
		worker = head;//Start at beginning of list

		//Find the last node (by stepping through list)
		while (worker->next)
			worker = worker->next;

		//Insert newNode as the last node
		worker->next = newNode;
	}
}//End append function
template <class T>
void LnkdLst<T>::prepend(int integer){
	Node *newNode; //Points to a new node
	Node *temp;//Temporary Node pointer container

	//Allocating a new node & storing integer
	newNode = new Node;
	newNode->data = integer;

	temp = head; //Saving head address (it will become second node in list)

	head = newNode;//Set  head to address of newNode (newNode becomes head of list)

	head->next = temp;//Set next slot to old head (re-linking the list)

}//End prepend function
template <class T>
string LnkdLst<T>::toString(){
	//std::string s = std::to_string(42);
	string temp;
	string str;

	// Position worker at the head of the list.
	worker = head;

	// While worker points to a node, traverse
	// the list.
	while (worker)
	{
		// Put the value and a space into a string here ////////
		temp = to_string(worker->data);
		str += temp + " ";

		// Move to the next node.
		worker = worker->next;
	}//End While

	return str;
}//End toString Function
template <class T>
LnkdLst<T>::~LnkdLst(){//Destructor steps through list & deletes

	Node *nextNode; // To point to the next node

	// Position worker at the head of the list.
	worker = head;

	// While worker is not at the end of the list...
	while (worker != NULL)
	{
		// Save a pointer to the next node.
		nextNode = worker->next;

		// Delete the current node.
		delete worker;

		// Position worker at the next node.
		worker = nextNode;
	}
}//End Destructor
template <class T>
int LnkdLst<T>::getFirst(){
	//Return the first value in the linked list
	int num = 0;

	num = head->data;

	return num;
}
template <class T>
int LnkdLst<T>::getLast(){
	int num = 0;

	worker = head;//Setting worker at beginning of list
	while (worker->next != NULL){
		worker = worker->next;//Stepping to next node
		num = worker->data;//Setting num to data member
	}

	return num;
}
template <class T>
int LnkdLst<T>::position(int integer){

	worker = head; //Set worker to beginning of list

	for (int i = 1; i < integer; i++){
		worker = worker->next;
	}

	return worker->data;
}
template <class T>
void LnkdLst<T>::extract(int integer){
	worker = head;//Setting worker at beginning of list - initializing

	Node *previous = worker;//Initializing

	//If list is empty do nothing (safeguard)
	if (!head)
		return;

	//Check first node
	if (head->data == integer){
		worker = head->next;//Temporarily storing value
		delete head;
		head = worker;//Assigning new head value
	}//End if
	else{
		//Init worker to head of list
		worker = head;
		//Skip values that do not match value to be deleted
		while (worker != NULL && worker->data != integer){
			previous = worker;
			worker = worker->next;
		}//End while
		//If not at end of list link back together
		if (worker){
			previous->next = worker->next;
			delete worker;
		}//End if
	}//End else
}//End function extract
template <class T>
LnkdLst<T>::LnkdLst(LnkdLst &obj){//Copy Constructor

	//Set workers to head of lists
	worker = head;
	obj.worker = obj.head;

	while (obj.worker != NULL){//Step through list & get length
		this->append(obj.worker->data);
		obj.worker = obj.worker->next;
	}
}//End Copy Constructor
template <class T>
void LnkdLst<T>::operator=(LnkdLst &obj){//Overloading assignment operator
	//Set workers to head of lists
	worker = head;
	obj.worker = obj.head;

	//Delete old list
	while (worker != NULL){//Step through list
		worker = head->next;//Temporarily storing value
		delete head;
		head = worker;//Assigning new head value
	}

	while (obj.worker != NULL){//Step through list
		//Add new values
		this->append(obj.worker->data);
		obj.worker = obj.worker->next;
	}

}//End assignment operator overload
template <class T>
void LnkdLst<T>::insertSort(int num){

	Node *newNode;
	Node *prev = NULL;

	newNode = new Node;
	newNode->data = num;


	// If there are no nodes in the list
	// make newNode the first node
	if (!head){
		head = newNode;
		newNode->next = NULL;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		worker = head;

		// Initialize previousNode to nullptr.
		prev = NULL;

		// Skip all nodes whose value is less than num.
		while (worker != NULL && worker->data < num)
		{
			prev = worker;
			worker = worker->next;
		}
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (prev == NULL){
			head = newNode;
			newNode->next = worker;
		}
		else // Otherwise insert after the previous node.
		{
			prev->next = newNode;
			newNode->next = worker;
		}//End else

	}//End Else insert new node

}//End insert Before

#endif	/* LNKDLST_H */

