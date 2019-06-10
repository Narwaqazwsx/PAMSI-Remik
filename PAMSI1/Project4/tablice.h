#ifndef TABLICE_H_INCLUDED
#define TABLICE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

void losowa(int tab[], int rozm) {
	int i;
	for (i = 0; i <= rozm; i++) {
		tab[i] = rand()*(RAND_MAX + 1) + rand();
	}
}

void mieszana(int tab[], int rozm, double fctr) {
	int i;
	int imax = fctr * rozm;
	for (i = 0; i <= imax; i++) {
		tab[i] = i;
	}
	for (i = imax + 1; i <= rozm; i++) {
		tab[i] = rand() *(RAND_MAX + 1) + rand();
	}
}

void odwrotna(int tab[], int rozm) {
	int i;
	for (i = 0; i <= rozm; i++) {
		tab[i] = rozm - i;
	}
}

/* Wyswietlanie tablicy */
void tab_print(int tab[], int rozm) {
	int i;
	for (i = 0; i <= rozm; i++) {
		cout << tab[i] << "\t";
	}
	cout << endl;
}

#endif // TABLICE_H_INCLUDED