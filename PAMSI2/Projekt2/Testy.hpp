#ifndef TESTY_HPP	
#define TESTY_HPP

#include "pch.h"
#include "Lista.hpp"
#include "Macierz.hpp"

class Testy {
public:
	void Testuj_Macierz(int wierzch, int dens);

	void Testuj_Liste(int wierzch, int dens);

	void Komunikacja();
};

void Testy::Testuj_Macierz(int wierzch, int dens) {

	double tab_czas[100];

	for (int i = 0; i < 100; i++) {
		
		Macierz M(wierzch, dens);
		tab_czas[i] = Czas_M(M);
		//std::cout << tab_czas[i] << " ";
	}
	std::sort(tab_czas, tab_czas + 100);
	std::cout << "Czasy Macierzy" << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Min Czas: " << tab_czas[0] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Max Czas: " << tab_czas[99] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Mediana: " << tab_czas[49] << std::endl;
}

void Testy::Testuj_Liste(int wierzch, int dens) {
	double tab_czas[100];

	for (int i = 0; i < 100; i++) {

		Graf_Lista L(wierzch,dens);
		tab_czas[i] = Czas_L(L);
	}
	std::sort(tab_czas, tab_czas + 100);
	std::cout << "Czasy Listy" << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Min Czas: " << tab_czas[0] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Max Czas: " << tab_czas[99] << std::endl;
	std::cout << "W: " << wierzch << " Dens: " << dens << " Mediana: " << tab_czas[49] << std::endl;
}

void Testy::Komunikacja() {
	std::cout << "Sprawdzenie dzialania algorytmu Bellmana Forda oraz tworzenia grafow na macierzy oraz liscie sasiedztwa" << std::endl;
	std::cout << "a - Przykladowe sprawdzenie dzialania programu" << std::endl;
	std::cout << "b - Sprawdzenie czasu dla grafu na macierzy i liscie 10 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "c - Sprawdzenie czasu dla grafu na macierzy i liscie 50 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "d - Sprawdzenie czasu dla grafu na macierzy i liscie 100 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "e - Sprawdzenie czasu dla grafu na macierzy i liscie 500 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "f - Sprawdzenie czasu dla grafu na macierzy i liscie 1000 elementow dla gestosci 25,50,75 i 100%" << std::endl;
	std::cout << "g - czyszczenie konsoli" << std::endl;
	std::cout << "q - wyjscie" << std::endl;
	std::cout << "Twoj wybor: ";
}

#endif