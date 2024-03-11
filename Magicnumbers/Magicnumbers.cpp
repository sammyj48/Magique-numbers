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
using namespace stdln;

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));
	int magique; // Magic number
	int guessnumber; // The person's guess
	int lowestNumber; // Lowest possible number
	int highestNumber; // Highest possible number


	cout << "This is a fun guessing game where you must guess the magic number!!!!" << endl << endl;
	cout << "Please choose the range you want your numbers to be between:\n\n";
	cout << "Enter the lowest possible number: ";
	cin >> lowestNumber;
	cout << "\nEnter the highest possible number: ";
	cin >> highestNumber;
	
	if (lowestNumber > highestNumber) { 
		MessageBoxW(NULL, L"Exception thrown!", L"Error!", MB_OK); 
		cout << "Press any key 2 exit";
		for (;;) {
			if (_kbhit()) return 0;
		}
	}
	
		
	
	do {
		magique = rand(); // this function gets a random number
	} while (magique < lowestNumber || magique > highestNumber);



	cout << "\nPlease enter your first guess here: ";
	cin >> guessnumber;
	while (guessnumber != magique) {
		cout << "\nOopsy daisy!!";
		if (guessnumber > highestNumber || guessnumber < lowestNumber) cout << "\nYour guess is outside of the range you specified, guess again!!: ";
		else if (guessnumber > magique) cout << "\nYour guess is too high, guess again!!: ";
		else if (guessnumber < magique) cout << "\nYour guess is too low, guess again!!: ";
		cin >> guessnumber;
	}
	MessageBoxW(NULL, L"Well done superhero, you guessed right!!", L"Yay!", MB_OK);
	cout << "\n\nWell done superhero, you guessed right!!\n\n\n";
	restartKey1 = 'A';
	restartKey2 = 'a';
	exitKey1 = 'E';
	exitKey2 = 'e';
	cout << "Press A to go again, or E to exit: ";
	exitchoice();
	return 0;
}
	

	
