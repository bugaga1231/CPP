#include "pch.h"
#include <iostream>
using namespace std;

int kal(int a, int b) {
	int answer;
	if (b == a) return 1;
	if (b > 10) return kal(a, b - 1) + kal(a, b - 10);
	else return kal(a, b - 1);
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	cout << kal(a, b);
	return 0;
}
