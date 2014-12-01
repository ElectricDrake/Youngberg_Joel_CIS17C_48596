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

//Struct here...
struct Coords{
	int index1;
	int index2;
	string pWord;
};

//Function Prototypes here
//Checks to see if first letter in word is on board
void isOnBoardFirst(vector< vector<char> >, string, vector<Coords>&, Coords);

void checkPerimeter(vector< vector<char> >, Coords&, int&, int&, string);

//Displays gameboard
void displayBoard(vector< vector<char> >);
//Performs upper and lower case conversions of player word list
string upperCase(string);
string lowerCase(string);

int main(){

	//Declaring variables
	//Declaring a two-dimensional vector of chars for boggle game
	vector< vector<char> > vec2D(7, vector<char>(7));

	//Initialize the random number seed
	srand(static_cast<unsigned int>(time(0)));

	int tempInt = 0;//Temporary integer to get randomization before conv. to char
	bool onBoard = false;//For determining if the first letter of a word is on the board
	int stop = 0; // for stopping the recursion...(matches size of string being checked)
	int match = 1; //If equal to word/string length... match was found
	bool fullWord = false;
	int valid = 0;
	int index = 1;

	Coords tempCoords;//Stucture for holding 2D vector index coordinates
	tempCoords.index1 = 0;
	tempCoords.index2 = 0;

	vector<Coords> CoordList(1);//For storing index coordinates of the locations of found first letters of words
	CoordList[0].index1 = 0;
	CoordList[0].index2 = 0;

	vector<Coords> NewCoordList(1);//Declaring new local temp vector...
	NewCoordList[0].index1 = 0;//Setting first indexes of first object to zero
	NewCoordList[0].index2 = 0;

	


	

	////-----------------------------------BOARD SETUP-------------------------------------------------------////////
	//Fill board with random chars
	//Nested for loops
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			tempInt = rand() % 26 + 65;//[65,90]
			// test cout << tempInt << " ";
			vec2D[i][j] = (char) tempInt;//Casting random number between 65-90 to letters (ASCII capitals)
		}
	}//End nested for

	//Set edges of board to '*'
	for (int i = 0; i < 7; i++){
		vec2D[0][i] = '*';
		vec2D[i][0] = '*';
		vec2D[6][i] = '*';
		vec2D[i][6] = '*';
	}//End setting stars on border

	////-----------------------------------INTRO-------------------------------------------------------////////
	cout << endl;
	cout << "Welcome to BOGGLE!! " << endl;
	cout << "Please enter the words you find(press enter after each word): " << endl;
	cout << endl;
	//Display Gameboard
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
		cout << "Enter # when list is finished..." << endl;

		cin >> tempWord;
		if (tempWord == "#"){//Exiting on x
			cout << endl;
			cout << "You have entered # to finish: Checking words in dictionary... " << endl;
			cout << endl;
			break;
		}
		else{
			//add word to player 1 list
			P1Words.push_back(tempWord);
		}
	} while (tempWord != "#");

	// Display the list of words (player 1's)
	cout << "Your words were: " << endl;
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	cout << endl;

	////-----------------------------------CHECK: ARE WORDS IN LIST ON GAMEBOARD?-------------------------------------------------------////////
	//Check words to board (Are these words really on the board?)
	//First ensure that word list is upper case for letters to match board...
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		*iter = upperCase(*iter);
	}

	//Then call function to check if first letter of word is on the board - if it is, store index coordinates
	//For further checking in additional vector
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		isOnBoardFirst(vec2D, *iter, CoordList, tempCoords);//Check to see if first letter of word is on board
		//If first letter checks out... then check to see if the rest of the word is present
		//Function to check the rest of the letters is called within the first letter function above
	}//End for

	//Displaying vector CoordList here...
	//Test to see what coordinates have been stored
	// test cout << "Contents of CoordList: " << endl;
	//cout << "coordlist size check: " << CoordList.size() << endl;
	for (int i = 1; i < CoordList.size(); i++){
		// test cout << "coordlist value: " << CoordList[i].index1 << endl;
		// test cout << "coordlist value: " << CoordList[i].index2 << endl;
		//Take one set of coordinates and branch from them to find if a word is on the board
		index = 1; //Reset index to one each time this function starts over (or has a new word)
		checkPerimeter(vec2D, CoordList[i], index, valid, CoordList[i].pWord);
	}
	//////////////////////////////////////////////////////
	cout << endl; //split between found on board and dictionary check
	//////////////////////////////////////////////////////

	//Then ensure that words are lower case again to check in dictionary
	for (iter = P1Words.begin(); iter != P1Words.end(); iter++){
		*iter = lowerCase(*iter);
	}

	//-------------------------DICTIONARY COMPARISON--------------------/////////////////
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
				cout << *iter << " " << curWord << " Dict. Match Found!! +1 " << endl;
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
	cout << "Player 1 valid value for test: " << valid << endl;









