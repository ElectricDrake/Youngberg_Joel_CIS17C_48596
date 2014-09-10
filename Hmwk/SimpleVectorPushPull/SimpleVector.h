// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   T *arrayTemp;       // To hold values of array when changing size
   int arraySize;    // Number of elements in the array
   int arrayCap;     // Total Capacity of array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}

   // Constructor declaration
   SimpleVector(int);

   // Copy constructor declaration
   SimpleVector(const SimpleVector &);

   // Destructor declaration
   ~SimpleVector();

   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);

   //Push function for adding new index onto array (vector)
   void push(T);

   //Pull function for subtracting an index from array (vector)
   void pull();

   //Display function for the vector
   void display();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   arrayCap = s*2;
   // Allocate memory for the array - array capacity is doubled
   try
   {
      aptr = new T [arrayCap];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array - setting all values to zero
   for (int count = 0; count < arrayCap; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arrayCap = obj.arrayCap;

   // Allocate memory for the array.
   aptr = new T [arrayCap];
   if (aptr == 0)
      memError();

   // Copy the elements of obj's array.
   for(int count = 0; count < arrayCap; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arrayCap > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//Push function for adding new index onto array (vector)
template <class T>
void SimpleVector<T>::push(T add){
    arraySize++;//Add additional array index
    //Add value to index at last location:
    aptr[arraySize-1] = add;
    //If the array capacity is reached:
    //Recreate the array and double the size
    if (arraySize == arrayCap){
        arrayCap *= 2;//Doubling array capacity

        //Allocate a temporary array
            arrayTemp = new T [arrayCap];
            //Initialize, then Fill temporary array with old values
            // Initialize the array - setting all values to zero
         for (int count = 0; count < arrayCap; count++)
            arrayTemp[count] = 0;

        for(int i=0;i<arraySize;i++){
            arrayTemp[i] = aptr[i];//Assigning current values to temporary array
        }//End for loop

        delete [] aptr;//delete old array

        //Now create new array by changing pointer to temporary array
        aptr = arrayTemp;

    }//End if Statement
}//End push function

//Pull function for subtracting an index from array (vector)
template <class T>
void SimpleVector<T>::pull(){
    //Set last array value to zero
    aptr[arraySize-1] = 0;
    arraySize--;//Remove array index
}

template <class T>
void SimpleVector<T>::display(){
    for(int i=0; i< arraySize;i++){
        cout << aptr[i] << " ";
    }
    cout << endl;
    cout << endl;
    //Test Display
    for(int i=0; i< arrayCap;i++){
        cout << aptr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

#endif
