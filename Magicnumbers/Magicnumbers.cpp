#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "StandaloneExitChoice.h"

#ifdef _DEBUG
#pragma comment(lib, "standaloneExitChoice.debug.lib")
#else
#pragma comment(lib, "standaloneExitChoice.release.lib")
#endif
using namespace std;
using namespace stdln;
void sandboxMode();
void savedGame();
int main() {

	cout << "Press H to load saved game, where the amount of tries\nit took you to guess is stored in a file, or S for sandbox mode: ";
	while (true) {

		if (_kbhit()) {
			char keyHit = _getch();
			if (keyHit == 'S' || keyHit == 's') {
				cout << keyHit << "\n\n";
				sandboxMode();
				break;
			}
			else if (keyHit == 'H' || keyHit == 'h') {
				cout << keyHit << "\n\n";
				savedGame();
				break;
			}

		}



	}


	restartKey1 = 'A';
	restartKey2 = 'a';
	exitKey1 = 'E';
	exitKey2 = 'e';
	cout << "Press A to go again, or E to exit: ";
	exitchoice();
	return 0;
}


