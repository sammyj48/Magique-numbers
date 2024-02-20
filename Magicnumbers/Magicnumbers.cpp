#include <iostream>
#include <ctime>

using namespace std;

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));

	int magique; // magic number
	int guessnumber; // the person's guess
generate:
	magique = rand(); // this function get a random number
	if (magique > 30) goto generate;
	cout << "This is a fun guessing game where you must guess the magic number between 1 and 30!!!!" << endl;
	cout << "\nPlease enter your first guess here: ";
	guess:
	cin >> guessnumber;

	if (guessnumber == magique) { 
		cout << "\nWell done superhero, you guessed right!!!";
		return 1;
}

	else {
		cout << "\nOopsy daisy!!";
		if (guessnumber > magique) cout << "Your guess is too high, guess again!!: ";
		else cout << "\nYour guess is too low, guess again!!: ";
		goto guess;
	}
	return 0;

}