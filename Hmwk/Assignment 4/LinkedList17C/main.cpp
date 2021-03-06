/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr Edited by Joel R. Youngberg
 * Created on September 18, 2014, 1:55 PM
 * Purpose:  Explore creation of a linked list class Version 3
 */

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {

    cout << "Linked List By Joel R. Youngberg: " << endl;

    //Create a linked list
    LnkdLst list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    return 0;
}
