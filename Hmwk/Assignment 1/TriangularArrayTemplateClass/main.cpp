/*
 * Joel R. Youngberg Triangular Array Template Class
 * 5 Sep 2014
 * This program demonstrates a 2D array with variation
 * in its column sizes.
 */

#include "TriAry.h"

int main()
{
    cout << "Triangular Array Template Class: Joel R. Youngberg" << endl;

    //Instantiate triangular array object
    TriAry<int>Trig;//Constructor Creates Arrays Here/Int Object

    Trig.printArray();//Printing Column array

    Trig.printArray2D();//Test print of regular 2D array

    Trig.printTriAry();//Print integer implementation of
                       //Triangular Array

    TriAry<float>TrigFloat;//Creating float object

    TrigFloat.printTriAry();//Print float implementation of
                            //Triangular Array


    return 0;
}

