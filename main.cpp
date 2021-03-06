#include <iostream>
#include <ctime>
#include "header.h"
using namespace std;

int main(void) {
	int n = 0;
	int* m = NULL;
	int** A = NULL;
	int w1 = 0;
	int w2 = 0;
	time_t t;

	srand(time(&t));

	do {
		cout << "Podaj liczbe wierszy tablicy nieregularnej A: ";
		cin >> n;
	} while (n < 1);

	m = new int[n];

	for (int i = 0; i < n; i++) {
		do {
			cout << "Podaj liczbe elementow " << i + 1 << " wiersza tablicy nieregularnej A: ";
			cin >> *(m + i);
		} while (*(m + i) < 1);
	}
	cout << endl;

	A = createIrregTab(n, m);
	cout << "Tablica nieregularna A:" << endl;
	printIrregTab(A, n, m);
	cout << endl;

	cout << "Program moze zamienic miejscami 2 wiersze tablicy nieregularnej A." << endl;
	cout << "Podaj numer wiersza w1: ";
	cin >> w1;
	cout << "Podaj numer wiersza w2: ";
	cin >> w2;
	cout << endl;

	if (substRows(A, n, m, w1, w2)) {
		cout << "Tablica nieregularna A po zamianie wiersza w1=" << w1 << " z wierszem w2=" << w2 << ":" << endl;
		printIrregTab(A, n, m);
	}
	else {
		cout << "W tablicy nieregularnej A zamiana wierszy w1=" << w1 << " i w2=" << w2 << " jest niemozliwa." << endl;
	}
	cout << endl;

	deleteIrregTab(A, n, m);

	return 0;
}