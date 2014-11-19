/*
Joel R. Youngberg 17C Recursion Exercise
Create a sum function that has logN call like the max function from class.

Create a recursive savings function FV=PV*(1+i)^n  Savings=(pv,i,n) where pv = present value,

i = interest rate %/year and n = number of years.
*/

#include <iostream> // I/O
#include <cmath> //Pow function
using namespace std;

void futureValue(float, float, float, int, int, int);



int main(){
	//Declaring variables

	float PV = 0;
	float intRate = 0;
	float FV = 0;
	int years = 0;
	int stop = 0;
	int totalYears = 0;

	cout << "Please enter the present value (starting amount): " << endl;
	cin >> PV;

	cout << "Please enter the interest rate: " << endl;
	cin >> intRate;

	cout << "Please enter the number of years for this calculation: " << endl;
	cin >> totalYears;

	futureValue(PV, intRate, FV, years, stop, totalYears);

	return 0;
}

void futureValue(float PV, float intRate, float FV, int years, int stop, int totalYears){
	//Main function body

	FV = PV* pow(1 + intRate, years);//calculating future value

	cout << "Year: " << years << " Future value: " << FV << endl;

	stop++;
	years++;

	if (stop != totalYears){//limiter
		//call function again
		futureValue(PV, intRate, FV, years, stop, totalYears);
	}

}