///////////////////////////////////////////////////////////////////////////////////
}////////////////////////////////////END MAIN/////////////////////////////////////////////----------------------------------------------------------------------------------------------------->
/////////////////////////////////////////////////////////////////////////////////////////////////////

void checkPerimeter(vector< vector<char> > vec2D, Coords &fLoc, int &index, int &valid, string pWord){

	//Takes in one set of coordinates (from where first letter was found)
	//And checks the perimeter of the location from those indices.
	//Increments valid if the letter count matches the count of the word index

	if (vec2D[fLoc.index1 - 1][fLoc.index2 - 1] == pWord[index]){//Northwest Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 -= 1;//Northwest Grid Location
		fLoc.index2 -= 1;//Northwest Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1 - 1][fLoc.index2] == pWord[index]){//North Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 -= 1;//North Grid Location
		fLoc.index2;//North Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1 - 1][fLoc.index2 + 1] == pWord[index]){//Northeast Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 -= 1;//Northeast Grid Location
		fLoc.index2 += 1;//Northeast Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1][fLoc.index2 + 1] == pWord[index]){//East Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1;//East Grid Location
		fLoc.index2 += 1;//East Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1 + 1][fLoc.index2 + 1] == pWord[index]){//SouthEast Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 += 1;//SouthEast Grid Location
		fLoc.index2 += 1;//SouthEast Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1 + 1][fLoc.index2] == pWord[index]){//South Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 += 1;//South Grid Location
		fLoc.index2;//South Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1 + 1][fLoc.index2 - 1] == pWord[index]){//Southwest Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1 += 1;//Southwest Grid Location
		fLoc.index2 -= 1;//Southwest Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check

	if (vec2D[fLoc.index1][fLoc.index2 - 1] == pWord[index]){//West Grid Location

		// test cout << "Letter " << pWord[index] << " found" << endl;

		//Changing location of first location to new location
		fLoc.index1;//West Grid Location
		fLoc.index2 -= 1;//West Grid Location

		if (index == pWord.length() - 1){
			cout << pWord << " is on the Board!" << endl;
			valid++;
		}
		else{
			//If this direction finds the letter, call function again
			// test cout << "Recursion happens after this..." << endl;
			checkPerimeter(vec2D, fLoc, index += 1, valid, pWord);
		}
	}//End directed grid location check
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////
}///////////////////////////////End function check perimeter//////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void isOnBoardFirst(vector< vector<char> > vec2D, string pWord, vector<Coords> &CoordList, Coords tempCoords){
	
	//Find intitial first letter
	//Loop through visible board and check for letter
	for (int i = 1; i < 6; i++){
		for (int j = 1; j < 6; j++){

			if (pWord[0] == vec2D[i][j]){//If first letter matches
				// test cout << "Found first letter: " << pWord[0] << " @ Vector Grid value: " << vec2D[i][j] << endl;
				//Set coordinates to queue here to be checked later when through checking board
				tempCoords.index1 = i;
				tempCoords.index2 = j;
				tempCoords.pWord = pWord;//Storing which word we are on here...
				CoordList.push_back(tempCoords);//Storing index coordinates in a vector of structs...!
			}//End if
			else{
				// test cout << "Did not find letter: " << pWord[0] << " @ Vector Grid value: " << vec2D[i][j] << endl;
			}
		}//End for
	}//End nested for
}//End bool isOnBoard

void displayBoard(vector< vector<char> > vec2D){
	//Display Vector
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
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