#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <chrono>
#include "sort.h"
#include "tablice.h"

#define RAND_MAX 0x7fff

using namespace std;

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

int main() {
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

	cout << "NIE W4RTO" << endl;

	srand(time(NULL));

	int tablica[11] = { 12, 5, 6, 7, 10, 4, 1, 3, 9, 8, 2 }; //testowy zestaw danych
	//int tablica[250000];

	int rozmiar = sizeof(tablica) / sizeof(tablica[0]) - 1;

	

	int n;
	double czasy[100];
	double suma = 0;

	for (n = 0; n < 1; n++) {

		cout << "Przed sortowaniem" << endl;
		tab_print(tablica, rozmiar);

		//losowa(tablica, rozmiar);
		//odwrotna(tablica, rozmiar);
		//mieszana(tablica, rozmiar, 0.997);

		performanceCountStart = startTimer();

		//sort_przez_scalanie(tablica, 0, rozmiar);
		//sort_szybkie(tablica, 0, rozmiar);
		sort_intro(tablica, 0, rozmiar);

		performanceCountEnd = endTimer();
		czasy[n] = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
	}

	for (n = 0; n < 100; n++) {
		suma += czasy[n];
	}

	double srednia = suma / 100.0;
	cout << "Po sortowaniu" << endl;
	tab_print(tablica, rozmiar);

	cout << endl << "Time:" << srednia << " s" << endl;
	int x;
	cin >> x;
	return 0;
}