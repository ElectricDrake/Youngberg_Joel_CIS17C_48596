//Joel R. Youngberg Simple Vector with push & pull
#include "SimpleVector.h"

using namespace std;

int main()
{
    int initSize = 0;
    int pp = 0;
    int pushVal = 0;
    //int indexVal = 0; //Originally for choosing index to pull...

    cout << "Simple Vector Program With Push & Pull Features" << endl;

    do{//Validate input - must be at least one index in inital creation
    cout << "Please enter the number of indexes for the initial vector: " << endl;
    cin >> initSize;

    if(initSize<=0){
        cout << "Error... must create at least one index to initialize vector..." << endl;
        cout << "What good is a vector with no indexes anyway!!?" << endl;
        cout << endl;
    }

    }while(initSize<=0);

    //Instantiate Vector Object
    SimpleVector<int> Vector(initSize);

    //Display Vector...
    Vector.display();

    //Demonstrating push/pull functions:
    do{
    cout << "Would you like to push a value to the vector or pull from it?" << endl;
    cout << "Enter a 1 to push, or a 0 to pull, or -1 to exit: " << endl;
    cin >> pp;

    if (pp == -1){
        cout << "Exiting..." << endl;
        break;
    }

    else if (pp == 1){//If pushing a value, execute this:
        cout << "Please enter a value to add to the vector: " << endl;
        cin >> pushVal;
        Vector.push(pushVal);
        //Display Vector with new value
        Vector.display();
    }
    else if (pp == 0) {//If pulling a value, execute this:
        cout << endl;
        cout << "Pulling value from the end of vector: " << endl;
        Vector.pull();
        //Display Vector with removed value
        Vector.display();
    }
    }while(pp!=-1);












    return 0;
}

