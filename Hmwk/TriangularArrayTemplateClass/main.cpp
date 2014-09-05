#include "TriAry.h"

using namespace std;

int main()
{
    cout << "Triangular Array Template Class" << endl;

    //Instatntiate triangular array object
    TriAry Trig;//Constructor Creates Arrays Here

    Trig.printArray();

    cout << endl;
    cout << endl;

    Trig.printArray2D();
    return 0;
}

