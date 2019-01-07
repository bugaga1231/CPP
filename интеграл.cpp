/* нахождение интеграла функции по формуле центральных прямоугольников */

#include "pch.h"
#include <iostream>
using namespace std;
typedef double(*Function)(double);

double f1(double x) {
	return x + 5;
}

double f2(double x) {
	return x * x;
}

double Integral(Function f, double a, double b) {
	double h = 0.0001;
	double n = (b - a) / h;
	double I = 0.0;
	for (int i = 1; i <= n; i++) {
		I += h * f(a + h * (i - 0.5));
	}
	return I;
}

int main()
{
	double I1 = Integral(f1, -3, 7);
	double I2 = Integral(f2, 0, 3);
	cout << I1 << endl << I2;
}
