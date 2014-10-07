//Including our library
#include "LnkdLst.h"

//Class member function definitions
LnkdLst::LnkdLst(int d){
	head = NULL; //Setting head of linked list to NULL
}

void LnkdLst::append(int integer){
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

void LnkdLst::prepend(int integer){
	Node *newNode; //Points to a new node
	Node *temp;//Temporary Node pointer container

	//Allocating a new node & storing integer
	newNode = new Node;
	newNode->data = integer;
	
	temp = head; //Saving head address (it will become second node in list)

	head = newNode;//Set  head to address of newNode (newNode becomes head of list)

	head->next = temp;//Set next slot to old head (re-linking the list)

}//End prepend function

string LnkdLst::toString(){
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

LnkdLst::~LnkdLst(){//Destructor steps through list & deletes

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

int LnkdLst::getFirst(){
	//Return the first value in the linked list
	int num = 0;
	
	num = head->data;

	return num;
}

int LnkdLst::getLast(){
	int num = 0;

	worker = head;//Setting worker at beginning of list
	while (worker->next != NULL){
		worker = worker->next;//Stepping to next node
			num = worker->data;//Setting num to data member
	}

	return num;
}

int LnkdLst::position(int integer){

	worker = head; //Set worker to beginning of list

	for (int i = 1; i < integer; i++){
		worker = worker->next;
	}

	return worker->data;
}

void LnkdLst::extract(int integer){
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
