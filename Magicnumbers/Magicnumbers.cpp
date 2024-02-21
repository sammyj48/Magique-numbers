#include <iostream>
#include <ctime>

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
generate:
	magique = rand(); // this function gets a random number
	if (magique > highestNumber || magique < lowestNumber) goto generate;
	cout << "\nPlease enter your first guess here: ";
	guess:
	cin >> guessnumber;

	if (guessnumber == magique) { 
		cout << "\nWell done superhero, you guessed right!!!";
		return 1;
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