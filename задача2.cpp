#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	float a;
	float eps;
	cout << "ENTER A: ";
	cin >> a;
	cout << "ENTER EPSILON: ";
	cin >> eps;
	float x, x_next;
	x = a;
	x_next = (2 * x + a / (x*x)) / 3;
	for (; abs(x - x_next) > eps; ) {
		x = x_next;
		x_next = (2 * x + a / (x*x)) / 3;
	}
	cout << x_next;
}
