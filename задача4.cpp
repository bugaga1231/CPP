#include "pch.h"
#include <iostream>
#include "stdlib.h"
#include <time.h>
using namespace std;

void createMatrix(int n, int m, int** a) {
	for (int i = 0; i < n; i++) {
 		a[i] = new int[m];
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 50 - 1;
		}
}


void outputMatrix(int n, int m, int** a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

void createMassive(int n, int m, int **a, int *b, bool* resheto) {
	int max_;
	for (int i = 0; i < n; i++) {
		max_ = a[i][2];
		for (int j = 3; j < m; j++) {
			if (max_ < a[i][j] && &resheto[j]) max_ = a[i][j];
		}
		b[i] = max_;
	}
}

void outputMassive(int n, int* b) {
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
}

void createResheto(int m, bool *a) {
	
	a[0] = false;
	a[1] = false;
	for (int i = 2; i < m; i++) {
		a[i] = true;
	}
	for (int i = 2; i < m; i++) {
		if (a[i])
			for (int j = i * i; j < m; j += i)
				a[j] = false;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	int **a = new int *[n];
	int *b = new int[n];
	bool *resheto = new bool[m];
	createMatrix(n, m, a);
	createResheto(m, resheto);
	outputMatrix(n, m, a);
	createMassive(n, m, a, b, resheto);
	outputMassive(n, b); 

	return 0;
}
