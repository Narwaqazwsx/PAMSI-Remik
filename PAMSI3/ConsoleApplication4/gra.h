#include "pch.h"
using namespace std;

class Gra {
public:
	char** plansza;
	int n = 0;

public:
	//Konstruktor
	Gra(int wym) {
		n = wym;
		plansza = new char*[n];
		for (int i = 0; i < n; i++) {
			plansza[i] = new char[n];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				plansza[i][j] = '-';
	}

	//Destruktor
	~Gra() {
		delete[] plansza;
	}

	//Sprawdza, czy gracz z podanym znakiem wygrywa
	bool wygrana(char xo) {
		//warunek 1 - wiersz
		for (int i = 0; i < n; i++) {
			int how_many_xo = 0;
			for (int j = 0; j < n; j++) {
				if (plansza[i][j] == xo) {
					how_many_xo++;
				}
			}
			if (how_many_xo == n) {
				return true;
			}
		}

		//warunek 2 - kolumna
		for (int j = 0; j < n; j++) {
			int how_many_xo = 0;
			for (int i = 0; i < n; i++) {
				if (plansza[i][j] == xo) {
					how_many_xo++;
				}
			}
			if (how_many_xo == n) {
				return true;
			}
		}

		//warunek 3 - przekatna z lewego gornego do prawego dolnego
		{
			int how_many_xo = 0;
			for (int i = 0, j = 0; i < n && j < n; i++, j++) {
				if (plansza[i][j] == xo) {
					how_many_xo++;
				}
			}
			if (how_many_xo == n) {
				return true;
			}
		}

		//warunek 4 - przekatna z prawego gornego do lewego dolnego
		{
			int how_many_xo = 0;
			for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
				if (plansza[i][j] == xo) {
					how_many_xo++;
				}
			}
			if (how_many_xo == n) {
				return true;
			}
		}

		return false;
	}

	//Sprawdza, czy padl remis
	bool remis(void) {
		int how_many_signs = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (plansza[i][j] == 'x' || plansza[i][j] == 'o') {
					how_many_signs++;
				}
			}
		}
		if (how_many_signs == n * n && !(wygrana('x') && !(wygrana('o')))) {
			return true;
		}
		else return false;
	}

	//Ponizsze funkcje przeliczaja podawana pozycje jak zwykle, np dla 3x3:
	// 1 2 3
	// 4 5 6
	// 7 8 9
	//Na wspóorzedne elementu w macierzy
	int przeliczX(int pozycja) {
		pozycja -= 1;
		return pozycja % n;
	}

	int przeliczY(int pozycja) {
		pozycja -= 1;
		return pozycja / n;
	}

	//Zwraca znak znajdujacy sie pod podana pozycja
	char jakiZnak(int pozycja) {
		return plansza[przeliczY(pozycja)][przeliczX(pozycja)];
	}

	//Sprawdza, czy dana pozycja jest zajeta lub czy istnieje
	bool czyZajeta(int pozycja) {
		if (pozycja <= 0 || pozycja > n*n) return true;
		else if (jakiZnak(pozycja) == 'x' || jakiZnak(pozycja) == 'o')
			return true;
		else return false;
	}

	char notGracz(char znak) {
		if (znak == 'o') return 'x';
		else return 'o';
	}

	int minmax(char gracz) {
		if (wygrana(gracz)) return (gracz == 'o') ? 10 : -10;
		if (remis()) return 0;
		gracz = (gracz == 'o') ? 'x' : 'o';
		int min = (gracz == 'o') ? -10 : 10;
		int m;

		for (int i = 1; i <= n * n; i++) {
			if (!czyZajeta(i)) {
				plansza[przeliczY(i)][przeliczX(i)] = gracz;
				m = minmax(gracz);
				plansza[przeliczY(i)][przeliczX(i)] = '-';
				if (gracz == 'o' && m > min) {
					min = m;
				}
				else if (gracz == 'x' && m < min) {
					min = m;
				}
			}
		}
		return min;
	}

	int alphabeta(int a, int b, char gracz) {
		if (wygrana(gracz)) return (gracz == 'o') ? 10 : -10;
		if (remis()) return 0;
		if (gracz == 'o') {
			int v = -10;
			for (int i = 1; i <= n * n; i++) {
				if (!czyZajeta(i)) {
					plansza[przeliczY(i)][przeliczX(i)] = 'o';
					v = max(v, alphabeta(a, b, 'x'));
					plansza[przeliczY(i)][przeliczX(i)] = '-';
					a = max(a, v);
					if (b <= a) {
						break;
					}
				}
			}
			return v;
		}
		else {
			int v = 10;
			for (int i = 1; i <= n * n; i++) {
				if (!czyZajeta(i)) {
					plansza[przeliczY(i)][przeliczX(i)] = 'x';
					v = min(v, alphabeta(a, b, 'o'));
					plansza[przeliczY(i)][przeliczX(i)] = '-';
					b = min(b, v);
					if (b <= a) {
						break;
					}
				}
			}
			return v;
		}
	}

	int ruchK() {
		int ruch, min = -10, m;
		for (int i = 1; i <= n * n; i++) {
			if (!czyZajeta(i)) {
				plansza[przeliczY(i)][przeliczX(i)] = 'o';
				m = minmax('o');
				//m = alphabeta(-10, 10, 'o');
				plansza[przeliczY(i)][przeliczX(i)] = '-';
				if (m > min) {
					min = m;
					ruch = i;
				}
			}
		}
		return ruch;
	}

	void ruchKomputera(int ktory) {
		if (n > 3 && ktory < n - 2) {
			bool found = false;
			while (!found) {
				int rr = (rand() % ((n*n) - 1)) + 1;
				if (!czyZajeta(rr)) {
					plansza[przeliczY(rr)][przeliczX(rr)] = 'o';
					found = true;
				}
			}
		}
		else {
			int r = ruchK();
			plansza[przeliczY(r)][przeliczX(r)] = 'o';
		}
	}


	//Obsluguje ruch gracza
	void ruchGracza(char znak) {
		int wybor = 0;
		while (czyZajeta(wybor)) {
			cout << "Ruch " << znak << " : ";
			cin >> wybor;
			if (czyZajeta(wybor))
				cout << "Niewlasciwa pozycja!\n";
		}
		plansza[przeliczY(wybor)][przeliczX(wybor)] = znak;
	}

	void print(void) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << plansza[i][j] << " ";
			}
			cout << "\n";
		}
	}

	
};
 ostream & operator << (ostream & output, const Gra & to) {
	for (int i = 0; i < to.n; i++) {
		for (int j = 0; j < to.n; j++) {
			output << to.plansza[i][j] << " ";
		}
		output << "\n";
	}
	return output;
}