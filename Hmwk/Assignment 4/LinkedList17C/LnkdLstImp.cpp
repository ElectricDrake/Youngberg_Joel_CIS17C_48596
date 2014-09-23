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
    if(!head)
        head = newNode;
    else {//Otherwise, insert newNode at the end
        //Initialize worker to the head of the list
        worker = head;//Start at beginning of list

        //Find the last node (by stepping through list)
        while(worker->next)
            worker = worker->next;

        //Insert newNode as the last node
        worker->next = newNode;
    }
}//End append function

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
}

