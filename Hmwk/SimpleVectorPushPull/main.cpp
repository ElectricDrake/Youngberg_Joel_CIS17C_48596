
#include "SimpleVector.h"

using namespace std;

int main()
{
    cout << "Simple Vector Test..." << endl;


    SimpleVector<int> Vector(10);

    //Fill Vector...
    for(int i=0; i<10;i++){
        Vector[i]=0;
    }

    //Display Vector...
    for(int i=0; i<10;i++){
        cout << Vector[i] << " ";
    }








    return 0;
}

