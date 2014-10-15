/*Joel R. Youngberg 9 Oct 2014
Doubly Linked variation of Linked List
*/

#include "LnkdLst.h"
template <class T>
class DoublyLinked : public LnkdLst<T>{

public:

	void setPrevs();
	DoublyLinked(int d) : LnkdLst(d) {}
	void dblAppend(int d);
	string backwardPrint();
	//~StackQueue() : ~LnkdLst() {}
	

};

template <class T>
void DoublyLinked<T>::setPrevs(){

	//Set pointers to previous nodes
	//Temporary node ptr holder
	
	Node *temp;

	    worker = head;

		head->previous = NULL;

		worker = worker->next;//Step forward one data member in list

		worker->previous = head;//Set previous to point to previous node data member

		//Continue assigning to rest of list
		while (worker->next){
			temp = worker;//Storing current pointer/address
			worker = worker->next;//Stepping to next Node
			worker->previous = temp;//Setting previous to point to previous data member
		}


}

template <class T>
void DoublyLinked<T>::dblAppend(int d){
	//Pass in data
	this->append(d);
	this->setPrevs();
}

template <class T>
string DoublyLinked<T>::backwardPrint(){
	string str2;//string to return
	string temp;

	//First step through list
	worker = head;
	//Go to end of list
	while (worker->next){
		//cout << "worker: " << worker << endl;
		//cout << "previous: " << worker->previous << endl;
		worker = worker->next;
	}
	//cout << "worker: " << worker << endl;
	//cout << "previous: " << worker->previous << endl;
	//Traverse from back to front
	while (worker != head){
		temp = to_string(worker->data);
		str2 += temp + " ";
		worker = worker->previous;
	}
	str2 += to_string(head->data);
	str2 += " ";

	return str2;

	//cout << "head: " << head << endl;
	//cout << "worker: " << worker << endl;


}