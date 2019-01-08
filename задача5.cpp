
#include "pch.h"
#include <iostream>
#include "stdlib.h"
#include <time.h>
using namespace std;

const int N = 100;
int main() {
	int a[N][N];
	int n;
	int M;
	int count = 0;
	cin >> n >> M;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 50 - 1;
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	int minM = abs(M - a[0][0]);

	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < n; j++) {
			if (minM > abs(M - a[i][j])) minM = abs(M - a[i][j]);
		}

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i<j && i>n - 1 - j && abs(M - a[i][j]) < minM) count++;
		}

	cout << minM;
	if (count) cout << count;
	else cout << "ERROR";
	return 0;
}
