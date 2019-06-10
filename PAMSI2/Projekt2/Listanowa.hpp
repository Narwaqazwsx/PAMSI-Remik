#ifndef LISTANOWA_HPP
#define LISTANOWA_HPP

#include "pch.h"

class Wierzcholki {

public:

	int waga = 0;

	int skad = 0;

	int dokad = 0;

	Wierzcholki *nastepny;

	Wierzcholki() { nastepny = 0; }
};

class Lista_tab {

public:

	Wierzcholki * pierwsza;

	Wierzcholki **tablica;

	Wierzcholki *p;

	void LosujGraf();

	void LosujGalaz(int wierzch, int dens);
};

void Lista_tab::LosujGalaz(int wierzch, int dens) {

	int kraw = (dens*wierzch*(wierzch - 1) / 200); //wyznaczamy ilosc krawedzi
	tablica = new Wierzcholki* [wierzch]; //tworzymy tablice list

	for (int i = 0; i < wierzch; i++) { //zerujemy listy;

		tablica[i] = NULL;
	}

	for (int i = 0; i < wierzch; i++) {
		Wierzcholki *nowy = new Wierzcholki; //nowy obiekt wierzcholki
		nowy->waga = 1 + rand() % 9;
		nowy->dokad = rand() % wierzch;

		if (pierwsza == 0) { pierwsza = nowy; }
		else {
			Wierzcholki *pom = pierwsza;

			while (pierwsza->nastepny) {

				pom = pom->nastepny;
			}
			pom->nastepny = nowy;
			nowy->nastepny = 0;
		}
	}
}

void Lista_tab::LosujGraf() {

}

#endif

