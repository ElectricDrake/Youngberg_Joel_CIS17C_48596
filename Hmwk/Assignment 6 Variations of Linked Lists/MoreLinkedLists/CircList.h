/*Joel R. Youngberg 9 Oct 2014
Circularly Linked variation of Linked List
*/

#include "LnkdLst.h"
template <class T>
class CircLinked : public LnkdLst<T>{

public:
	CircLinked(int d) : LnkdLst(d) {}
	void circInsertSort(int d);
	string circToString();
	//~CircLinked() : ~LnkdLst() {}

};

template <class T>
void CircLinked<T>::circInsertSort(int num){
	Node *newNode;
	Node *prev = NULL;

	newNode = new Node;
	newNode->data = num;


	// If there are no nodes in the list
	// make newNode the first node
	if (!head){
		head = newNode;
		newNode->next = NULL;//Have the only single node point to NULL
	}
	else // Otherwise, insert newNode
	{
		// Position worker at the head of list.
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
	
}//End insertSort function

template <class T>
string CircLinked<T>::circToString(){
	
	string temp;
	string str;
	int loops = 0;

	// Position worker at the head of the list.
	worker = head;

	// While worker points to a node, traverse
	// the list.
	while (loops < 3)
	{
		// Put the value and a space into a string here ////////
		cout << worker->data << endl;
		temp = to_string(worker->data);
		str += temp + " ";

		
		//if (worker == head){
			//loops++;
		//}
		// Move to the next node.
		worker = worker->next;
	}//End While

	return str;
}//End toString