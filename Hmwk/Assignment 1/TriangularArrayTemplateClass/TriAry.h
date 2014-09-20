#ifndef TRIARY_H
#define TRIARY_H

//System Libraries
#include <cstdlib>//Random # generation
#include <iostream>//I/O
#include <ctime>//Random # generation
#include <iomanip>//To show floats vs ints
using namespace std;

template <class T>
class TriAry{

private:
    int cols;
    int *array;//Column Array
    int ** array2D;// Two dimensional test array
    T ** trigAry;// Triangular array
    int cls, rows, perLine;

public:
    //Constructor creates/initializes three first arrays
    TriAry();
    //Destructor to clean up dynamic arrays
    ~TriAry();

    //Class Member Functions
    void templateTrigAry();
    void printArray();
    void printArray2D();
    void printTriAry();
};
template <class T>
TriAry<T>::TriAry(){
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
      array2D[row]=new int[cols];
    }
    //Fill the array with random 2 digit numbers
        rows=5;
        cols=10;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                array2D[row][col]=rand()%90+10;
            }
        }//End Create Regular 2D Array

        //Create Triangular array
            trigAry=new T*[rows];
            for(int row=0;row<rows;row++){
                trigAry[row]=new T[array[row]];
            }
            //Fill the array with random 2 digit numbers
            for(int row=0;row<rows;row++){
                for(int col=0;col<array[row];col++){
                    trigAry[row][col]=rand()%90+10;
                }
            }

}//End Constructor
template <class T>
TriAry<T>::~TriAry(){
    //Destroy row pointers
    delete []array;

    //Destroy row pointers
    delete []array2D;

    //Destroy cols
    for(int row=0;row<rows;row++){
           delete []trigAry[row];
       }
       //Destroy row pointers
       delete []trigAry;

}
template <class T>
void TriAry<T>::printArray(){
    //Print the Array
        cout<<endl;
        cols=5;
        for(int col=0;col<cols;col++){
           cout<<array[col]<<" ";
           if(col%perLine==(perLine-1))cout<<endl;
        }
        cout<<endl;
}
template <class T>
void TriAry<T>::printArray2D(){
    //Print array2D
    cols=10;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array2D[row][col]<<" ";
        }
        cout << endl;
    }
}
template <class T>
void TriAry<T>::printTriAry(){
    //Print the Array
    cout << fixed << showpoint << setprecision(2);
        cout<<endl;
        for(int row=0;row<rows;row++){
            for(int col=0;col<array[row];col++){
                cout<<trigAry[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}

void templateTrigAry(){

}

#endif // TRIARY_H
