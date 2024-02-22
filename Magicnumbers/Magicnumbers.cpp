#include <iostream>
#include <ctime>
#include <Windows.h>
#include "StandaloneExitChoice.h"
#include <conio.h>
#include <string>
#ifdef _DEBUG
#pragma comment(lib, "standaloneExitChoice.debug.lib")
#else
#pragma comment(lib, "standaloneExitChoice.release.lib")
#endif
using namespace std;

int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));
	int magique; // magic number
	int guessnumber; // the person's guess
	int lowestNumber; // Lowest possible number
	int highestNumber; // Highest possible number

	
	cout << "This is a fun guessing game where you must guess the magic number!!!!" << endl << endl;
	cout << "Please choose the range you want your numbers to be between:\n\n";
	cout << "Enter the lowest possible number: ";
	cin >> lowestNumber;
	cout << "\nEnter the highest possible number: ";
	cin >> highestNumber;
	try { if (lowestNumber > highestNumber) throw (1); }
	catch (int errorCode) {
		MessageBox(NULL, L"    Exeption thrown!\n ", L"Error!", MB_OK);
		cout << "\n\n\nPress any key to exit...";
		while (true) if (_kbhit()) return 0;

	}
generate:
	magique = rand(); // this function gets a random number
	if (magique > highestNumber || magique < lowestNumber) goto generate;
	cout << "\nPlease enter your first guess here: ";
	guess:
	cin >> guessnumber;

	if (guessnumber == magique) { 
		cout << "\nWell done superhero, you guessed right!!!\n\n";
		MessageBox(NULL, L"Well done!", L"You won! :)", MB_OK);
		stdln::restartKey1 = 'a';
		stdln::restartKey2 = 'A';
		stdln::exitKey1 = 'e';
		stdln::exitKey2 = 'E';
		cout << "Press E to exit the game or A to go again!";
		stdln::exitchoice(2);
}

	else {
		cout << "\nOopsy daisy!!";
		if (guessnumber > highestNumber || guessnumber < lowestNumber) cout << "\nYour guess is outside of the range you specified, guess again!!: ";
		else if (guessnumber > magique) cout << "\nYour guess is too high, guess again!!: ";
		else if (guessnumber < magique) cout << "\nYour guess is too low, guess again!!: ";
		goto guess;
	}
	
	return 0;

}