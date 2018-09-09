#include <iostream>
using namespace std;

int** createIrregTab(int n, int* m) {
	int** A = NULL;
	A = new int*[n];

	for (int i = 0; i < n; i++) {
		*(A + i) = new int[*(m + i)];

		for (int j = 0; j < *(m + i); j++) {
			*(*(A + i) + j) = -9 + rand() % 19;
		}
	}

	return A;
}


void printIrregTab(int** A, int n, int* m) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < *(m + i); j++) {
			cout.width(4);
			cout << *(*(A + i) + j) << " ";
		}
		cout << endl;
	}
}


void deleteIrregTab(int** A, int n, int* m) {
	for (int i = 0; i < n; i++) {
		delete[] * (A + i);
	}

	delete[] A;
	A = NULL;
	delete[] m;
	m = NULL;
}


int substRows(int** A, int n, int* m, int w1, int w2) {
	if (w1 < 1 || w1 > n || w2 < 1 || w2 > n) {
		return 0;
	}
	else {
		if (w1 != w2) {
			int* tmp = NULL;
			int t = 0;

			tmp = *(A + w1 - 1);
			t = *(m + w1 - 1);
			*(A + w1 - 1) = *(A + w2 - 1);
			*(m + w1 - 1) = *(m + w2 - 1);
			*(A + w2 - 1) = tmp;
			*(m + w2 - 1) = t;

			tmp = NULL;
			t = 0;
		}

		return 1;
	}
}
