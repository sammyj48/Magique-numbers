#include <ctime>
#include <iostream>
#include <random>

using namespace std;

namespace rng {
    std::random_device device;
    std::mt19937 rng(device());
    int random(int min, int max) {
        auto dist = std::uniform_int_distribution(min, max);
        return dist(rng);
    }
}

int main() {
    int magique;       // Magic number
    int guessnumber;   // The person's guess
    int lowestNumber;  // Lowest possible number
    int highestNumber; // Highest possible number

    cout << "This is a fun guessing game where you must guess the magic number!!!!" << endl << endl;
	cout << "Please choose the range you want your numbers to be between:\n\n";
	cout << "Enter the lowest possible number: ";
	cin >> lowestNumber;
	cout << "\nEnter the highest possible number: ";
	cin >> highestNumber;

    if (lowestNumber > highestNumber) {
        cout << "Swapping those, they're the wrong way round.";
        swap(lowestNumber, highestNumber);
    }

    magique = rng::random(lowestNumber, highestNumber);

    cout << "\nPlease enter your first guess here: ";
    cin >> guessnumber;
	while (guessnumber != magique) {
		cout << "\nOopsy daisy!!";
		if (guessnumber > highestNumber || guessnumber < lowestNumber) cout << "\nYour guess is outside of the range you specified, guess again!!: ";
		else if (guessnumber > magique) cout << "\nYour guess is too high, guess again!!: ";
		else if (guessnumber < magique) cout << "\nYour guess is too low, guess again!!: ";
		cin >> guessnumber;
    }
    cout << "\n\nWell done superhero, you guessed right!!\n\n\n";
    return 0;
}
