/*Boggle Game by Joel R. Youngberg
Project CIS 17C
*/

//Including applicable libraries/constructs
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

//Function Prototypes here
//Checks to see if first letter in word is on board
void isOnBoardFirst(vector< vector<char> >, string, bool&, int&, bool&);
bool isEveryOther(vector< vector<char> >, string, int&, int, int);

void displayBoard(vector< vector<char> >);
string upperCase(string);
string lowerCase(string);

int main(){

	//Declaring variables
	//Declaring a two-dimensional vector of chars for boggle game
	vector< vector<char> > vec2D(5, vector<char>(5));
	//Initialize the random number seed
	srand(static_cast<unsigned int>(time(0)));
	//Temporary integer to get randomization before conv. to char
	int tempInt = 0;
	bool onBoard = false;//For determining if the first letter of a word is on the board
	int stop = 0; // for stopping the recursion...(matches size of string being checked)
	int match = 1; //If equal to word/string length... match was found
	bool fullWord = false;
	int valid = 0;


	//Fill board with random chars
	//Nested for loops
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			tempInt = rand() % 26 + 65;//[65,90]
			// test cout << tempInt << " ";
			vec2D[i][j] = (char) tempInt;//Casting random number between 65-90 to letters (ASCII capitals)
		}
	}//End nested for
	
	cout << endl;
	cout << "Welcome to BOGGLE!! " << endl;
	cout << "Please enter the words you find(press enter after each word): " << endl;
	cout << endl;
	//Display Vector
	displayBoard(vec2D);
	cout << endl;

	//Prompt for and take in list of words from player here
	list <string> P1Words;//Initialize list
	list <string>::iterator iter;//Defining iterator

	string tempWord;

	//Time this... if possible
	//In the event of a tie the better time wins
	

	do {
		cout << "Please enter a word: " << endl;
		cout << "Enter x to exit..." << endl;

		cin >> tempWord;
		if (tempWord == "x"){//Exiting on x
			cout << "You have exited: Checking words in dictionary... " << endl;
			cout << endl;
			break;
		}
		else{
			//add word to player 1 list
			P1Words.push_back(tempWord);
		}
	} while (tempWord != "x");

	// Display the list of words (player 1's)
	cout << "Your words were: " << endl;
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	cout << endl;

	//Check words to board (Are these words really on the board?)
	//First ensure that word list is upper case for letters to match board...
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		*iter = upperCase(*iter);
	}

	//Then call function to check if they are on the board
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		isOnBoardFirst(vec2D, *iter, onBoard, match, fullWord);//Check to see if first letter of word is on board
		//If first letter checks out... then check to see if the rest of the word is present
		//Call function here to check every other letter
		/////////////////////////////////////////////////////////////////////////////////////////
		if (fullWord){//Summing number of full words validated
			valid++;
		}

	}

	//Then ensure that words are lower case again to check in dictionary
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		*iter = lowerCase(*iter);
	}

	//Check word list and compare to dictionary
	//Declare filestream object
	fstream Dict;
	Dict.open("wordsEn.txt", ios::in);
	string curWord;//To hold current word while stepping through dictionary
	int p1Score = 0;//To hold score of player1

	//First step through each word in list - similar to display
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		// test cout << *iter << " " << endl;
		
		while (Dict){//While stepping through dictionary list
			Dict >> curWord;//Pulling from dictionary into current word
			if (*iter == curWord){//If current word from dictionary equals current word in player 1 list
				p1Score++;//Add 1 point to player one's score
				cout << *iter << " " << curWord << " Match Found!! +1 " << endl;
				continue;
		}//End if
			
      }//End while
		Dict.clear();//Clear filestream object value everytime we break out of while loop
		Dict.seekg(0, ios::beg);//Reset filestream object to beginning of file
	}//End For
	cout << endl;
	cout << "Player 1 Score before Validation: " << p1Score << endl;

	if (valid < p1Score){
		p1Score = valid;
	}
	cout << "Player 1 Score After Validation: " << p1Score << endl;
		
}//End main

