#include "pch.h"
#include "gra.h"

using namespace std;

int main() {
	int n = 0;
	char multi;
	while (n <= 2) {
		cout << "Wielkosc planszy: ";
		cin >> n;
		if (n <= 2) {
			cout << "Za maly wymiar planszy!\n";
		}
	}

	cout << "Multiplayer? (y/n) ";
	cin >> multi;

	if (multi == 'y' || multi == 'Y') {
		Gra gra(n);
		cout << gra;

		while (!gra.wygrana('x') || !gra.wygrana('o') || !gra.remis()) {
			gra.ruchGracza('x');
			cout << gra;
			if (gra.wygrana('x')) {
				cout << "X wygrywa!\n";
				break;
			}
			if (gra.remis()) {
				cout << "Remis!\n";
				break;
			}
			gra.ruchGracza('o');
			cout << gra;
			if (gra.wygrana('o')) {
				cout << "O wygrywa!\n";
				break;
			}
			if (gra.remis()) {
				cout << "Remis!\n";
				break;
			}
		}
		cout << "Dzieki za gre!\n";
	}
	else {
		Gra gra(n);
		cout << gra;
		int ruch = 0;
		while (!gra.wygrana('x') || !gra.wygrana('o') || !gra.remis()) {
			gra.ruchGracza('x');
			cout << gra;
			if (gra.wygrana('x')) {
				cout << "X wygrywa!\n";
				break;
			}
			if (gra.remis()) {
				cout << "Remis!\n";
				break;
			}
			cout << "\n";
			gra.ruchKomputera(ruch);
			ruch++;
			cout << gra;
			if (gra.wygrana('o')) {
				cout << "O wygrywa!\n";
				break;
			}
			if (gra.remis()) {
				cout << "Remis!\n";
				break;
			}
		}
		cout << "Dzieki za gre!\n";

	}

return 0;
}
