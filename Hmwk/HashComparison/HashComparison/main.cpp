//Joel R. Youngberg: Search Time Comparison Including Hashing
//Timing example...
//t0 = clock();
//code you want to benchmark
//t1 = clock();
//elapsed = t1 - t0;

//Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


//Function Prototypes
int linearSearch(string[], int, string);
void quickSort(string[], int, int);
int binarySearch(string[], int, string);

int main(){
	//Create large array
	const int size = 10000000;
	string *array;
	//Use dynamic allocation to create a larger array...
	array = new string[size];
	int numChar = 20;//Number of Characters (in each string)
	int randNum = 0;
	string notInAry = "$aaaaaaaaaaaaaaaaaaa";
	string value = notInAry;
	float t0, t1, elapseT;
	int matchInd = 0;

	//Initialize the random number seed
	srand(static_cast<unsigned int>(time(0)));

	char alpha[] = {"abcdefghijklmnopqrstuvwxyz"};
	
	//Fill array with random strings 20 Charachters long
	for (int i = 0; i < size; i++){
		//Looping 20X to fill with 20 characters each
		for (int j = 0; j < numChar; j++){
			randNum = rand() % 25;//Get new random number each time
			array[i] += alpha[randNum];//Concatenating random char here by randomly indexing alpha
		}
	}
	
	int left = 0;
	int right = size;
	//Sort array for binary search later...
	quickSort(array, left, right);

	cout << "Array Search Comparison Program: Joel R Youngberg" << endl;
	//Beginning with linear search times
	elapseT = clock();
	t0 = clock();
	matchInd = linearSearch(array, size, value);
	t1 = clock();
	elapseT = t1 - t0;
	cout << "Linear Search Time Not in Array: " << elapseT << endl;
	cout << matchInd << endl;

	value = array[50000];
	elapseT = clock();
	t0 = clock();
	matchInd = linearSearch(array, size, value);
	t1 = clock();
	elapseT = t1 - t0;
	cout << "Linear Search Time in Array (Halfway point): " << elapseT << endl;
	cout << matchInd << endl;

	//Binary Search Begins here:

	elapseT = clock();
	t0 = clock();
	matchInd = binarySearch(array, size, value);
	t1 = clock();
	elapseT = t1 - t0;
	cout << "Binary Search Time Not in Array: " << elapseT << endl;
	cout << matchInd << endl;

	value = array[50000];
	elapseT = clock();
	t0 = clock();
	matchInd = binarySearch(array, size, value);
	t1 = clock();
	elapseT = t1 - t0;
	cout << "Binary Search Time in Array (Halfway point): " << elapseT << endl;
	cout << matchInd << endl;
	
	

	
	

	//cout << array[0] << endl;
	cout << array[1] << endl;
	cout << array[2] << endl;
	cout << array[3] << endl;
	cout << array[50000] << endl;

	delete [] array;

	return 0;
}
//Function Definitions
int linearSearch(string array[], int numElems, string value){

	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found
	while (index < numElems && !found)
	{
		if (array[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}//End linearSearch

void quickSort(string arr[], int left, int right) {
	int i = left, j = right;
	string tmp;
	string pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}//End QuickSort

int binarySearch(string array[], int numElems, string value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag
	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}//End binarySearch