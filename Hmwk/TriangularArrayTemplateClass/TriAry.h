#ifndef TRIARY_H
#define TRIARY_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


class TriAry{

private:
    int cols;
    int *array;
    int ** array2D;
    int ** trigAry;
    int cls, rows, perLine;

public:
    //Constructor creates first two arrays
    TriAry();
    //TriAry(int,int);
    //TriAry(int,int*);

    //Class Member Functions
    //Overloaded Display
    void printArray();
    void printArray2D();
    //void printArray(int**,int,int *);
    //Convert this to destructor
    //void destroy(int *);
    //void destroy(int **,int);

};

TriAry::TriAry(){
    //Create the 1D Array
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    cols = 5;
    cls=rows, perLine=10;
    array=new int[cols];
    //Fill array with random 2 digit numbers
    for(int col=0;col<cols;col++){
            array[col]=rand()%9+2;
    }
    //Create array2D here
    array2D=new int*[rows];
    for(int row=0;row<rows;row++){
      array[row]=new int[cols];
    }
    //Fill the array with random 2 digit numbers
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                array2D[row][col]=rand()%90+10;
            }
        }
}

//TriArray::TriArray(int,int){

//}

//TriArray::TriArray(int,int*){

//}

void TriAry::printArray(){
    //Print the Array
        cout<<endl;
        for(int col=0;col<cols;col++){
           cout<<array[col]<<" ";
           if(col%perLine==(perLine-1))cout<<endl;
        }
        cout<<endl;
}

void TriArray::printArray2D(){

}

//void TriArray::printArray(int**,int,int *){

//}

//void TriArray::destroy(int *){

//}

//void TriArray::destroy(int **,int){

//}

#endif // TRIARY_H
