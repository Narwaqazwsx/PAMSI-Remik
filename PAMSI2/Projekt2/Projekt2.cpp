#include "pch.h"
#include "Macierz.hpp"
#include "Lista.hpp"
#include "Testy.hpp"

int main()
{
	srand(time(NULL));
	Testy Test;
	
	char znak;
	do
	{
		Test.Komunikacja();
		std::cin >> znak;

		switch (znak) {
		case 'a': {
			Macierz M(5, 75);
			M.Wypisz_Macierz(5);
			std::cout << std::endl << std::endl;
			Bellman_Ford_Pierwszy(M);
			M.Usun_Macierz(5);

			Graf_Lista L(5, 75);
			L.Wypisz_Liste(5);
			std::cout << std::endl;
			Bellman_Ford_Drugi(L);
			L.Usun_Liste(5);
			break;
		}
		case 'b': {
			Test.Testuj_Macierz(10, 25);
			Test.Testuj_Macierz(10, 50);
			Test.Testuj_Macierz(10, 75);
			Test.Testuj_Macierz(10, 100);

			Test.Testuj_Liste(10, 25);
			Test.Testuj_Liste(10, 50);
			Test.Testuj_Liste(10, 75);
			Test.Testuj_Liste(10, 100);
			break;
		}
		case'c': {
			Test.Testuj_Macierz(50, 25);
			Test.Testuj_Macierz(50, 50);
			Test.Testuj_Macierz(50, 75);
			Test.Testuj_Macierz(50, 100);

			Test.Testuj_Liste(50, 25);
			Test.Testuj_Liste(50, 50);
			Test.Testuj_Liste(50, 75);
			Test.Testuj_Liste(50, 100);
			break;
		}
		case 'd': {
			Test.Testuj_Macierz(100, 25);
			Test.Testuj_Macierz(100, 50);
			Test.Testuj_Macierz(100, 75);
			Test.Testuj_Macierz(100, 100);

			Test.Testuj_Liste(100, 25);
			Test.Testuj_Liste(100, 50);
			Test.Testuj_Liste(100, 75);
			Test.Testuj_Liste(100, 100);
			break;
		}
		case 'e': {
			Test.Testuj_Macierz(500, 25);
			Test.Testuj_Macierz(500, 50);
			Test.Testuj_Macierz(500, 75);
			Test.Testuj_Macierz(500, 100);

			Test.Testuj_Liste(500, 25);
			Test.Testuj_Liste(500, 50);
			Test.Testuj_Liste(500, 75);
			Test.Testuj_Liste(500, 100);
			break;
		}
		case 'f': {
			Test.Testuj_Macierz(1000, 25);
			Test.Testuj_Macierz(1000, 50);
			Test.Testuj_Macierz(1000, 75);
			Test.Testuj_Macierz(1000, 100);

			Test.Testuj_Liste(1000, 25);
			Test.Testuj_Liste(1000, 50);
			Test.Testuj_Liste(1000, 75);
			Test.Testuj_Liste(1000, 100);
			break;
		}
		case'g': {
			system("cls");
		}
		}

	} while (znak != 'q');
}