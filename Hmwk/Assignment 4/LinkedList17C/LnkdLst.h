#ifndef LNKDLST_H
#define LNKDLST_H

/*
 * File:   LnkdLst.h
 * Author: Dr. Mark E. Lehr
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
         Node *next;//Self referential data structure
    };
    Node *head;
    Node *worker;

public://Class member functions
    LnkdLst(int);
    void append(int);
    string toString();
    virtual ~LnkdLst();
};

#endif	/* LNKDLST_H */

