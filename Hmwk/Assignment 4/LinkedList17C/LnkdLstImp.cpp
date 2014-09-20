//Including our library
#include "LnkdLst.h"

//Class member function definitions
LnkdLst::LnkdLst(int d){
    head = NULL; //Setting head of linked list to NULL
}

void LnkdLst::append(int integer){
    Node *newNode; //Points to a new node
    Node *nodePtr; //For moving through list

    //Allocating a new node & storing integer
    newNode = new Node;
    newNode->data = integer;
    newNode->next = NULL;

    //If there are no nodes in the linked list
    //Make newNode be the first node.
    if(!head)
        head = newNode;
    else {//Otherwise, insert newNode at the end
        //Initialize nodePtr to the head of the list
        nodePtr = head;//Start at beginning of list

        //Find the last node (by stepping through list)
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        //Insert newNode as the last node
        nodePtr->next = newNode;
    }
}//End append function

string LnkdLst::toString(){
    //std::string s = std::to_string(42);
    string temp;
    string str;
    Node *nodePtr; // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
     while (nodePtr)
    {
    // Put the value and a space into a string here ////////
    temp = to_string(nodePtr->data);
    str += temp + " ";

    // Move to the next node.
    nodePtr = nodePtr->next;
    }//End While

    return str;
}//End toString Function

LnkdLst::~LnkdLst(){
    //delete [] newNode;
}
