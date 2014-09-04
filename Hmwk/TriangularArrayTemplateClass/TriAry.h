#ifndef TRIARY_H
#define TRIARY_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class TriAry{

private:

public:
    //Class Member Functions
    //Overloaded Constructor
    TriArray(int);
    TriArray(int,int);
    TriArray(int,int*);
    //Overloaded Display
    void printArray(int*,int,int);
    void printArray(int**,int,int);
    void printArray(int**,int,int *);
    //Convert this to destructor
    void destroy(int *);
    void destroy(int **,int);

};

TriArray(int){

}

TriArray(int,int){

}

TriArray(int,int*){

}

void printArray(int*,int,int){

}

void printArray(int**,int,int){

}

void printArray(int**,int,int *){

}

void destroy(int *){

}

void destroy(int **,int){

}

#endif // TRIARY_H