void isOnBoardFirst(vector< vector<char> > vec2D, string pWord, bool &onBoard, int &match, bool &fullWord){
	
	//Find intitial first letter
	//Loop through board and check for letter
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){

			if (pWord[0] == vec2D[i][j]){
				//cout << "Vector Grid value: " << vec2D[i][j] << endl;
				//cout << "Found first letter... " << pWord[0] << endl;
				onBoard = true;
					//fullWord = isEveryOther(vec2D, pWord, match, i, j);/////////////////////////////////////
			}//End if
			else{
				//cout << "Did not find the first letter of this word..." << endl;
				//cout << "Vector Grid value: " << vec2D[i][j] << endl;
				//cout << "letter: " << pWord[0] << endl;
				onBoard = false;
			}
		}//End for
	}//End nested for
}//End bool isOnBoard

bool isEveryOther(vector< vector<char> > vec2D, string pWord, int &match, int i, int j){
	//Will be taking in same string as previous call

	//We know that first letter has been found at this point
	//Therefore, we can start checking at the second letter (index 1)
	//Check if second letter is contained within the perimeter of the first letter

	for (int k = 1; k < pWord.length(); k++){
		//Check all 8 directions on grid from original location
		if (vec2D[i - 1][j] == pWord[k]){//North
			match++;
			//If this matches, change i and j to new location
			i--;
			if (i < 0)
				i = 0;
		}
		if (vec2D[i + 1][j] == pWord[k]){//South
			match++;
			//If this matches, change i and j to new location
			i++;
			if (i > 5)
				i = 5;
		}
		if (vec2D[i][j + 1] == pWord[k]){//East
			match++;
			//If this matches, change i and j to new location
			j++;
			if (j > 5)
				j = 5;
		}
		if (vec2D[i + 1][j] == pWord[k]){//West
			match++;
			//If this matches, change i and j to new location
			i++;
			if (i > 5)
				i = 5;
		}
		if (vec2D[i - 1][j - 1] == pWord[k]){//NW
			match++;
			//If this matches, change i and j to new location
			i--;
			j--;
			if (i < 0)
				i = 0;
			if (j < 0)
				j = 0;
		}
		if (vec2D[i + 1][j - 1] == pWord[k]){//SW
			match++;
			//If this matches, change i and j to new location
			i++;
			j--;
			if (i > 5)
				i = 5;
			if (j < 0)
				j = 0;
		}
		if (vec2D[i + 1][j + 1] == pWord[k]){//SE
			match++;
			//If this matches, change i and j to new location
			i++;
			j++;
			if (i > 5)
				i = 5;
			if (j > 5)
				j = 5;
		}
		if (vec2D[i - 1][j + 1] == pWord[k]){//NE
			match++;
			//If this matches, change i and j to new location
			i--;
			j++;
			if (i < 0)
				i = 0;
			if (j > 5)
				j = 5;
		}

	}//End For loop
	cout << "match value is: " << match << endl;
	//When loop stops checking, check for a match
	if (match == pWord.length())
		return true;
	else
		return false;

	//We need the index locations though... and we should
	//still know them in our looping process... right?
	//if we don't we should save them and store them... then pass them in here...

	//utilizing the index location in the 2D vector,
	//we should be able to check the perimeter for the
	//next letter... then call the function again recursively

	//We will want to use a new boolean here to indicate whether each letter was found
	// 
	//


}//End every other function

void displayBoard(vector< vector<char> > vec2D){
	//Display Vector
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cout << vec2D[i][j] << " ";
		}
		cout << endl;
	}//End nested for
}

string upperCase(string str){
	//Change string to upper case
	transform(str.begin(), str.end(), str.begin(), toupper);
	//cout << str;
	return str;
}

string lowerCase(string str){
	//Change string to lower case
	transform(str.begin(), str.end(), str.begin(), tolower);
	//cout << str;
	return str;
}