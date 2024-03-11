#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

bool fileExists(const char*);
ifstream* saveFilePTR = nullptr;
void savedGame() {
	bool isAllocated = false;
	int bestRun;
	const char* saveFileName = "magique_numbers_save.txt";
	if (fileExists(saveFileName)) {
		saveFilePTR = new ifstream(saveFileName);
		isAllocated = true;
	}
	
	
	srand(static_cast<unsigned int>(time(nullptr)));
	int magique; // magic number
	int guessnumber; // the person's guess
	const int lowestNumber = 1; // Lowest possible number
	const int highestNumber = 100; // Highest possible number
	int amountOfTries = 1; // Amount of tries it took for the user to guess the magic number
	cout << "This is a fun guessing game where you must guess the magic number between 1 and 100!!!!" << endl << endl;
	do {
		magique = rand(); // this function gets a random number
	} while (magique < lowestNumber || magique > highestNumber);
	cout << "\nPlease enter your first guess here: ";
	cin >> guessnumber;
	while (guessnumber != magique) {
		cout << "\nOopsy daisy!!";
		if (guessnumber > highestNumber || guessnumber < lowestNumber) cout << "\nYour guess is outside of the range, guess again!!: ";
		else if (guessnumber > magique) cout << "\nYour guess is too high, guess again!!: ";
		else if (guessnumber < magique) cout << "\nYour guess is too low, guess again!!: ";
		cin >> guessnumber;
		amountOfTries++;
	}
	MessageBoxW(NULL, L"Well done superhero, you guessed right!!", L"Yay!", MB_OK);
	cout << "\n\nWell done superhero, you guessed right!!\n\n";
	cout << "It only took " << amountOfTries << " tries!\n\n";
	if (isAllocated) {
		*saveFilePTR >> bestRun;
		if (bestRun > amountOfTries) {
			cout << "You beat your best score!\n\n\n";
			saveFilePTR->close();
			ofstream writeToFile(saveFileName);
			writeToFile << amountOfTries;
			writeToFile.close();
		}
		else {
			cout << "Your best score was " << bestRun << "\n\n\n";
		}
		
	}
	else {
		ofstream createFile(saveFileName);
		createFile << amountOfTries;
		createFile.close();
	}
	delete saveFilePTR; // Do not use saveFilePTR after this line of code! */ 
	saveFilePTR == nullptr; // Or this line of code!
	return;
	
}
bool fileExists(const char* fileName) { // This function checks if a file exists
	ifstream check_if_good(fileName);
	return check_if_good.good();
}
