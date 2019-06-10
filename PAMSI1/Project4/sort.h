#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

/* Funkcja pomocnicza scalaj¹ca podtablice */
void scal(int tab[], int l_end, int mid, int r_end) {
	int sizeL = mid - l_end + 1;
	int sizeR = r_end - mid;

	int *left_tab = new int[sizeL];
	int *right_tab = new int[sizeR];

	int i, j;

	for (i = 0; i < sizeL; i++) {
		left_tab[i] = tab[l_end + i];
	}

	for (j = 0; j < sizeR; j++) {
		right_tab[j] = tab[mid + 1 + j];
	}

	i = 0;
	j = 0;

	int ind = l_end;

	while (i < sizeL && j < sizeR) {
		if (left_tab[i] <= right_tab[j]) {
			tab[ind] = left_tab[i];
			i++;
		}
		else {
			tab[ind] = right_tab[j];
			j++;
		}
		ind++;
	}

	while (i < sizeL) {
		tab[ind] = left_tab[i];
		i++;
		ind++;
	}

	while (j < sizeR) {
		tab[ind] = right_tab[j];
		j++;
		ind++;
	}
}

/* Sortowanie przez scalanie */
void sort_przez_scalanie(int tab[], int l_end, int r_end) {
	if (l_end < r_end) {
		int mid = (l_end + r_end) / 2;

		sort_przez_scalanie(tab, l_end, mid);
		sort_przez_scalanie(tab, mid + 1, r_end);

		scal(tab, l_end, mid, r_end);
	}
}

/* Sortowanie szybkie */
void sort_szybkie(int tab[], int l_end, int r_end) {
	int i, j;
	int piwot;

	i = (l_end + r_end) / 2;
	piwot = tab[i];
	tab[i] = tab[r_end];

	i = l_end;
	j = l_end;
	while (i < r_end) {
		if (tab[i] < piwot) {
			int tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			j++;
		}
		i++;
	}
	tab[r_end] = tab[j];
	tab[j] = piwot;
	if (l_end < j - 1) {
		sort_szybkie(tab, l_end, j - 1);
	}
	if (j + 1 < r_end) {
		sort_szybkie(tab, j + 1, r_end);
	}
}


/* Sortowanie przez wstawianie*/
void wstawianie(int tab[], int rozm) {
	int i, j;
	int key;

	for (i = 1; i < rozm; i++) {
		key = tab[i];
		j = i - 1;
		while (tab[j] > key && j >= 0) {
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = key;
	}
}


/* Sortowanie introspektywne*/
void intro(int tab[], int l_end, int r_end, int max_wyw) {
	int i, j;
	int piwot;

	if (max_wyw == 0) {
		wstawianie(tab, r_end - l_end);
	}

	if (max_wyw > 0) {
		max_wyw = max_wyw - 1;

		i = (l_end + r_end) / 2;
		piwot = tab[i];
		tab[i] = tab[r_end];

		i = l_end;
		j = l_end;
		while (i < r_end) {
			if (tab[i] < piwot) {
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j++;
			}
			i++;
		}
		tab[r_end] = tab[j];
		tab[j] = piwot;
		if (l_end < j - 1) {
			intro(tab, l_end, j - 1, max_wyw);
		}
		if (j + 1 < r_end) {
			intro(tab, j + 1, r_end, max_wyw);
		}
	}

}
void sort_intro(int tab[], int l_end, int r_end) {
	int max_wyw = int(2 * log(r_end - l_end + 1));
	intro(tab, l_end, r_end, max_wyw);
}

#endif // SORT_H_INCLUDED